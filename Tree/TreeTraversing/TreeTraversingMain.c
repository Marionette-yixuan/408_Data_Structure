//
// Created by マリオネット on 2021/7/19.
//

#include "TreeTraversing.h"

int main() {
	TrTree myTrTree;
	InitTree_T(&myTrTree, 'A');
	TrTNode *TrNode_B = AddNode_T(myTrTree, 'B', LEFT);
	TrTNode *TrNode_C = AddNode_T(myTrTree, 'C', MID);
	TrTNode *TrNode_D = AddNode_T(myTrTree, 'D', RIGHT);
	TrTNode *TrNode_E = AddNode_T(TrNode_B, 'E', LEFT);
	TrTNode *TrNode_F = AddNode_T(TrNode_B, 'F', RIGHT);
	TrTNode *TrNode_G = AddNode_T(TrNode_C, 'G', MID);
	TrTNode *TrNode_H = AddNode_T(TrNode_D, 'H', MID);
	TrTNode *TrNode_I = AddNode_T(TrNode_D, 'I', RIGHT);
	TrTNode *TrNode_J = AddNode_T(TrNode_E, 'J', LEFT);
	TrTNode *TrNode_K = AddNode_T(TrNode_E, 'K', MID);
	TrTNode *TrNode_L = AddNode_T(TrNode_E, 'L', RIGHT);
	TrTNode *TrNode_M = AddNode_T(TrNode_H, 'M', RIGHT);

	PreTraverse_T(myTrTree);
	printf("\n");
	PostTraverse_T(myTrTree);
    printf("\n");
    LayerTraverse_T(myTrTree);

	return 0;
}

