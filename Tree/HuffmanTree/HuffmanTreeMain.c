//
// Created by マリオネット on 2021/7/21.
//

#include "HuffmanTree.h"

int main() {
    TList tList = InitList();
    HTNode *aNode = InitTree('a', 7, tList),
        *bNode = InitTree('b', 5, tList),
        *cNode = InitTree('c', 2, tList),
        *dNode = InitTree('d', 4, tList);

    HTree resTree = HuffmanEncode(tList);
    char prefix[8] = {'\0'};
    Encode(resTree, prefix);

    return 0;
}
