#include <stdio.h>
#include <string.h>
// considering bit counting l-endianess
void swap(int* source, int bit_num, bool val) {
	unsigned int source_val = *source;
	unsigned int offset = (sizeof(int)*8) - bit_num;
	unsigned int mask = 1 << offset;
	unsigned int s_bit = source_val & mask;
	if (s_bit == val) return;
	
	if (s_bit) {
		source_val = source_val & (!mask);
	}
	else {
		source_val = source_val | mask;
	}

	*source = source_val;
}

bool get_bit(int* source, int bit_num) {
	unsigned int offset = (sizeof(int) * 8) - bit_num - 1;
	unsigned int mask = 1 << offset;
	return (*source & mask);
}

int main() {
	unsigned int x = 123;
	unsigned int y = 243;
	unsigned int n = 5;
	unsigned int p = 2;
	printf("x: %d, y: %d, n: %d, p: %d\n", x, y, n ,p);

	for (int i = 0; i < n; i++) {
		bool bit = get_bit(&y, i);
		swap(&x, p + i, !bit);
	}

	printf("swaped x: %d\n", x);
	return 0;
}
