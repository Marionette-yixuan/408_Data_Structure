//
// Created by マリオネット on 2021/7/21.
//

#include "HuffmanTree.h"

HTree InitTree(ElemType data, int weight, TList tList) {
    HTNode *rootNode = (HTNode *) malloc(sizeof(HTNode));
    rootNode->data.data = data;
    rootNode->data.weight = weight;
    rootNode->lchild = NULL;
    rootNode->rchild = NULL;
    InsertList(tList, rootNode);
    return rootNode;
}

HTree MakeTree(HTree lTree, HTree rTree) {
    HTNode *newRoot = (HTNode *) malloc(sizeof(HTNode));
    int lWeight = lTree->data.weight, rWeight = rTree->data.weight;
    newRoot->data.data = '\0';
    newRoot->data.weight = lWeight + rWeight;
    newRoot->lchild = lTree;
    newRoot->rchild = rTree;
    return newRoot;
}

TList InitList() {
    TLNode *headNode = (TLNode *) malloc(sizeof(TLNode));
    headNode->data = NULL;
    headNode->next = NULL;
    return headNode;
}

void InsertList(TList tList, HTree hTree) {
    /* 插入在表头 */
    TLNode *newNode = (TLNode *) malloc(sizeof(TLNode));
    newNode->data = hTree;
    newNode->next = tList->next;
    tList->next = newNode;
}

void DeleteList(TList tList, HTree hTree) {
    TLNode *pre = tList, *cursor = tList->next;     // pre指向比对的前一个结点，cursor指向比对的结点
    while (cursor && cursor->data != hTree) {
        pre = pre->next;
        cursor = cursor->next;
    }
    if (cursor)
        pre->next = cursor->next;
    // 这里不能free，否则树就彻底没了
    // 只是要把它删除集合而已
}

int ListLength(TList tList) {
    int length = 0;
    while (tList->next) {
        length++;
        tList = tList->next;
    }
    return length;
}

TLNode *GetElem(TList tList, int index) {
    TLNode *retNode = tList->next;
    for (int i = 0; i < index; i++)
        retNode = retNode->next;
    return retNode;
}

HTree *MinTwoTree(TList tList) {
    HTree minTree = tList->next->data, penTree;             // 最小&倒数第二小的树
    for (int i = 0; i < ListLength(tList); i++) {
        HTree iNode = GetElem(tList, i)->data;
        if (iNode->data.weight < minTree->data.weight)
            /* 若集合中第i棵树的权重小于minTree的权重，则替换 */
            minTree = iNode;
    }
    /* 从tList中删除minTree */
    DeleteList(tList, minTree);
    /* 重复上面的操作，找出倒数第二小的 */
    penTree = tList->next->data;
    for (int i = 0; i < ListLength(tList); i++) {
        HTree iNode = GetElem(tList, i)->data;
        if (iNode->data.weight < penTree->data.weight)
            /* 若集合中第i棵树的权重小于minTree的权重，则替换 */
            penTree = iNode;
    }
    DeleteList(tList, penTree);
    HTree retTrees[2] = {minTree, penTree};
    return retTrees;
}

HTree HuffmanEncode(TList tList) {
    while(ListLength(tList) > 1) {
        HTree *minTwoTrees = MinTwoTree(tList);      // 找出权值最小的两棵树
        HTree lTree = minTwoTrees[0], rTree = minTwoTrees[1];
        InsertList(tList, MakeTree(lTree, rTree));
    }
    return GetElem(tList, 0)->data;
}

void Encode(HTree hTree, char *prefix) {
    if (hTree->data.data != '\0') {     // 不为'\0'即到达叶子结点
        printf("[%c, %s], ", hTree->data.data, prefix);
    } else {
        char cpfix[8] = {'\0'};
        strcpy(cpfix, prefix);
        Encode(hTree->lchild, strcat(cpfix, "0"));
        strcpy(cpfix, prefix);
        Encode(hTree->rchild, strcat(cpfix, "1"));
    }
}