//
// Created by マリオネット on 2021/3/5.
//

#include "LkString.h"

int main() {
	LString S, T, P, Q;
	StrAssign(&S, "Never gonna");
	StrAssign(&T, " give you up");
	StrAssign(&P, "Never gonna give you up");
	StrPrint(S);
	printf("%d\n", StrCompare(S, P));
	Concat(&Q, S, P);
	StrPrint(Q);
	SubString(&Q, Q, 3, 6);
	StrPrint(Q);

	return 0;
}
