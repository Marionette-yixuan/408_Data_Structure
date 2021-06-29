//
// Created by マリオネット on 2021/6/23.
//

#include "BinaryThreadTree.h"

int main() {
#ifdef IN_ORDER
	InBiTree myTree;
	InitInTree (&myTree, 5);

	AddNode (myTree, 0, 3);
	AddNode (myTree, 1, 6);
	AddNode (myTree->lchild, 0, 2);
	AddNode (myTree->lchild, 1, 4);
	/*
	 * 5
	 * |--- 3
	 * |    |--- 2
	 * |    |--- 4
	 * |--- 6
	 */
	InThreadlize (&myTree);
	InThreadTraverse (myTree);
	printf ("Next node of root: %d\n", NextNode (myTree)->data);
	printf ("Pre node of root: %d\n", PreNode (myTree)->data);
#endif
#ifdef PRE_ORDER
	PreBiTree myTree;
	InitPreTree (&myTree, 5);

	AddNode (myTree, 0, 3);
	AddNode (myTree, 1, 6);
	AddNode (myTree->lchild, 0, 2);
	AddNode (myTree->lchild, 1, 4);
	/*
	 * 5
	 * |--- 3
	 * |    |--- 2
	 * |    |--- 4
	 * |--- 6
	 */
	PreThreadlize (&myTree);
	PreThreadTraverse (myTree);
	printf ("Next node of root: %d\n", NextNode (myTree)->data);
#endif
#ifdef POST_ORDER
	PostBiTree myTree;
	InitPostTree(&myTree, 5);

	AddNode(myTree, 0, 3);
	AddNode(myTree, 1, 6);
	AddNode(myTree->lchild, 0, 2);
	AddNode(myTree->lchild, 1, 4);
	/*
	 * 5
	 * |--- 3
	 * |    |--- 2
	 * |    |--- 4
	 * |--- 6
	 */
	PostThreadlize(&myTree);
	printf("Pre node of root: %d\n", PreNode(myTree)->data);
#endif

	return 0;
}

