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

int Index(SString4 S, SString4 T, int pos) {
	/* 返回子串T在主串S中第pos个字符之后的位置，若不存在，则返回0 */
	/* 其中，T为非空，1 ≤ pos ≤ StrLength(S) */
	/* 本函数使用第四种定长字符串表示：0位不使用，最后一位表示长度 */
	int i = pos, j = 1;     // S从S[pos]开始检测，T从T[1]
	while (i <= StrLength(S) && j <= StrLength(T)) {        // i > S.length说明匹配到主串的尾部了，j > T.length说明匹配完成了
		if (T[j] == S[i]) {
			i++;
			j++;
		} else {
			pos++;      // 比对下一个子串
			i = pos;
			j = 1;
		}
	}
	if (j > StrLength(T)) return pos;     // 此处返回i - T.length也是一样的效果
	else return 0;
}

int *get_next(SString4 T) {
	int next[StrLength(T) + 1];    // next数组，第0位不使用，所以申请的空间比串长大1
	next[1] = 0;
	int i = 1;                          // next数组的下标
	int j = 0;                          // 当前比对的序号
	while (i <= StrLength(T)) {
		if (j == 0 || T[i] == T[j])
			next[++i] = ++j;
		else j = next[j];
	}
	return next;
}

int *get_nextval(SString4 T) {
	int nextval[StrLength(T) + 1];
	nextval[1] = 0;
	int i = 1, j = 0;
	while (i <= StrLength(T)) {
		if (j == 0 || T[i] == T[j]) {
			i++;
			j++;
			if (T[i] != T[j]) nextval[i] = j;
			else nextval[i] = nextval[j];
		} else j = nextval[j];
	}
	return nextval;
}

int Index_KMP(SString4 S, SString4 T, int pos) {
	int i = pos, j = 1;
	int *next = get_next(T);
	int *nextval = get_nextval(T);
	while (i <= StrLength(S) && j <= StrLength(T)) {
		if (j == 0 || S[i] == T[j]) {
			i++;
			j++;
		} else j = next[j];
	}
	if (j > StrLength(T)) return i - StrLength(T);
	else return 0;
}

bool Replace(SString4 *S, char *old, char *new) {
	/* old: 被替换的串, new: 替换成的串, form: 原串中old串之前的子串, latter: old串之后的子串, cat: latter和new连接的串*/
	SString4 oldstr, newstr, formstr, latterstr, catstr;
	StrAssign(&newstr, new);
	StrAssign(&oldstr, old);
	int pos = Index_KMP(*S, oldstr, 1);
	SubString(&formstr, *S, 1, pos - 1);        // pos - 1: 子串的长度
	int latpos = StrLength(oldstr) + pos;       // old串后方子串的起始位置
	SubString(&latterstr, *S, latpos, StrLength(S) - latpos + 1);
	Concat(&catstr, newstr, latterstr);
	Concat(S, formstr, catstr);
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