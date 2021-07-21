//
// Created by マリオネット on 2021/7/21.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef INC_408_DATA_STRUCTURE_HUFFMANTREE_H
#define INC_408_DATA_STRUCTURE_HUFFMANTREE_H

#endif //INC_408_DATA_STRUCTURE_HUFFMANTREE_H

#ifdef INC_408_DATA_STRUCTURE_HUFFMANTREE_H

#define ElemType char

typedef struct Data {
  ElemType data;
  int weight;
} Data;

typedef struct HTNode {                 // 赫夫曼树的结点
  Data data;
  struct HTNode *lchild, *rchild;
} HTNode, *HTree;
typedef struct TLNode {                 // TreeListNode
  HTree data;
  struct TLNode *next;
} TLNode, *TList;
typedef struct HuffCode {               // 编码结果
  ElemType data;
  char *encode;
} HuffCode;

HTree InitTree(ElemType data, int weight, TList tList);
HTree MakeTree(HTree lTree, HTree rTree);           // 将两个子树连成一个新树并返回

TList InitList();                                   // 链表初始化
void InsertList(TList tList, HTree hTree);          // 将新子树放入集合中
void DeleteList(TList tList, HTree hTree);          // 从集合中删除
int ListLength(TList tList);                        // 集合的元素数量
TLNode *GetElem(TList tList, int index);            // 获取第i-1个集合元素
HTree *MinTwoTree(TList tList);                     // 将集合中最小的两棵树放在数组中返回, 并从集合中删除这两棵树
HTree HuffmanEncode(TList tList);                   // 赫夫曼编码
void Encode(HTree hTree, char *prefix);             // 将赫夫曼树转换为编码（结果会在函数内输出）

#endif