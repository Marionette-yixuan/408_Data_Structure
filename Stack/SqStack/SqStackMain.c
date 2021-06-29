//
// Created by マリオネット on 2021/1/8.
//

#include "SqStack.h"

int main() {
	SqStack S;
//	int e;
	ElemType c;
	InitStack_Sq(&S);
	bool ischeck = false;
	do { // 括号匹配
		ElemType outchar;
		scanf("%c", &c);
		if (c == '(' || c == '[')
			Push(&S, c);
		else if (c == ')') {
			if (!Pop(&S, &outchar)) {
				ischeck = true;
				printf("fail");
				break;
			}
			if (outchar != '(') {
				ischeck = true;
				printf("\'(\'expected");
				break;
			}
		} else if (c == ']') {
			if (!Pop(&S, &outchar)) {
				ischeck = true;
				printf("fail\n");
			}
			if (outchar != '[') {
				ischeck = true;
				printf("\'[\'expected");
				break;
			}
		}
	} while (c != '\n');
	if (ischeck) return 0;
	if (S.base == S.top)
		printf("success");
	else
		printf("fail");
	return 0;
}
