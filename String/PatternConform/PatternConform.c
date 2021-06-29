//
// Created by マリオネット on 2021/3/7.
//

#include "SqString.h"

int main() {
	SString4 S, T;
	StrAssign(&S, "Never gonna give you up");
	StrAssign(&T, "aabcb");
	printf("%d\n", Index(S, T, 1));
	printf("%d\n", Index_KMP(S, T, 1));
	StrPrint(S);
	Replace(S, "Never", "Always");
	StrPrint(S);
	Replace(S, "give you up", "let you down");

	return 0;
}