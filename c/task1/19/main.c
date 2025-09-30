#include <stdio.h>

int main() {
	int dec_size = sizeof(unsigned int);
	double real = 1;
	for (int i = 0; i < dec_size * 8; i++) {
		real *= 2;
	}

	printf("%lf\n", real);
	printf("0 <= X < 2^N: %u\n", (unsigned int)(real - 1));
	printf("X >= 2^N: %u\n", (unsigned int)(real + 1));
	printf("X < 0: %u\n", (unsigned int)(real - (real + 1)));
}
