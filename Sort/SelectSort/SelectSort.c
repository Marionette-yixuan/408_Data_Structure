//
// Created by マリオネット on 2021/8/17.
//

#include "SelectSort.h"

void SelectSort(int A[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int min = i;        // 记录最小元素的位置
        for (int j = i + 1; j < length; j++)     // 在剩余元素中选择最小的元素
            if (A[j] < A[min]) min = j;
        if (min != i) {      // 如果第一个元素不是最小的，则将其与最小的元素交换
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
    for (int i = 0; i < length; i++)
        printf("%d ", A[i]);
    printf("\n");
}