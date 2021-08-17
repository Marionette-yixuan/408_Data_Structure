//
// Created by マリオネット on 2021/8/17.
//

#include "HeapSort.h"

int main() {
    int arr[] = {0, 87, 45, 78, 32, 17, 65, 53, 9};
    HeapSort(arr, sizeof(arr) / sizeof(arr[0]) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
        printf("%d ", arr[i + 1]);
    return 0;
}