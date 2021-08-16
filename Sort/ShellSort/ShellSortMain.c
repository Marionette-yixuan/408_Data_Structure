//
// Created by マリオネット on 2021/8/16.
//

#include "ShellSort.h"

int main() {
    int arr[] = {0, 49, 13, 27, 49, 76, 38, 65, 97};
    ShellSort(arr, sizeof(arr) / sizeof(arr[0]) - 1);       // 减去哨兵位
    return 0;
}