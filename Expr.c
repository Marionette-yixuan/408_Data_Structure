//
// Created by マリオネット on 2021/1/12.
//

#include <stdio.h>

int main() {
	int max(int x, int y);

	printf("%d", max(2, 3));

	return 0;
}

int max(int x, int y) {
	return x > y ? x : y;
}