//
// Created by マリオネット on 2021/8/14.
//

#include "BinarySearch.h"

int main() {
    ElemType elem[] = {7, 10, 13, 16, 19, 29, 32, 33, 37, 41, 43};      // 这里必须是递增的有序表
    SSTable *ssTable = InitTable(elem, sizeof(elem) / sizeof(elem[0]));
    printf("%d\n", BinarySearch(*ssTable, 33));
    printf("%d\n", BinarySearch(*ssTable, 12));

    return 0;
}
