#include <stdio.h>

int is_perfect(int num) {
	int sum = 0;
	for (int i = 1; i < num; i++) {
		if (num % i == 0) sum += i;
	}

	return (sum == num);
}

int main() {
	int num;
	printf("Insert number: ");
	if (scanf("%d", &num) != 1) return 1;
	
	for (int i = 1; i < num; i++) {
		if (is_perfect(i)) printf("%d ", i);
	}

	return 0;
}
