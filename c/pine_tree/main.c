#include <stdio.h>

void print_tree(int h) {

	int middle_index = h;
	int width = h * 2 + 1;
	for (int k = 1; k <= h; k ++) {
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= (width - 1); j++) {
				if ((j >= (middle_index - i)) &&
						(j <= (middle_index + i))) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}

		printf("\n");
		}
	}
}

int main() {
	printf("Insert tree hight: ");
	int h;
	if(scanf("%d", &h) != 1) {
		printf("Not valid input!");
	}

	print_tree(h);

	return 0;
}
