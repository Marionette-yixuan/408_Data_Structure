//
// Created by マリオネット on 2021/8/17.
//

#include "QuickSort.h"

int Partition(int A[], int low, int high) {
    int pivot = A[low];         // 子表的第一个元素作为枢轴
    while(low < high) {
        while(low < high && A[high] >= pivot)   --high;     // 找到表左侧第一个比pivot小的元素
        A[low] = A[high];           // 移动到左侧
        while(low < high && A[low] <= pivot)    ++low;      // 找到表右侧第一个比pivot大的元素
        A[high] = A[low];           // 移动到右侧
    }
    A[low] = pivot;     // pivot归位
    return low;
}

void QuickSort(int A[], int low, int high) {
    if(low < high) {        // 递归结束的条件
        int pivotPos = Partition(A, low, high);     // 确定子表的划分
        QuickSort(A, low, pivotPos - 1);    // 快排左子表
        QuickSort(A, pivotPos + 1, high);   // 快排右子表
    }
}