//
// Created by マリオネット on 2021/8/17.
//

#include "BubbleSort.h"

void BubbleSort(int A[], int length) {
    bool flag = true;
    for (int i = length; i > 1 && flag; --i) {      // 从前往后比较时，每次都把最大的元素放到最后面，所以每次遍历的终点提前一位
        flag = false;       // 标记这一趟是否发生交换
        for (int j = 1; j < i; ++j) {
            if (A[j] < A[j - 1]) {
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = true;
            }
        }
    }
    for(int i = 0; i < length; ++i)
        printf("%d ", A[i]);
    printf("\n");
}