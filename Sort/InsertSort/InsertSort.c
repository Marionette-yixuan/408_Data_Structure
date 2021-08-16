//
// Created by マリオネット on 2021/8/16.
//

#include "InsertSort.h"

void InsertSort(int A[], int length) {
    for (int i = 1; i < length; i++) {    // 0位置已经可以看作是有序的序列，所以从1位置开始插入
        int pos, temp = A[i];      // pos指示插入位置，temp用来暂存待插元素的值
        for (pos = i - 1; pos >= 0 && A[pos] > temp; --pos) {
            A[pos + 1] = A[pos];        // 待插元素更小，则pos位置的元素后移
        }       // 循环结束后，pos指向最后一个比待插元素大的记录
        A[pos + 1] = temp;
    }
    /* 输出数组元素 */
    for (int i = 0; i < length; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void InsertSort_P(int A[], int length) {
    for (int i = 2; i < length; i++) {
        int pos;
        A[0] = A[i];        // 0位置作为哨兵，存储待插元素的值
        for (pos = i - 1; A[pos] > A[0]; --pos)      // 这种办法不用判断pos是否到0了，因为pos = 0时元素相等，自会跳出循环
            A[pos + 1] = A[pos];
        A[pos + 1] = A[0];
    }
    for (int i = 1; i < length; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void InsertSort_B(int A[], int length) {
    for (int i = 2; i < length; i++) {
        int low = 1, high = i - 1;
        A[0] = A[i];
        while(low <= high) {
            int mid = (low + high) / 2;
            if(A[mid] > A[0])   high = mid - 1;
            else low = mid + 1;
        }       // 循环结束时，low指向要插入的位置，high=low-1
        for(int j = i - 1; j > high; --j)
            A[j + 1] = A[j];
        A[low] = A[0];
    }
    for (int i = 1; i < length; i++)
        printf("%d ", A[i]);
    printf("\n");
}