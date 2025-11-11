#include <stdio.h>
double cur_val = 0;
double x;
bool set_x = false;

void add_coef(double coef) {
	cur_val = cur_val * x + coef;
}

int main() {
	printf("Hello and welcome to the Horner calc!\n");
	printf("Please insert x, an, ..., a0\n");
	while (!feof(stdin)) {
		double input;
		if (!scanf("%lf", &input) != 1) {
			if (feof(stdin)) break;
			// printf("Wrong input!");
			// return -1;
		}

		if (!set_x) {
			x = input;
			set_x = true;
			continue;
		}

		add_coef(input);
	}
	
	printf("%.10g", cur_val);
}
