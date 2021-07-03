//
// Created by マリオネット on 2021/1/12.
//

#include "LkStack.h"

bool test3_17();

bool test3_19();

int main() {
	LinkList L;
	ElemType e;
	InitStack(&L);
/*  // 栈测试程序
	Push(L, 24);
	Push(L, 36);
	Push(L, 48);
	StackTraverse(L);
	Pop(L, &e);
	printf("%d\n", e);
	StackTraverse(L);
	Push(L, 64);
	StackTraverse(L);
	GetTop(L, &e);
	printf("%d\n\n", e);

	InitStack_Wo(&L);
	Push_Wo(&L, 24);
	Push_Wo(&L, 36);
	Push_Wo(&L, 48);
	StackTraverse_Wo(L);
	Pop_Wo(&L, &e);
	printf("%d\n", e);
	StackTraverse_Wo(L);
	Push_Wo(&L, 64);
	StackTraverse_Wo(L);
	GetTop_Wo(L, &e);
	printf("%d\n", e);
*/

/*  // 行编辑程序
	char ch;
	do{
		ch = getchar();
		if(ch == '\n'){
			OutPut(L);
			ClearStack(L);
		}
		switch(ch){
			case '#':
				Pop(L, &e);
				break;
			case '@':
				ClearStack(L);
				break;
			default:
				Push(L, ch);
				break;
		}
	} while (ch != '~');
*/
/*	// 3.17
	printf(test3_17() ? "true\n" : "false\n");
*/
/*	// 3.19
	printf(test3_19() ? "true\n" : "false\n");
*/

	return 0;
}

bool test3_17() {
	char inc, popc;
	LinkList S;
	InitStack(&S);
	do {
		inc = (char) getchar();
		Push(S, inc);
	} while (inc != '&');
	Pop(S, &popc);
	while ((inc = (char) getchar()) != '@') {
		Pop(S, &popc);
		if (inc != popc) return false;
	}
	return !GetTop(S, &popc);
}

bool test3_19() {
	LinkList S;
	InitStack(&S);
	char inc, popc;
	do {
		inc = (char) getchar();
		if (inc == '(' || inc == '[' || inc == '{')
			Push(S, inc);
		else if (inc == ')') {
			Pop(S, &popc);
			if (popc != '(') return false;
		} else if (inc == ']') {
			Pop(S, &popc);
			if (popc != '[') return false;
		} else if (inc == '}') {
			Pop(S, &popc);
			if (popc != '{') return false;
		}
	} while (inc != '\n');
	return !GetTop(S, &popc);
}