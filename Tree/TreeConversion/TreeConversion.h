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

typedef struct TrTNode {            // 用于转换的三叉树
  ElemType data;
  struct TrTNode *lChild, *mChild, *rChild;
} TrTNode, *TrTree;
typedef struct BiTNode {            // 二叉树定义
  ElemType data;
  struct BiTNode *lChild, *rChild;
} BiTNode, *BiTree;
typedef TrTNode TrForest[MAX_TREE_NUM]; // 用于转换的森林

#endif //INC_408_DATA_STRUCTURE_TREECONVERSION_H
