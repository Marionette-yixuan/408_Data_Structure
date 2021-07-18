//
// Created by マリオネット on 2021/7/18.
//

#include "TreeConversion.h"

void InitTree_T(TrTree *trTree, ElemType rootData) {
	TrTNode *rootNode = (TrTNode *) malloc(sizeof(TrTNode));
	rootNode->data = rootData;
	rootNode->lChild = NULL;
	rootNode->mChild = NULL;
	rootNode->rChild = NULL;
	*trTree = rootNode;
}

TrTNode *AddNode_T(TrTNode *parentNode, ElemType newData, int pos) {
	TrTNode *newNode = (TrTNode *) malloc(sizeof(TrTNode));
	newNode->data = newData;
	newNode->lChild = NULL;
	newNode->mChild = NULL;
	newNode->rChild = NULL;

	if (pos == LEFT)
		parentNode->lChild = newNode;
	else if (pos == MID)
		parentNode->mChild = newNode;
	else if (pos == RIGHT)
		parentNode->rChild = newNode;
	else return NULL;

	return newNode;
}

void InitTree_B(BiTree *biTree, ElemType rootData) {
	BiTNode *rootNode = (BiTNode *) malloc(sizeof(TrTNode));
	rootNode->data = rootData;
	rootNode->lChild = NULL;
	rootNode->rChild = NULL;
	*biTree = rootNode;
}

BiTNode *AddNode_B(BiTNode *parentNode, ElemType newData, int pos) {
	BiTNode *newNode = (BiTNode *) malloc(sizeof(BiTNode));
	newNode->lChild = NULL;
	newNode->rChild = NULL;

	if (pos == LEFT)
		parentNode->lChild = newNode;
	else if (pos == RIGHT)
		parentNode->rChild = newNode;
	else return NULL;

	return newNode;
}

BiTree TrToBi(TrTree trTree) {
	/* 这部分代码为了分清楚每一步，冗余非常多，可以重构得更加简洁 */
	/* 1 创建根结点，存入根数据 */
	BiTree biTree;   // 转换后二叉树的根结点
	InitTree_B(&biTree, trTree->data);

	/* 2 转换第一棵子树，将转换后的子树连在根结点的左侧 */
	int firstSubNum = 0;        // 判定哪棵子树是第一棵
	if (trTree->lChild) firstSubNum = LEFT;
	else if (trTree->mChild) firstSubNum = MID;
	else if (trTree->rChild) firstSubNum = RIGHT;
	else return biTree;           // 若没有子树，则直接返回

	switch (firstSubNum) {
		case LEFT:
			biTree->lChild = TrToBi(trTree->lChild);    // 第一棵子树是LEFT，将其转换连在根左侧
			break;
		case MID:
			biTree->lChild = TrToBi(trTree->mChild);    // 第一棵子树是MID
			break;
		case RIGHT:
			biTree->lChild = TrToBi(trTree->rChild);    // 第一棵子树是RIGHT
			break;
		default:
			return biTree;                              // 双保险
	}

	/* 3 转换剩余子树，将剩余子树连在上一个根的右侧 */
	BiTNode *lastRoot = biTree->lChild;
	if (firstSubNum == LEFT) {
		if (trTree->mChild) {
			lastRoot->rChild = TrToBi(trTree->mChild);
			lastRoot = lastRoot->rChild;
		}
		if (trTree->rChild)
			lastRoot->rChild = TrToBi(trTree->rChild);      // RIGHT已经是最后一棵子树，不用再更改lastRoot的值了
	} else if (firstSubNum == MID) {
		if (trTree->rChild)
			lastRoot->rChild = TrToBi(trTree->rChild);
	} else;

	return biTree;      // 将转换后的二叉树返回，用于连接到更大的转换树上
}

void Traverse_B(BiTree biTree) {
	if (biTree) {
		Traverse_B(biTree->lChild);
		printf("%c", biTree->data);
		Traverse_B(biTree->rChild);
	}
}

void InitForest(TrForest trForest) {
	for (int i = 0; i < MAX_TREE_NUM; i++)
		trForest[i] = NULL;
}

BiTree FstToBi(TrForest trForest) {
	/* 将第一棵树的转换结果存在根的位置 */
	BiTree biTree = TrToBi(trForest[0]);
	BiTree lastRoot = biTree;

	for (int i = 1; i < MAX_TREE_NUM; i++) {
		if (!trForest[i]) break;
		lastRoot->rChild = TrToBi(trForest[i]);     // 将下一棵树转换的结果连在上一个根的右子树位置
		lastRoot = lastRoot->rChild;
	}

	return biTree;
}