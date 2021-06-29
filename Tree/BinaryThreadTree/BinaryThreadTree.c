//
// Created by マリオネット on 2021/6/22.
//

#include "BinaryThreadTree.h"

#ifdef IN_ORDER
InBiTNode *pre = NULL;  // pre指针指向遍历访问的上一个结点

bool InitInTree (InBiTree *T, ElemType e) {
	InBiTNode *root = (InBiTNode *) malloc (sizeof (InBiTNode));
	if (!root) return false;
	root->data = e;
	root->lchild = NULL;
	root->rchild = NULL;
	root->ltag = 0;     // 初始化设置两个标签均为0
	root->rtag = 0;     // 代表左右均有孩子
	*T = root;
	return true;
}

bool AddNode (InBiTNode *T, int LorR, ElemType e) {
	if (!T) return false;
	InBiTNode *newNode = (InBiTNode *) malloc (sizeof (InBiTNode));
	if (!newNode) return false;

	newNode->data = e;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	newNode->ltag = 0;
	newNode->rtag = 0;

	if (LorR == 0) T->lchild = newNode;
	else if (LorR == 1) T->rchild = newNode;
	else return false;
	return true;
}

void InThreadlize (InBiTree *T) {
	InThreading (*T);
}

/*
 * 中序遍历线索化
 * 线索化后整个树最左下的结点（中序遍历的第一个结点）ltag = 1, lchild = NULL
 * 最右下的结点（中序遍历最后一个结点）rtag = 0, rchild = NULL
 */
void InThreading (InBiTree T) {
	if (T) {
		InThreading (T->lchild);   // 左子树线索化

		if (!T->lchild) {    // 若T没有左孩子，则将左孩子域指向前驱结点
			T->lchild = pre;
			T->ltag = 1;
		}
		if (pre && !pre->rchild) {   // 更新上一个结点的右孩子域，指向当前访问结点
			pre->rchild = T;
			pre->rtag = 1;
		}
		pre = T;    // 更新pre

		InThreading (T->rchild);   // 右子树线索化
	}
}

void InThreadTraverse (InBiTree T) {
	InBiTNode *currentNode = T;

	while (currentNode) {
		/* 每次循环中都先找到currentNode为根的子树的最左下结点进行访问 */
		while (currentNode->ltag == 0) currentNode = currentNode->lchild;
		printf ("%d", currentNode->data);

		/* 如果当前结点没有右孩子，则根据线索依次访问其后继结点，直到访问的结点有右孩子 */
		while (currentNode->rtag == 1) {
			currentNode = currentNode->rchild;
			printf ("%d", currentNode->data);
		}

		/* 访问到有右孩子的结点时，以其右孩子作为新的currentNode进行下一次循环 */
		currentNode = currentNode->rchild;
	}
	printf ("\n");

}

InBiTNode *NextNode (InBiTNode *T) {
	if (T->rtag == 1) {  // rtag = 1说明右孩子域直接存放后继，返回即可
		return T->rchild;
	} else {    // rtag = 0说明T有右子树，需要找到右子树中的最左下结点为T的后继
		InBiTNode *retNode = T->rchild;
		while (retNode->ltag == 0) retNode = retNode->lchild;
		return retNode;
	}
}

InBiTNode *PreNode (InBiTNode *T) {
	if (T->ltag == 1) {  // ltag = 1说明左孩子域直接存放前驱，返回即可
		return T->lchild;
	} else {    // ltag = 0说明有左子树，需要找到左子树的最右下结点为T的前驱
		InBiTNode *retNode = T->lchild;
		while (retNode->rtag == 0) retNode = retNode->rchild;
		return retNode;
	}
}
#endif

#ifdef PRE_ORDER
PreBiTNode *pre = NULL;  // pre指针指向遍历访问的上一个结点

bool InitPreTree (PreBiTree *T, ElemType e) {
	PreBiTNode *root = (PreBiTNode *) malloc (sizeof (PreBiTNode));
	if (!root) return false;
	root->data = e;
	root->lchild = NULL;
	root->rchild = NULL;
	root->ltag = 0;     // 初始化设置两个标签均为0
	root->rtag = 0;     // 代表左右均有孩子
	*T = root;
	return true;
}

