#include <stdio.h>

int main() {
	int symb = getchar();
	bool in_the_middle = false;
	while (symb != '.' && symb != EOF) {
		if (symb != '0') {
			in_the_middle = (symb > '0' && symb <= '9');
			printf("%c", symb);
		} else {
			while (symb == '0') {
				if (in_the_middle) printf("%c", symb);
				symb = getchar();
			}

			if ((symb < '0' || symb > '9') && (!in_the_middle)) {
				printf("%c", '0');
			} else {
				in_the_middle = true;
			}
			
			if (symb != '.')
			printf("%c", symb);
		}
		
		if (symb != '.')
		symb = getchar();
	}

	return 0;
}
