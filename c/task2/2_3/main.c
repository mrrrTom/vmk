#include <stdio.h>

int calc_ite(int i) {
	if (i == 0) return 0;
	if (i == 1) return 1;

	int prev_prev = 0;
	int prev = 1;
	int cur = 0;
	for (int c = 2; c <= i; c++) {
		cur = prev_prev + prev;
		prev_prev = prev;
		prev = cur;
	}

	return cur;
}

int calc_rec(int i) {
	if (i == 0) return 0;
	if (i == 1) return 1;

	return (calc_rec(i - 2) + calc_rec(i - 1));
}

int main() {
	printf("Hello and welcome to the Fibonacci calculator!\n");
	printf("Please insert xs to the end of file... : \n");
	while (true) {
		int input;
		if (scanf("%d", &input) != 1) {
			if (feof(stdin)) return 0;
			printf("Wrong input!");
			return -1;
		}
		int ite_result = calc_ite(input);
		printf("Iterative result: %d\n", ite_result);
		int rec_result = calc_rec(input);
		printf("Recursive result: %d\n", rec_result);
	}
}
