#include <stdio.h>
// has bugs with rounding errors
bool is_bigger(int* target, double* summ, int n) {
	*summ = *summ + 1/(double)n;
	return *summ > *target;
}

int main() {
	
	int target;
	while (true) {
		printf("insert a:");
		scanf("%d", &target);
		double summ = 0;
		int i = 1;
		while (!is_bigger(&target, &summ, i)) {
			i++;
		}
		
		printf("n: %d\n", i); 
	}

	return 0;
}
