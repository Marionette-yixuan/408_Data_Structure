//
// Created by マリオネット on 2021/1/15.
//

#include "LkStack.h"
#include "LkQueue.h"

bool test3_31();

int main() {
	printf(test3_31() ? "true" : "false");
	return 0;
}

bool test3_31() {
	char inc, outqc, outsc;
	LinkQueue Q;
	InitQueue(&Q);
	LinkList S;
	InitStack(&S);
	while ((inc = getchar()) != '\n') {
		Push(S, inc);
		EnQueue(&Q, inc);
	}
	while (GetTop(S, &outsc) && QueueLength(Q)) {         // GetTop和QueueLength分别能判定栈和队列是否为空
		Pop(S, &outsc);
		DeQueue(&Q, &outqc);
		if (outsc != outqc) return false;               // 若出栈序列和出队序列不同，说明不为回文序列
	}
	return !GetTop(S, &outsc) && !QueueLength(Q);       // 检查结束，若栈和队列任一不为空，说明不匹配
}

