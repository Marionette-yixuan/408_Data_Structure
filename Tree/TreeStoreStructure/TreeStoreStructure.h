//
// Created by マリオネット on 2021/6/29.
//

#ifndef INC_408_DATA_STRUCTURE_TREESTORESTRUCTURE_H
#define INC_408_DATA_STRUCTURE_TREESTORESTRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ElemType char

#define PARENT_MODE         // 更改这行换用不同的表示法

#ifdef PARENT_MODE          // 双亲表示法（顺序存储）

#define MAX_TREE_SIZE 100   // 树中最大结点数
typedef struct {
  ElemType data;        // 数据域
  int parent;           // 双亲的位置
} PTNode;
typedef struct {
  PTNode nodes[MAX_TREE_SIZE];  // 树中全部结点的存储域
  int nodeNum;          // 结点数
} PTree;

void InitPTree(PTree *pTree, ElemType rootData);            // 初始化PTree
void AddNode(PTree *pTree, ElemType newData, int parent);   // 添加新结点
void DeleteNode(PTree *pTree, int index);                   // 删除指定下标的结点

#endif

#endif //INC_408_DATA_STRUCTURE_TREESTORESTRUCTURE_H
