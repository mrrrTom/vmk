#include <std_bin_tree.h>

void print_num(b_tree* tree, int num) {
	t_node* node = find(tree, num);
	if (node) {
		printf("\n%d yes\n", node -> num);
	}
	else {
		printf("\n%d no\n", num);
	}
};

int get_num(char* input) {
	char* cur = input;
	cur++;
	int result = 0;
	while (*cur != '\0') {
		int digit = (*cur) - '0';
		result = result * 10 + digit;
		cur++;
	}

	return result;
};

int main() {
	printf("Hello in the tree creator!");
	b_tree* tree = malloc(sizeof(b_tree));
	while (true) {
		char input[100];
		scanf("%s", input);
		int num = get_num(input);
		char operation = input[0];
		switch (operation) {
			case '+':
				add_num(tree, num);
				break;
			case '-':
				remove_num(tree, num);
				break;
			case '?':
				print_num(tree, num);
				break;
			case '!':
				print_tree(tree, num);
				break;
			default:
				break;
		}
	}

	clean_up(tree);
	return 0;
};
