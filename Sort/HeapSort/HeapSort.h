//
// Created by マリオネット on 2021/8/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef INC_408_DATA_STRUCTURE_HEAPSORT_H
#define INC_408_DATA_STRUCTURE_HEAPSORT_H

#endif //INC_408_DATA_STRUCTURE_HEAPSORT_H

#ifdef INC_408_DATA_STRUCTURE_HEAPSORT_H

void BuildMaxHeap(int A[], int length);     // 建立大根堆
void HeapAdjust(int A[], int root, int length);     // 将以root为根的子树调整为大根堆
void HeapSort(int A[], int length);         // 堆排序

#endif
