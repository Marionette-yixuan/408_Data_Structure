//
// Created by マリオネット on 2021/8/16.
//

#include "ShellSort.h"

void ShellSort(int A[], int length) {
    for (int d = length / 2; d >= 1; d /= 2) {      // 增量d每次减少至先前的1/2
        for (int i = d + 1; i <= length; i++) {     // d+1指向第一个子表的第二个元素（使用了哨兵位）
            /* 循环内部即为一次完整的对子表的插入排序 */
            int pos;
            A[0] = A[i];            // 0位置作哨兵位
            for (pos = i - d; A[pos] > A[0]; pos -= d)      // 插入排序中pos=i-1，这里是i-d
                A[pos + d] = A[pos];        // 元素后移
            A[pos + d] = A[0];
        }
    }
    for (int i = 0; i < length; i++)
        printf("%d ", A[i + 1]);
    printf("\n");
}