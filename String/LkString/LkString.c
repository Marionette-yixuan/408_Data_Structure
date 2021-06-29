//
// Created by マリオネット on 2021/3/5.
//

#include "LkString.h"

bool StrAssign(LString *S, char *chars) {

	char *c = chars;
	if (!c) return false;       // 空字符串，直接返回
	int index = 0, strlen = 0;

	Chunk *head_chunk = (Chunk *) malloc(sizeof(Chunk));  // 头结点
	if (!head_chunk) return false;
	Chunk *current_chunk = head_chunk;

	while (*c != '\0') {
		strlen++;
		current_chunk->ch[index++] = *c++;
		if (index >= CHUNKSIZE) {
			Chunk *new_chunk = (Chunk *) malloc(sizeof(Chunk));
			if (!new_chunk) return false;
			current_chunk->next = new_chunk;
			current_chunk = new_chunk;
			current_chunk->next = NULL;
			index = 0;
		}
	}
	while (index < CHUNKSIZE)
		current_chunk->ch[index++] = '\0';
	S->head = head_chunk;
	S->tail = current_chunk;
	S->curlen = strlen;
	return true;
}

int StrCompare(LString S, LString T) {
	Chunk *sstr = S.head, *tstr = T.head;
	for (int i = 0, index = 0; i < S.curlen && i < T.curlen; i++) {
		char schar = sstr->ch[index], tchar = tstr->ch[index];
		if (schar != tchar)
			return schar - tchar;
		index++;
		if (index >= CHUNKSIZE) {
			index = 0;
			sstr = sstr->next;
			tstr = tstr->next;
		}
	}
	return S.curlen - T.curlen;
}

int StrLength(LString S) {
	return S.curlen;
}

bool Concat(LString *Q, LString S, LString T) {
	int index = 0, strlen = 0;
	Chunk *curchunk = S.head;
	char *c = curchunk->ch;

	Chunk *head_chunk = (Chunk *) malloc(sizeof(Chunk));
	if (!head_chunk) return false;
	Chunk *current_chunk = head_chunk;

	for (int i = 0; i < 2; i++) {
		while (*c != '\0' || curchunk->next) {
			if (*c == '\0') {
				curchunk = curchunk->next;
				c = curchunk->ch;
			}
			strlen++;
			current_chunk->ch[index++] = *c++;
			if (index >= CHUNKSIZE) {
				Chunk *new_chunk = (Chunk *) malloc(sizeof(Chunk));
				if (!new_chunk) return false;
				current_chunk->next = new_chunk;
				current_chunk = new_chunk;
				current_chunk->next = NULL;
				index = 0;
			}
		}
		curchunk = T.head;
		c = curchunk->ch;
	}

	while (index < CHUNKSIZE)
		current_chunk->ch[index++] = '\0';
	Q->curlen = strlen;
	Q->head = head_chunk;
	Q->tail = current_chunk;
	return true;
}

bool SubString(LString *Q, LString S, int pos, int len) {
	Chunk *head_chunk = (Chunk *) malloc(sizeof(Chunk));
	if (!head_chunk) return false;
	Chunk *current_chunk = head_chunk;

	Chunk *s_chunk = S.head;
	while (pos > CHUNKSIZE) {
		s_chunk = s_chunk->next;
		pos -= CHUNKSIZE;
	}
	int sdex = pos - 1, count = 0, index = 0;
	while (count++ < len) {
		current_chunk->ch[index++] = s_chunk->ch[sdex++];
		if (index >= CHUNKSIZE) {
			Chunk *new_chunk = (Chunk *) malloc(sizeof(Chunk));
			if (!new_chunk) return false;
			current_chunk->next = new_chunk;
			current_chunk = new_chunk;
			current_chunk->next = NULL;
			index = 0;
		}
		if (sdex >= CHUNKSIZE) {
			s_chunk = s_chunk->next;
			sdex = 0;
		}
	}
	while (index < CHUNKSIZE)
		current_chunk->ch[index++] = '\0';
	Q->curlen = len;
	Q->head = head_chunk;
	Q->tail = current_chunk;
	return true;
}

bool StrPrint(LString S) {
	Chunk *current_chunk = S.head;
	while (current_chunk) {
		printf("%s", current_chunk->ch);
		current_chunk = current_chunk->next;
	}
	printf("\n");
	return true;
}