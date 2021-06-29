//
// Created by マリオネット on 2021/6/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_BINARYTHREADTREE_H
#define INC_408_DATA_STRUCTURE_BINARYTHREADTREE_H

#endif //INC_408_DATA_STRUCTURE_BINARYTHREADTREE_H

#ifdef INC_408_DATA_STRUCTURE_BINARYTHREADTREE_H

#define ElemType int

#define POST_ORDER       // 改这一行切换遍历顺序

#ifdef IN_ORDER
/* 中序线索二叉树 */
typedef struct InBiTNode {
  ElemType data;
  struct InBiTNode *lchild, *rchild;
  int ltag, rtag;
} InBiTNode, *InBiTree;

bool InitInTree (InBiTree *T, ElemType e);    // 初始化树
bool AddNode (InBiTNode *TNode, int LorR, ElemType e);   // 添加结点
void InThreadlize (InBiTree *T);     // 中序线索化
void InThreading (InBiTree T);   // 递归线索化函数
void InThreadTraverse(InBiTree T);  // 中序线索二叉树的遍历
InBiTNode *NextNode(InBiTNode *T);  // 找到中序遍历中T的后继元素
InBiTNode *PreNode(InBiTNode *T);   // 找到中序遍历中T的前驱元素
#endif

#ifdef PRE_ORDER
/* 先序线索二叉树 */
typedef struct PreBiTNode {
  ElemType data;
  struct PreBiTNode *lchild, *rchild;
  int ltag, rtag;
} PreBiTNode, *PreBiTree;

bool InitPreTree(PreBiTree *T, ElemType e);
bool AddNode (PreBiTNode *TNode, int LorR, ElemType e);   // 添加结点
void PreThreadlize(PreBiTree *T);    // 先序线索化
void PreThreading(PreBiTree T);      // 递归线索化函数
void PreThreadTraverse(PreBiTree T); // 先序线索二叉树的遍历
PreBiTNode *NextNode(PreBiTNode *T); // 找到先序遍历中T的后继元素
// 先序遍历中T的前驱元素需要在遍历过程中找
#endif

#ifdef POST_ORDER
typedef struct PostBiTNode {
  ElemType data;
  struct PostBiTNode *lchild, *rchild;
  int ltag, rtag;
} PostBiTNode, *PostBiTree;

bool InitPostTree(PostBiTree *T, ElemType e);

bool AddNode(PostBiTNode *TNode, int LorR, ElemType e);    // 添加结点
void PostThreadlize(PostBiTree *T); // 后序线索化
void PostThreading(PostBiTree T);   // 递归线索化函数
// 后序线索二叉树的遍历比较复杂，建议使用递归方法
// 后序遍历中T的后继元素需要在遍历过程中找
PostBiTNode *PreNode(PostBiTNode *T);   // 找到后序遍历中T的前驱元素
#endif

#endif
