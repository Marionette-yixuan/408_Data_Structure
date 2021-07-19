//
// Created by マリオネット on 2021/7/18.
//

#include "TreeConversion.h"

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

	BiTree cvsBiTree = TrToBi(myTrTree);
	Traverse_B(cvsBiTree);

	TrForest myForest = { myTrTree, myTrTree };
	cvsBiTree = FstToBi(myForest);
	Traverse_B(cvsBiTree);

	return 0;
}