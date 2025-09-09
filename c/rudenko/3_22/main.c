/*
 * Определить, верно ли, что куб суммы цифр натурального числа n
 * равен n^2
 * для простоты не учитываю возможность переполнения
 */

#include <stdio.h>

int main() {
	printf("insert number to check: ");
	int num;
	if (scanf("%d", &num) != 1) {
		return 1;
	}

	int dbled = num * num;
	int cube = 0;
	while (num) {
		int digit = num % 10;
		num = num / 10;
		cube = cube + digit;
	}

	cube = cube * cube * cube;
	printf("%d", (cube == dbled));
	return 0;
}

/*
 * Неверно - берём 2 - получаем 0 => неверно
 */

