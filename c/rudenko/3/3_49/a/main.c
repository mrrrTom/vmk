#include <stdio.h>

int main() {
	int symb = getchar();
	while (symb != '.' && symb != EOF) {
		if (symb == '?') {
			printf("%c", '!');
		} else {
			printf("%c", symb);
		}
	
		symb = getchar();
	}

	return 0;
}