bool AddNode (PreBiTNode *T, int LorR, ElemType e) {
	if (!T) return false;
	PreBiTNode *newNode = (PreBiTNode *) malloc (sizeof (PreBiTNode));
	if (!newNode) return false;

	newNode->data = e;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	newNode->ltag = 0;
	newNode->rtag = 0;

	if (LorR == 0) T->lchild = newNode;
	else if (LorR == 1) T->rchild = newNode;
	else return false;
	return true;
}

void PreThreadlize (PreBiTree *T) {
	PreThreading (*T);
}

/*
 * 先序遍历线索化
 * 线索化后最右下结点rtag = 0, rchild = NULL
 */
void PreThreading (PreBiTree T) {
	if (T) {
		if (!T->lchild) {
			T->lchild = pre;
			T->ltag = 1;
		}
		if (pre && !pre->rchild) {
			pre->rchild = T;
			pre->rtag = 1;
		}
		pre = T;

		if (T->ltag == 0) PreThreading (T->lchild);       // 由于是先添加的前驱，所以要判断T是否有左孩子，否则会无限循环
		PreThreading (T->rchild);
	}
}

void PreThreadTraverse (PreBiTree T) {
	PreBiTNode *currentNode = T;

	while (currentNode) {
		printf ("%d", currentNode->data);
		currentNode = NextNode (currentNode);
	}

	printf ("\n");
}

PreBiTNode *NextNode (PreBiTNode *T) {
	if (T->rtag == 1) {  // rtag = 1说明右孩子域直接存放后继，返回即可
		return T->rchild;
	} else {    // rtag = 0说明T有右子树，此时要先判断是否有左子树
		if (T->ltag == 0) {     // 有左子树时，T的后继为左子树的树根
			return T->lchild;
		} else {    // 左子树为空，则T的后继为右子树的树根
			return T->rchild;
		}
	}
}
#endif

#ifdef POST_ORDER
PostBiTNode *pre = NULL;  // pre指针指向遍历访问的上一个结点

bool InitPostTree(PostBiTree *T, ElemType e) {
	PostBiTNode *root = (PostBiTNode *) malloc(sizeof(PostBiTNode));
	if (!root) return false;
	root->data = e;
	root->lchild = NULL;
	root->rchild = NULL;
	root->ltag = 0;     // 初始化设置两个标签均为0
	root->rtag = 0;     // 代表左右均有孩子
	*T = root;
	return true;
}

bool AddNode(PostBiTNode *T, int LorR, ElemType e) {
	if (!T) return false;
	PostBiTNode *newNode = (PostBiTNode *) malloc(sizeof(PostBiTNode));
	if (!newNode) return false;

	newNode->data = e;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	newNode->ltag = 0;
	newNode->rtag = 0;

	if (LorR == 0) T->lchild = newNode;
	else if (LorR == 1) T->rchild = newNode;
	else return false;
	return true;
}

void PostThreadlize(PostBiTree *T) {
	PostThreading(*T);
}

void PostThreading(PostBiTree T) {
	if (T) {
		PostThreading(T->lchild);  // 由于是先递归，所以不会出现绕圈圈的情况
		PostThreading(T->rchild);

		if (!T->lchild) {
			T->lchild = pre;
			T->ltag = 1;
		}
		if (pre && !pre->rchild) {
			pre->rchild = T;
			pre->rtag = 1;
		}
		pre = T;
	}
}

PostBiTNode *PreNode(PostBiTNode *T) {
	if (T->ltag == 1) {  // ltag = 1说明左孩子域直接存放前驱，返回即可
		return T->lchild;
	} else {    // 否则需要判断是否有右孩子
		if (T->rtag == 0) { // 如果有右孩子，则右子树的根必定为后序前驱
			return T->rchild;
		} else {    // 否则左子树的根为后序前驱
			return T->lchild;
		}

	}
}

#endif