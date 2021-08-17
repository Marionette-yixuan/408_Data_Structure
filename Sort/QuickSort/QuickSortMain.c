//
// Created by マリオネット on 2021/8/17.
//

#include "QuickSort.h"

int main() {
    int arr[] = {49, 38, 65, 97, 13, 27, 49};
    QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d ", arr[i]);
    return 0;
}
