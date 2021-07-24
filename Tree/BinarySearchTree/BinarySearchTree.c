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

    for (int i = 1; i < length; i++)
        Insert(*T, keys[i]);
}

bool Delete(BSTree T, int key) {
    /* 需要找到两个结点：被删除结点的双亲结点、被删除结点直接后继（右子树最左下结点）的双亲结点 */
    BSTNode *parOfDel = NULL, *delNode = NULL, *parOfDes = NULL;         // 被删除结点的双亲，被删除结点，被删除结点的后继的双亲
    /* 找parOfDel */
    int tagDel = 0;         // 标志位指示parOfDel的左孩子还是右孩子为要被删除的结点
    while (T != NULL) {
        if (key < T->key) {             // 小去左
            if (T->lChild && T->lChild->key == key) {       // T有左子树且左子树根就是要找的关键字
                parOfDel = T;
                delNode = T->lChild;
                tagDel = 0;
                break;
            }
            else
                T = T->lChild;                              // T的左子树作为新一轮循环的子树（可能为空）
        } else if (key > T->key) {      // 大去右
            if (T->rChild && T->rChild->key == key) {
                parOfDel = T;
                delNode = T->rChild;
                tagDel = 1;
                break;
            }
            else
                T = T->rChild;
        } else                      // 这种情况只可能在删除整棵树的树根时出现
            return false;           // 由于传进来的是T本身，所以无法修改，只能报错
    }
    if(!delNode)    return false;

    /* 找parOfDes */
    int childCnt = (delNode->lChild ? 1 : 0) + (delNode->rChild ? 2 : 0);       // 判断delNode是否同时有左右子树
    // childCnt=0: 无子树，1: 有左，2: 有右，3: 都有
    if(childCnt == 3) {
        if(!delNode->rChild->lChild) {          // 若右子树本身没有左孩子，则用右子树替代被删除结点的位置
            if(tagDel == 0)             // parDel的左孩子是delNode
                parOfDel->lChild = delNode->rChild;
            else if (tagDel == 1)
                parOfDel->rChild = delNode->rChild;
            delNode->rChild->lChild = delNode->lChild;          // 被删除结点的左子树连在原右子树的左侧
            free(delNode->rChild);                              // 释放空间
            return true;
        } else {                                // 若右子树有左孩子，则parOfDes至少是右子树的根结点
            parOfDes = delNode->rChild;
            while(parOfDes->lChild->lChild)                     // 循环找到右子树的最左下结点的双亲
                parOfDes = parOfDes->lChild;
            BSTNode *desNode = parOfDes->lChild;        // 这里一定要新建一个变量存储最左下结点，否则会出现指针转圈

            /* 将最左下结点的右孩子（最左下结点必没有左孩子）连在其双亲的左侧 */
            parOfDes->lChild = desNode->rChild;

            /* 将被删除结点的左右子树连在最左下结点的左右侧 */
            desNode->lChild = delNode->lChild;
            desNode->rChild = delNode->rChild;

            /* 将最左下结点连在被删除结点的对应位置（根据tagDel决定） */
            if(tagDel == 0)
                parOfDel->lChild = desNode;
            else if(tagDel == 1)
                parOfDel->rChild = desNode;

            free(delNode);
            return true;
        }
    } else if (childCnt == 2) {             // 要删除的结点只有右子树时，将右子树连在parOfDel的对应侧即可
        if(tagDel == 0)
            parOfDel->lChild = delNode->rChild;
        else if (tagDel == 1)
            parOfDel->rChild = delNode->rChild;
        free(delNode);
        return true;
    } else if (childCnt == 1) {
        if(tagDel == 0)
            parOfDel->lChild = delNode->lChild;
        else if (tagDel == 1)
            parOfDel->rChild = delNode->lChild;
        free(delNode);
        return true;
    } else {                                // 要删除的结点为叶子结点（没有孩子）时，将parOfDel的对应孩子改为NULL即可
        if(tagDel == 0)
            parOfDel->lChild = NULL;
        else if (tagDel == 1)
            parOfDel->rChild = NULL;
        free(delNode);
        return true;
    }
}