//
// Created by マリオネット on 2021/4/12.
//

#include "BinaryTree.h"

bool InitTree(BiTree *T, ElemType e) {
    BiTNode *root = (BiTNode *) malloc(sizeof(BiTNode));
    if (!root) return false;
    root->data = e;
    root->lchild = NULL;
    root->rchild = NULL;
    *T = root;
    return true;
}

bool AddNode(BiTNode *T, int LorR, ElemType e) {
    if (!T) return false;
    BiTNode *newNode = (BiTNode *) malloc(sizeof(BiTNode));
    if (!newNode) return false;
    newNode->data = e;
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    if (LorR == 0) T->lchild = newNode;
    else if (LorR == 1) T->rchild = newNode;
    else return false;
    return true;
}

bool PreOrderTraverse(BiTree T, void Print(ElemType)) {
    Print(T->data);
    if (T->lchild)
        if (!PreOrderTraverse(T->lchild, Print)) return false;
    if (T->rchild)
        if (!PreOrderTraverse(T->rchild, Print)) return false;
    return true;
}

bool InOrderTraverse(BiTree T, void Print(ElemType)) {
    if (T->lchild)
        if (!InOrderTraverse(T->lchild, Print)) return false;
    Print(T->data);
    if (T->rchild)
        if (!InOrderTraverse(T->rchild, Print)) return false;
    return true;
}

bool PostOrderTraverse(BiTree T, void Print(ElemType)) {
    if (T->lchild)
        if (!PostOrderTraverse(T->lchild, Print)) return false;
    if (T->rchild)
        if (!PostOrderTraverse(T->rchild, Print)) return false;
    Print(T->data);
    return true;
}

void Print(ElemType e) {
    printf("%d ", e);
}

bool LayerOrderTraverse(BiTree T, void Print(ElemType)) {
    LinkQueue supQ;
    InitQueue(&supQ);
    EnQueue(&supQ, *T);
    while (QueueLength(supQ)) {
        BiTNode popNode;
        DeQueue(&supQ, &popNode);
        Print(popNode.data);
        if (popNode.lchild)
            EnQueue(&supQ, *(popNode.lchild));
        if (popNode.rchild)
            EnQueue(&supQ, *(popNode.rchild));
    }
    return true;
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

bool EnQueue(LinkQueue *Q, BiTNode e) {
    QNode *new_node = (QNode *) malloc(sizeof(QNode));
    if (!new_node) return false;
    new_node->data = e;
    new_node->next = Q->rear->next;
    if (Q->rear == Q->front) Q->front->next = new_node;
    Q->rear->next = new_node;
    Q->rear = new_node;
    return true;
}

bool DeQueue(LinkQueue *Q, BiTNode *e) {
    if (Q->rear == Q->front) return false;
    QNode *de_node = Q->front->next;    // 头结点的下一个结点是首元结点
    *e = de_node->data;
    Q->front->next = de_node->next;
    if (!Q->front->next) Q->rear = Q->front;
    free(de_node);
    return true;
}

void TraverseQueue(LinkQueue Q) {
    QNode *node = Q.front;
    while (node->next) {
        node = node->next;
        printf("%d ", node->data.data);
    }
    printf("\n");
}