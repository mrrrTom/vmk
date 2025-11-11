#include <stdio.h>
// how to handle ctrl+d - i can read char by char or remove scanf count..
double calc_next(double previous, double x) {
	double next = (previous + x / previous) / 2;
	return next;
}

double calc_dif(double previous, double current) {
	double dif = previous - current;
	return (dif < 0 ? (-dif) : dif);
}

double calc_sqrt(double x, double epsilon) {
	double previous = 1;
	double current = calc_next(previous, x);
	double dif = calc_dif(previous, current);

	while (dif >= epsilon) {
		previous = current;
		current = calc_next(previous, x);
		dif = calc_dif(previous, current);
	}

	return current;
}

int main() {
	printf("Welcome to square root calculator!\n");
	printf("Please, insert epsilon value: \n");
	double epsilon;
	if (scanf("%lf", &epsilon) != 1) {
		printf("wrong input!\n");
		return -1;
	}

	while (!feof(stdin)) {
		printf("Please, insert x value: \n");
		double x;
		if (scanf("%lf", &x) != 1) {
			//printf("wrong input!\n");
			//return -1;
		}

		double sqrt = calc_sqrt(x, epsilon);
		printf("%.10g\n", sqrt);
	}
}
