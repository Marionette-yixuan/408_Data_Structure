//
// Created by マリオネット on 2021/1/3.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef INC_408_DATA_STRUCTURE_SQLIST_H
#define INC_408_DATA_STRUCTURE_SQLIST_H

#endif //INC_408_DATA_STRUCTURE_SQLIST_H

#ifdef INC_408_DATA_STRUCTURE_SQLIST_H

#define LIST_INIT_SIZE 100      // 线性表存储空间的初始分配量
#define LISTINCREMENT 10        // 线性表存储空间的分配增量
#define ElemType int
typedef struct {
  ElemType *elem;               // 存储空间基址
  int length;                   // 当前顺序表长度
  int listsize;                 // 当前分配的存储容量（单位为sizeof(ElemType)）
} SqList;

bool InitList_Sq(SqList *);      // 构造一个空的线性表L
bool ListInsert_Sq(SqList *, int, ElemType);     // 在表L的i位置前插入元素e
bool ListDelete_Sq(SqList *, int, ElemType *);    // 删除表L在i位置的元素，元素值存在e中
void ListTraverse(SqList *);     // 遍历线性表L

#endif