/*
 * Подсчитать количество натуральных чисел n (111 <= n <= 999), в записи
 * которых есть две одинаковые цифры
 */


#include <stdio.h>

int match(int num) {
	int right = num % 10;
	num = num / 10;

	int middle = num % 10;
	num = num / 10;
	
	if (right == middle) return 1;

	int left = num % 10;
	return ((left == middle) || (left == right));
}

int main() {
	int count = 0;
	for (int i = 111; i < 1000; i++) {
		if (match(i)) count++;
	}

	printf("%d", count);
	return 0;
}

