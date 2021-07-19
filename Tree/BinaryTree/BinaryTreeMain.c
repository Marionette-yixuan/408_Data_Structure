//
// Created by マリオネット on 2021/4/12.
//

#include "BinaryTree.h"

int main() {
	BiTree myTree;
	InitTree(&myTree, 5);

    AddNode(myTree, 0, 3);
    AddNode(myTree, 1, 6);
    AddNode(myTree->lchild, 0, 2);
    AddNode(myTree->lchild, 1, 4);

	PreOrderTraverse(myTree, Print);
	printf("\n");
	InOrderTraverse(myTree, Print);
	printf("\n");
	PostOrderTraverse(myTree, Print);
	printf("\n");
	LayerOrderTraverse(myTree, Print);

	return 0;
}