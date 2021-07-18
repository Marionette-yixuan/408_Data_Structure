//
// Created by マリオネット on 2021/6/29.
//

#include "TreeStoreStructure.h"

int main() {

#ifdef PARENT_MODE
	PTree myTree;
	InitPTree(&myTree, 'A');
	AddNode(&myTree, 'B', 0);
	AddNode(&myTree, 'C', 0);
	AddNode(&myTree, 'D', 0);
	AddNode(&myTree, 'E', 1);
	AddNode(&myTree, 'F', 1);
	AddNode(&myTree, 'G', 2);
	AddNode(&myTree, 'H', 3);
	AddNode(&myTree, 'I', 3);
	AddNode(&myTree, 'J', 3);
	AddNode(&myTree, 'K', 4);
	AddNode(&myTree, 'L', 4);
	AddNode(&myTree, 'M', 7);

	DeleteNode(&myTree, 4);
#endif

#ifdef CHILD_MODE
	CTree myTree;
	InitTree(&myTree, 'A');
	AddNode(&myTree, 'B', 0);
	AddNode(&myTree, 'C', 0);
	AddNode(&myTree, 'D', 0);
	AddNode(&myTree, 'E', 1);
	AddNode(&myTree, 'F', 1);
	AddNode(&myTree, 'G', 2);
	AddNode(&myTree, 'H', 3);
	AddNode(&myTree, 'I', 3);
	AddNode(&myTree, 'J', 3);
	AddNode(&myTree, 'K', 4);
	AddNode(&myTree, 'L', 4);
	AddNode(&myTree, 'M', 7);
	DeleteNode(&myTree, 4);
#endif

	return 0;
}
