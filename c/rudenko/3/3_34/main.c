/*
 * Распечатать первые n чисел Фибоначчи
 */

#include <stdio.h>

int get_f(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	return (get_f(n-1) + get_f(n-2));
}

int main() {
	printf("insert n: ");
	int n;
	if (scanf("%d", &n) != 1)
		return 1;
	
	int prev = 0;
	int curr = 1;
	for (int i = 0; i < n; i++) {
		printf("%d ", curr);
		int next = curr + prev;
		prev = curr;
		curr = next;
	}
	
	printf("\n");

	printf("%d", get_f(n));
	printf("\n");
	return 0;
}
