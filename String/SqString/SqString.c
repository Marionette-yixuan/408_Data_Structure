//
// Created by マリオネット on 2021/3/4.
//

#include "SqString.h"

#ifdef FIX_STORE

bool StrAssign(SString4 T, char *chars) {
	ClearString(T);
	int i = 1;
	for (; i < MAXSTRLEN; i++) {
		char c = chars[i - 1];
		if (c != '\0')
			T[i] = c;
		else break;
	}
	T[MAXSTRLEN] = i - 1;       // 由于i是从1开始的，所以长度是i-1
	return true;
}

int StrCompare(SString4 T, SString4 S) {     // 字符串比较，返回正数代表T较大，负数代表S较大
	int i = 0;
	int tlen = T[MAXSTRLEN], slen = S[MAXSTRLEN];
	for (; i < tlen && i < slen; i++) {
		if (T[i + 1] != S[i + 1])
			return T[i + 1] - S[i + 1];
		else continue;
	}
	return tlen - slen;     // 若没有比较出大小，则根据长度作为依据
}

int StrLength(SString4 S) {
	return S[MAXSTRLEN];
}

bool Concat(SString4 Q, SString4 S, SString4 T) {
	ClearString(Q);
	int qlen = 0;
	for (int i = 0; i < S[MAXSTRLEN] && qlen < MAXSTRLEN; i++, qlen++)
		Q[qlen + 1] = S[i + 1];
	for (int i = 0; i < T[MAXSTRLEN] && qlen < MAXSTRLEN; i++, qlen++)
		Q[qlen + 1] = T[i + 1];
	Q[MAXSTRLEN] = qlen;
	return true;
}

bool SubString(SString4 Q, SString4 S, int pos, int len) {
	ClearString(Q);
	for (int i = 0; i < len && pos + i < MAXSTRLEN; i++) {
		Q[i + 1] = S[pos + i];
	}
	Q[MAXSTRLEN] = len;
	return true;
}

bool ClearString(SString4 T) {
	for (int i = 0; i < MAXSTRLEN + 1; i++)
		T[i] = NULL;
	return true;
}

bool StrPrint(SString4 T) {
	for (int i = 0; i < T[MAXSTRLEN]; i++)
		printf("%c", T[i + 1]);
	printf("\n");
	return true;
}


#endif

#ifdef HEAP_STORE

bool StrAssign(HString *T, char *chars){
	if(T->ch)   free(T->ch);
	int length;
	char *c = chars;
	for(length = 0; *c != '\0'; length++, c++);     // 计算chars的长度
	T->length = length;
	if(!T->length) {
		T->ch = NULL;
		return false;
	} else {
		T->ch = (char*)malloc(sizeof(char) * T->length);
		if(!T->ch)  return false;
		for(int i = 0; i< length; i++)
			T->ch[i] = chars[i];
	}
	return true;
}

int StrCompare(HString S, HString T){
	int i, j;
	for(i = 0, j = 0; i< S.length && j< T.length; i++, j++){
		if(S.ch[i] != T.ch[j])
			return S.ch[i] - T.ch[j];
		else continue;
	}
	return S.length - T.length;
}

int StrLength(HString T){
	return T.length;
}

bool Concat(HString *Q, HString S, HString T){
	if(Q->ch)   free(Q->ch);
	int slen, tlen;
	char *s = S.ch, *t = T.ch;
	for(slen = 0; *s != '\0'; slen++, s++);
	for(tlen = 0; *t != '\0'; tlen++, t++);
	Q->length = slen + tlen;
	Q->ch = (char*)malloc(sizeof(char) * (slen + tlen));
	if(!Q->ch)  return false;
	int index = 0;
	for(int i = 0; i< slen; i++, index++)
		Q->ch[index] = S.ch[i];
	for(int i = 0; i< tlen; i++, index++)
		Q->ch[index] = T.ch[i];
	Q->ch[index] = '\0';
	return true;
}

bool SubString(HString *Q, HString S, int pos, int len){
	if(Q->ch)   free(Q->ch);
	Q->ch = (char*)malloc(sizeof(char) * len);
	Q->length = len;
	if(!Q->ch)   return false;
	for(int i = 0; i< len; i++)
		Q->ch[i] = S.ch[pos + i - 1];
	Q->ch[len] = '\0';
	return true;
}

#endif