//
// Created by マリオネット on 2021/7/22.
//

#include "BinarySearchTree.h"

BSTNode *Search(BSTree T, int key) {
    while (T != NULL && key != T->key)          // 若树空或目标值等于根结点的值，则返回树根结点（NULL或是正确结果）
        T = key > T->key ? T->rChild : T->lChild;       // 大去右，小去左
    return T;
}

bool Insert(BSTree T, int key) {
    if (key == T->key)             // 插入相同元素则报错
        return false;
    else if (key > T->key) {    // 大去右
        if (T->rChild) return Insert(T->rChild, key);       // 若右子树不为空，则以右子树的根为新的树进行插入
        else {      // 否则申请一个新结点，成为T的右孩子
            BSTNode *newNode = (BSTNode *) malloc(sizeof(BSTNode));
            newNode->key = key;
            newNode->lChild = NULL;
            newNode->rChild = NULL;
            T->rChild = newNode;
            return true;
        }
    } else {                    // 小去左
        if (T->lChild) return Insert(T->lChild, key);
        else {
            BSTNode *newNode = (BSTNode *) malloc(sizeof(BSTNode));
            newNode->key = key;
            newNode->lChild = NULL;
            newNode->rChild = NULL;
            T->lChild = newNode;
            return true;
        }
    }
}

void Create(BSTree *T, int *keys, int length) {
    /* 创建一个根结点存储第一个元素 */
    BSTNode *rootNode = (BSTNode *) malloc(sizeof(BSTNode));
    rootNode->key = keys[0];
    rootNode->lChild = NULL;
    rootNode->rChild = NULL;
    *T = rootNode;

    for (int i = 1; i< length; i++)
        Insert(*T, keys[i]);
}