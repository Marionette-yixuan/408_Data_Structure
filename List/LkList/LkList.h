//
// Created by マリオネット on 2021/1/6.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef INC_408_DATA_STRUCTURE_LKLIST_H
#define INC_408_DATA_STRUCTURE_LKLIST_H

#endif //INC_408_DATA_STRUCTURE_LKLIST_H

#ifdef INC_408_DATA_STRUCTURE_LKLIST_H

#define ElemType int

typedef struct LNode {
  ElemType data;            // 数据域
  struct LNode *next;       // 指针域
} LNode, *LinkList;        // LNode强调结点本身，LinkList强调整个链表的指针

bool InitList_Lk(LinkList *);        // 初始化链表，创建头结点
bool GetElem_L(LinkList, int, ElemType *);       // 获得表L在i位置的元素，元素值存在e中
bool ListInsert_Lk(LinkList, int, ElemType);   // 在表L的i位置前插入元素e
bool ListDelete_Lk(LinkList, int, ElemType *);  // 删除表L在i位置的元素，元素值存在e中
void ListTraverse(LinkList);       // 遍历链表L

#endif
