//
// Created by マリオネット on 2021/8/16.
//

#include "InsertSort.h"

int main() {
    int arr[] = {49, 38, 65, 97, 76, 13, 27, 49};
    InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
    int arr_p[] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
    InsertSort_P(arr_p, sizeof(arr_p) / sizeof(arr_p[0]));
    int arr_b[] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
    InsertSort_B(arr_b, sizeof(arr_b) / sizeof(arr_b[0]));
    return 0;
}
