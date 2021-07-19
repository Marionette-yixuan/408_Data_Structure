//
// Created by マリオネット on 2021/7/19.
//

#include "TreeTraversion.h"

void InitTree_T(TrTree *trTree, ElemType rootData) {
    TrTNode *rootNode = (TrTNode *) malloc(sizeof(TrTNode));
    rootNode->data = rootData;
    rootNode->lChild = NULL;
    rootNode->mChild = NULL;
    rootNode->rChild = NULL;
    *trTree = rootNode;
}

TrTNode *AddNode_T(TrTNode *parentNode, ElemType newData, int pos) {
    TrTNode *newNode = (TrTNode *) malloc(sizeof(TrTNode));
    newNode->data = newData;
    newNode->lChild = NULL;
    newNode->mChild = NULL;
    newNode->rChild = NULL;

    if (pos == LEFT)
        parentNode->lChild = newNode;
    else if (pos == MID)
        parentNode->mChild = newNode;
    else if (pos == RIGHT)
        parentNode->rChild = newNode;
    else return NULL;

    return newNode;
}

void PreTraverse_T(TrTree trTree) {
    if (trTree) {
        printf("%c ", trTree->data);
        /* 依次先序遍历每棵子树 */
        PreTraverse_T(trTree->lChild);      // 这里如果为子树空就会直接返回，无伤大雅
        PreTraverse_T(trTree->mChild);
        PreTraverse_T(trTree->rChild);
    }
}

void PostTraverse_T(TrTree trTree) {
    if (trTree) {
        /* 依次先序遍历每棵子树 */
        PostTraverse_T(trTree->lChild);
        PostTraverse_T(trTree->mChild);
        PostTraverse_T(trTree->rChild);
        /* 最后访问根结点 */
        printf("%c ", trTree->data);
    }
}

void LayerTraverse_T(TrTree trTree) {
    LinkQueue supQ;
    InitQueue(&supQ);
    EnQueue(&supQ, *trTree);
    while (QueueLength(supQ)) {
        TrTNode popNode;
        DeQueue(&supQ, &popNode);
        printf("%c ", popNode.data);
        if (popNode.lChild) EnQueue(&supQ, *(popNode.lChild));
        if (popNode.mChild) EnQueue(&supQ, *(popNode.mChild));
        if (popNode.rChild) EnQueue(&supQ, *(popNode.rChild));
    }
}

bool InitQueue(LinkQueue *Q) {
    QNode *head_node = (QNode *) malloc(sizeof(QNode));
    if (!head_node) return false;
    head_node->next = NULL;
    Q->front = head_node;
    Q->rear = head_node;
    return true;
}

int QueueLength(LinkQueue Q) {
    int length = 0;
    QNode *node = Q.front;
    while (node->next) {
        node = node->next;
        length++;
    }
    return length;
}

bool EnQueue(LinkQueue *Q, TrTNode e) {
    QNode *new_node = (QNode *) malloc(sizeof(QNode));
    if (!new_node) return false;
    new_node->data = e;
    new_node->next = Q->rear->next;
    if (Q->rear == Q->front) Q->front->next = new_node;
    Q->rear->next = new_node;
    Q->rear = new_node;
    return true;
}

bool DeQueue(LinkQueue *Q, TrTNode *e) {
    if (Q->rear == Q->front) return false;
    QNode *de_node = Q->front->next;    // 头结点的下一个结点是首元结点
    *e = de_node->data;
    Q->front->next = de_node->next;
    if (!Q->front->next) Q->rear = Q->front;
    free(de_node);
    return true;
}