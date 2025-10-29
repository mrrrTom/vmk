#include <stdio.h>

_Static_assert ((sizeof (unsigned int) == 4), 
		"for this exercise unsigned int length must be 4 bytes");

_Static_assert ((sizeof (char) == 1),
			   "for this exercise char length must be 1 byte");

void add_value(unsigned int* storage_ptr, char value) {
	unsigned int storage = *storage_ptr;
	
	storage = storage << 8;
	storage = storage | value;

	*storage_ptr = storage;
}

int main() {
	unsigned int storage = 0;
	char values[] = "abcd";
	for (int i = 0; i < sizeof(values) && (values[i] != '\0'); i++) {
		add_value(&storage, values[i]);
	}

	
	printf("%d", storage);

	return 0;
}
