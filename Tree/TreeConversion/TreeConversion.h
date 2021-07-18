//
// Created by マリオネット on 2021/7/18.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef INC_408_DATA_STRUCTURE_TREECONVERSION_H
#define INC_408_DATA_STRUCTURE_TREECONVERSION_H

#define ElemType char
#define MAX_TREE_NUM 50
#define LEFT (-1)
#define MID (0)
#define RIGHT (1)

typedef struct TrTNode {            // 用于转换的三叉树
  ElemType data;
  struct TrTNode *lChild, *mChild, *rChild;
} TrTNode, *TrTree;
typedef struct BiTNode {            // 二叉树定义
  ElemType data;
  struct BiTNode *lChild, *rChild;
} BiTNode, *BiTree;
typedef TrTree TrForest[MAX_TREE_NUM]; // 用于转换的森林

void InitTree_T(TrTree *trTree, ElemType rootData);                             // 三叉树初始化
TrTNode *AddNode_T(TrTNode *parentNode, ElemType newData, int pos);             // 三叉树添加结点，并返回新添加的结点

void InitTree_B(BiTree *biTree, ElemType rootData);                             // 二叉树初始化
BiTNode *AddNode_B(BiTNode *parentNode, ElemType newData, int pos);             // 二叉树添加结点，并返回新添加的结点

BiTree TrToBi(TrTree trTree);                                                   // 三叉树转化为二叉树
void Traverse_B(BiTree biTree);                                                 // 二叉树中序遍历

void InitForest(TrForest trForest);                                             // 初始化森林
BiTree FstToBi(TrForest trForest);                                              // 森林转化为二叉树

#endif //INC_408_DATA_STRUCTURE_TREECONVERSION_H
