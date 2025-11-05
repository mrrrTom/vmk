#include <stdio.h>

bool can_proceed(int* source, int devider) {
	int reminder = (*source) % devider;
	if (reminder == 0) *source = (*source / devider);
	return (reminder == 0 && *source != 0); 
}

int main() {
	
	int source;
	while (true) {
		printf("insert n:");
		scanf("%d", &source);
		while (can_proceed(&source, 3)) {
		}

		if (source != 1) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}

	return 0;
}
