//
// Created by マリオネット on 2021/6/29.
//

#include "TreeStoreStructure.h"

#ifdef PARENT_MODE

void InitPTree(PTree *pTree, ElemType rootData) {
	for (int i = 0; i < MAX_TREE_SIZE; i++) {
		pTree->nodes[i].data = '\0';
		pTree->nodes[i].parent = -1;
	}

	pTree->nodeNum = 0;
	PTNode *rootNode = (PTNode *) malloc(sizeof(PTNode));
	rootNode->data = rootData;
	rootNode->parent = -1;
	pTree->nodes[0] = *rootNode;
	pTree->nodeNum++;
}

void AddNode(PTree *pTree, ElemType newData, int parent) {
	if (pTree->nodeNum >= MAX_TREE_SIZE) return;

	PTNode *newNode = (PTNode *) malloc(sizeof(PTNode));
	newNode->data = newData;
	newNode->parent = parent;
	pTree->nodes[pTree->nodeNum] = *newNode;        // nodeNum就是新结点的下标
	pTree->nodeNum++;
}

void DeleteNode(PTree *pTree, int index) {
	if (index >= pTree->nodeNum) return;

	for (int i = 1; i < pTree->nodeNum; i++) {    // 递归删除所有以该结点为双亲的结点
		if (pTree->nodes[i].parent == index)
			DeleteNode(pTree, i);
	}

	pTree->nodeNum--;   // 先--，nodeNum指向存在的最后一个元素
	/* 将最后表中最后一位的数据挪到被删除结点的位置 */
	pTree->nodes[index].data = pTree->nodes[pTree->nodeNum].data;
	pTree->nodes[index].parent = pTree->nodes[pTree->nodeNum].parent;

	/* 最后一位结点清零 */
	pTree->nodes[pTree->nodeNum].data = '\0';
	pTree->nodes[pTree->nodeNum].parent = -1;
}

#endif
