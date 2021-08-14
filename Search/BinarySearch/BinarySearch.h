//
// Created by マリオネット on 2021/8/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_BINARYSEARCH_H
#define INC_408_DATA_STRUCTURE_BINARYSEARCH_H

#endif //INC_408_DATA_STRUCTURE_BINARYSEARCH_H

#ifdef INC_408_DATA_STRUCTURE_BINARYSEARCH_H

#define ElemType int

typedef struct {
  ElemType *elem;
  int tableLength;
} SSTable;

SSTable *InitTable(ElemType elem[], int tableLength);
int BinarySearch(SSTable ssTable, ElemType key);

#endif