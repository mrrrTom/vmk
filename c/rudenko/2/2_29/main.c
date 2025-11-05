#include <stdio.h>
#include <string.h>
void shift_l(unsigned int* source) {
	unsigned int val = *source;
	val = val << 1;
	char carry = 0;
	__asm__ ("setc %0" 
			: "=r" (carry));
	
	if (carry) {
		unsigned int mask = 1;	
		val = val | mask;
	}

	*source = val;
}

int main() {
	unsigned int x = 123;
	unsigned int n = 30;
	printf("x: %d, n: %d\n", x, n);

	for (int i = 0; i < n; i++) {
		shift_l(&x);
	}

	printf("shifted x: %u\n", x);
	return 0;
}
