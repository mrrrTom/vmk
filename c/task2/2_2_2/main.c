#include <stdio.h>
double cur_val = 0;
double x;
bool set_x = false;

void add_coef(double coef) {
	cur_val = cur_val * x + coef;
}

int max_exponent = 0;
int cur_exponent = 0;
double der = 0;

double rise(double x, int exp) {
	if (exp < 0) return 0;

	double result = 1;
	for (int i = 0; i < exp; i++) {
		result = result * x;
	}

	return result;
}

void calc() {
	double input;
	if (scanf("%lf", &input) != 1) {
		if (feof(stdin)) return; 
	}

	if (!set_x) {
		x = input;
		set_x = true;
	}
	else {
		add_coef(input);
		max_exponent++;
	}

	calc();
	if (cur_exponent <= (max_exponent - 1)) {
		der = der + cur_exponent * input * (rise(x, cur_exponent - 1));
		cur_exponent++;
	}
}

int main() {
	printf("Hello and welcome to the Horner calc!\n");
	printf("Please insert x, an, ..., a0\n");
	calc();
	printf("%.10g\n%.10g", cur_val, der);
}
