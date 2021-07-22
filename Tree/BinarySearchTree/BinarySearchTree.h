//
// Created by マリオネット on 2021/7/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_BINARYSEARCHTREE_H
#define INC_408_DATA_STRUCTURE_BINARYSEARCHTREE_H

#endif //INC_408_DATA_STRUCTURE_BINARYSEARCHTREE_H

#ifdef INC_408_DATA_STRUCTURE_BINARYSEARCHTREE_H

/* 二叉排序树 */
typedef struct BSTNode {
  int key;
  struct BSTNode *lChild, *rChild;
} BSTNode, *BSTree;

BSTNode *Search(BSTree T, int key);                 // 二叉排序树的查找
bool Insert(BSTree T, int key);                     // 二叉排序树的插入
void Create(BSTree *T, int *keys, int length);      // 二叉排序树的初始化

#endif
