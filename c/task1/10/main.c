#include <stdio.h>
int count = 0;
bool check() {
	printf("Check %d\n", count++);
	return true;
}

int main() {
	if (check() || check()) {
		printf("Inside if");
	}

	return 0;
}

