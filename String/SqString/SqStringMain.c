//
// Created by マリオネット on 2021/3/4.
//

#include "SqString.h"

int main() {

# ifdef FIX_STORE
	SString4 T, S, Q;
	StrAssign(&T, "Never gonna");
	StrAssign(&S, " give you up");
	StrPrint(T);
	printf("%d\n", StrCompare(T, S));
	Concat(&Q, T, S);
	StrPrint(Q);
	SubString(&Q, T, 3, 6);
	StrPrint(Q);
	printf("%d", StrLength(T));
#endif
#ifdef HEAP_STORE
	HString T, S, Q;
	StrAssign(&T, "Never gonna");
	StrAssign(&S, " give you up");
	printf("%s\n", T.ch);
	printf("%d\n", StrCompare(T, S));
	Concat(&Q, T, S);
	printf("%s\n", Q.ch);
	SubString(&Q, T, 3, 6);
	printf("%s\n", Q.ch);
	printf("%d", StrLength(T));
#endif

	return 0;
}