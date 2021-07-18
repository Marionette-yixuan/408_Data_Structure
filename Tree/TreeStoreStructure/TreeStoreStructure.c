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

	pTree->nodes[0].data = rootData;
	pTree->nodes[0].parent = -1;
	pTree->nodeNum++;
}

void AddNode(PTree *pTree, ElemType newData, int parent) {
	if (pTree->nodeNum >= MAX_TREE_SIZE) return;

	pTree->nodes[pTree->nodeNum].data = newData;    // nodeNum就是新结点所在的下标
	pTree->nodes[pTree->nodeNum].parent = parent;

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

#ifdef CHILD_MODE
void InitTree(CTree *cTree, ElemType rootData) {
	for (int i = 0; i < MAX_TREE_SIZE; i++) {
		cTree->nodes[i].data = '\0';
		cTree->nodes[i].firstChild = NULL;
	}
	cTree->nodeNum = 0;

	cTree->nodes[0].data = rootData;
	cTree->nodeNum++;
	cTree->rootPos = 0;
}

void AddNode(CTree *cTree, ElemType newData, int parent) {
	if (cTree->nodeNum >= MAX_TREE_SIZE) return;

	int i;
	for (i = 0; cTree->nodes[i].data != '\0'; i++);      // 找到第一个空位
	cTree->nodes[i].data = newData;

	/* 循环找到parent结点的最后一个孩子指针 */
	struct CTNode *lastChild = cTree->nodes[parent].firstChild;
	while (lastChild && lastChild->next)     // 先判断parent是否有firstChild，没有的话lastChild为空
		lastChild = lastChild->next;

	struct CTNode *newChild = (struct CTNode *) malloc(sizeof(struct CTNode));
	newChild->child = i;   // 记录新结点在数组中的位置
	newChild->next = NULL;

	if (lastChild)
		lastChild->next = newChild;
	else
		cTree->nodes[parent].firstChild = newChild;

	cTree->nodeNum++;
}

void DeleteNode(CTree *cTree, int index) {
	struct CTNode *child = cTree->nodes[index].firstChild;
	while (child) {      // 递归删除index结点的所有子结点
		int childIndex = child->child;
		DeleteNode(cTree, childIndex);

		cTree->nodeNum--;
		child = child->next;
	}
	cTree->nodes[index].data = '\0';
	cTree->nodes[index].firstChild = NULL;
	cTree->nodeNum--;
}
#endif