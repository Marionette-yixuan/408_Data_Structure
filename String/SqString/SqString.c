//
// Created by マリオネット on 2021/3/4.
//

#include "SqString.h"

#ifdef FIX_STORE

bool StrAssign(SString4 *T, char *chars) {
	ClearString(T);
	int i = 1;
	while (i < MAXSTRLEN) {
		char c = chars[i - 1];      // chars的第i位对应新字符串的i+1位
		if (c != '\0')
			T->ch[i] = c;
		else break;
		i++;
	}
	T->length = i - 1;           // 由于i初始为1，所以长度是i-1
	return true;
}

int StrCompare(SString4 T, SString4 S) {
	int tLen = T.length, sLen = S.length;
	for (int i = 0; i < tLen && i < sLen; i++) {
		if (T.ch[i + 1] != S.ch[i + 1])
			return T.ch[i + 1] - S.ch[i + 1];      // 若有任何一位不同，则返回不同的差值作为两个字符串的差
	}
	return tLen - sLen;     // 若某字符串遍历完成还未比出大小，则返回两字符串长度的差
}

int StrLength(SString4 S) {
	return S.length;
}

bool Concat(SString4 *Q, SString4 S, SString4 T) {       // 将S和T的连接结果存入Q
	ClearString(Q);
	int qLen = 0;
	for (int i = 0; i < S.length; i++, qLen++)
		Q->ch[qLen + 1] = S.ch[i + 1];
	for (int i = 0; i < T.length && qLen + 1 < MAXSTRLEN; i++, qLen++)       // 若两字符串相加后长度越界，则截断T剩下的字符
		Q->ch[qLen + 1] = T.ch[i + 1];
	Q->length = qLen;
	return true;
}

bool SubString(SString4 *Q, SString4 S, int pos, int len) {      // 将S串[pos, pos+len-1]位置的子串存放在Q中
	ClearString(Q);
	int qLen = 0;
	for (int i = 0; i < len && pos + i < MAXSTRLEN; i++, qLen++) {
		Q->ch[i + 1] = S.ch[pos + i];
	}
	Q->length = qLen;        // 如果越界，qLen就不等于len了
	return true;
}

bool ClearString(SString4 *T) {
	for (int i = 1; i < MAXSTRLEN; i++)
		T->ch[i] = '\0';
	T->length = 0;
	return true;
}

bool StrPrint(SString4 T) {
	for (int i = 0; i < T.length; i++)
		printf("%c", T.ch[i + 1]);
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