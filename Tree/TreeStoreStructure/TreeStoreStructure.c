//
// Created by マリオネット on 2021/6/29.
//

#include "TreeStoreStructure.h"

#ifdef PARENT_MODE

void InitPTree(PTree *pTree, ElemType rootData) {
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


}

#endif
