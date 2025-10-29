#include <stdio.h>
#include <string.h>

_Static_assert ((sizeof (unsigned int) == 4), 
		"for this exercise unsigned int length must be 4 bytes");

_Static_assert ((sizeof (char) == 1),
			   "for this exercise char length must be 1 byte");

char get_value(unsigned int* storage_ptr) {
	unsigned int storage = *storage_ptr;
	char value = 0;
	value = value | storage;
	storage = storage >> 8;
	*storage_ptr = storage;
	return value;
}

int main() {
	unsigned int storage = 1633837924;
	char result[5];
	for (int i = 3; i >= 0; i--) {
		result[i] =get_value(&storage);
	}

	
	printf("%s", result);

	return 0;
}
