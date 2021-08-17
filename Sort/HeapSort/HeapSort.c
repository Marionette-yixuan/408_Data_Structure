//
// Created by マリオネット on 2021/8/17.
//

#include "HeapSort.h"

void BuildMaxHeap(int A[], int length) {
    for (int i = length >> 1; i > 0; --i)       // 从后往前调整所有非终端结点（最后一个非终端结点的下标为length/2）
        HeapAdjust(A, i, length);
}

void HeapAdjust(int A[], int root, int length) {
    A[0] = A[root];         // 0位置暂存根结点的关键字
    for (int i = root << 1; i <= length; i <<= 1) {       // 初始时i指向root子树的左孩子，每次循环后都将i指向当前子树的左孩子
        if (i < length && A[i] < A[i + 1]) i++;     // 若子树的右孩子比左孩子大，则将i指向右孩子（永远指向更大的那个，小顶堆则指向小的）
        if(A[0] >= A[i])    break;      // 如果子树的两个孩子都比树根小，说明已经调整完毕，退出循环即可（由于建立堆时从后往前调整，所以可以保证再深层的子树已经是堆了）
        else {
            A[root] = A[i];             // 找到了更大的关键字，则将大关键字放到树根里
            root = i;                   // 将更大关键字原来的位置作为新的树根，目的是看如果A[0]位置的元素交换到此位置时，会不会导致下面的子树不符合堆的要求
        }
    }
    A[root] = A[0];     // 调整完毕后，root的位置就是原来子树根所应在的正确位置
}

void HeapSort(int A[], int length) {
    BuildMaxHeap(A, length);
    for(int i = length; i > 1; --i) {
        /* 将堆顶元素换到堆尾 */
        int temp = A[i];
        A[i] = A[1];
        A[1] = temp;

        HeapAdjust(A, 1, i - 1);
    }
}