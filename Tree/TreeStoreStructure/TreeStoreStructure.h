//
// Created by マリオネット on 2021/6/29.
//

#ifndef INC_408_DATA_STRUCTURE_TREESTORESTRUCTURE_H
#define INC_408_DATA_STRUCTURE_TREESTORESTRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ElemType char

#define CHILDSIB_MODE         // 更改这行换用不同的表示法

#define MAX_TREE_SIZE 100   // 树中最大结点数

#ifdef PARENT_MODE          // 双亲表示法（顺序存储）
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

#ifdef CHILD_MODE           // 孩子表示法（顺序、链式存储）
struct CTNode {
  int child;                // 孩子结点在数组（nodes）中的位置
  struct CTNode *next;      // 下一个孩子
};
typedef struct {
  ElemType data;
  struct CTNode *firstChild;    // 第一个孩子
} CTBox;
typedef struct {
  CTBox nodes[MAX_TREE_SIZE];
  int nodeNum, rootPos;         // 结点个数、根的位置
} CTree;

void InitTree(CTree *cTree, ElemType rootData);
void AddNode(CTree *cTree, ElemType newData, int parent);
void DeleteNode(CTree *cTree, int index);
#endif

#ifdef CHILDSIB_MODE        // 孩子兄弟表示法（链式存储）
typedef struct CSNode {
  ElemType data;
  struct CSNode *firstChild, *nextSib;      // 第一个孩子、右兄弟指针
} CSNode, *CSTree;

void InitTree(CSTree *csTree, ElemType rootData);
void AddNode(CSNode *parentNode, ElemType newData);
void DeleteNode(CSNode *delNode);

#endif

#endif //INC_408_DATA_STRUCTURE_TREESTORESTRUCTURE_H
