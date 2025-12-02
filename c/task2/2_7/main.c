#include <calc.h>

int main() {
	printf("Hello and welcome to the greatest calculator!\n");
	printf("Please, insert smth to calculate...\n");
	ex_context* ctx = get_ctx();
	if (!ctx -> beg || !ctx -> end) {
		printf("Bad resolve!\n");
		return -1;
	}

	int result = calculate_ctx(ctx -> beg, ctx -> end);
	printf(" %d\n", result);
	printf("----------------\n");
	return 0;
};
