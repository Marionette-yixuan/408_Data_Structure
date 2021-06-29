//
// Created by マリオネット on 2021/3/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_SQSTRING_H
#define INC_408_DATA_STRUCTURE_SQSTRING_H

#define FIX_STORE       // 更改这一行来使用不同的存储方式

/* 定长存储 */
#define MAXSTRLEN 255
typedef unsigned char SString1[MAXSTRLEN + 1];  // 最后一位存储串长
typedef unsigned char SString2[MAXSTRLEN + 1];  // 0号位置存放串长，这种方式字符的位序和数组下标相同
typedef unsigned char SString3[MAXSTRLEN];  // 串以'\0'作为结尾
typedef unsigned char SString4[MAXSTRLEN + 1];  // 教材使用的版本：0位置弃用，最后一位存储串长

/* 堆存储 */
typedef struct {
  char *ch;         // 若为非空串，则按串的长度分配存储区，否则为NULL
  int length;       // 串长
} HString;

#ifdef FIX_STORE

bool StrAssign(SString4, char *);        // 字符串分配
int StrCompare(SString4, SString4);     // 字符串比较
int StrLength(SString4);                // 字符串长度
bool Concat(SString4, SString4, SString4);     // 字符串连接
bool SubString(SString4, SString4, int, int);  // 求子串
bool ClearString(SString4);             // 清空串
bool StrPrint(SString4);                // 打印串

#endif

#ifdef HEAP_STORE

bool StrAssign(HString*, char*);
int StrCompare(HString, HString);
int StrLength(HString);
bool Concat(HString*, HString, HString);
bool SubString(HString*, HString, int, int);
bool ClearString(HString*);

#endif

#endif //INC_408_DATA_STRUCTURE_SQSTRING_H
