//
// Created by マリオネット on 2021/8/14.
//

#include "BinarySearch.h"

SSTable *InitTable(ElemType elem[], int tableLength) {
    SSTable *ssTable = (SSTable *) malloc(sizeof(SSTable));
    ssTable->elem = (ElemType *) malloc(sizeof(ElemType) * tableLength);
    ssTable->tableLength = tableLength;

    for (int i = 0; i < tableLength; i++)
        ssTable->elem[i] = elem[i];

    return ssTable;
}

int BinarySearch(SSTable ssTable, ElemType key) {
    int low = 0, high = ssTable.tableLength - 1, mid;
    while (low <= high) {
        mid = (low + high) >> 1;
        int com = ssTable.elem[mid];
        if (key < com) high = mid - 1;
        else if (key > com) low = mid + 1;
        else return mid;
    }
    return -1;
}
