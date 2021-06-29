//
// Created by マリオネット on 2021/3/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_LKSTRING_H
#define INC_408_DATA_STRUCTURE_LKSTRING_H

#define CHUNKSIZE 5        // 每个块中存放的字符数量
typedef struct Chunk {
  char ch[CHUNKSIZE];
  struct Chunk *next;
} Chunk;
typedef struct {
  Chunk *head, *tail;       // 头尾指针
  int curlen;               // 当前串长
} LString;

bool StrAssign(LString *, char *);

int StrCompare(LString, LString);

int StrLength(LString);

bool Concat(LString *, LString, LString);

bool SubString(LString *, LString, int, int);

bool StrPrint(LString);

#endif //INC_408_DATA_STRUCTURE_LKSTRING_H
