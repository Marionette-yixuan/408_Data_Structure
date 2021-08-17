//
// Created by マリオネット on 2021/8/17.
//

#include "MergeSort.h"

void Merge(int A[], int low, int mid, int high) {
    int *B = (int *) malloc(
        (high + 1) * sizeof(int));      // 辅助数组，网课中B的长度为A的长度，但是A的长度并没有传进来，所以就用high+1作为长度，足够放下所有的待排序列了
    for (int k = low; k < high + 1; k++) B[k] = A[k];        // 将A数组中的元素复制到B数组，这样就能直接在A数组里插入了
    int pos = low, i = low, j = mid + 1;      // pos指向A数组当前插入元素的位置, i和j分别指向两个子序列正在比对的元素
    while (i < mid + 1 && j < high + 1) {     // 网课里这里用了for循环，但while更符合逻辑，功能上没有区别
        if (B[i] <= B[j]) A[pos++] = B[i++];        // 子序列1的元素更小，则将其加入，并后移指针
        else A[pos++] = B[j++];                     // 子序列2的元素更小，则将其加入，病后移指针
    }
    while (i < mid + 1) A[pos++] = B[i++];      // 依次加入剩余元素
    while (j < high + 1) A[pos++] = B[j++];
}

void MergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) >> 1;
        MergeSort(A, low, mid);                 // 归并排序左半序列
        MergeSort(A, mid + 1, high);        // 归并排序右半序列
        Merge(A, low, mid, high);               // 合并左右序列
    }
}