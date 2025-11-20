#include <std_list.h>

int main() {
	printf("Hello and welcome to the best words reader!\n");
	printf("Start insertind words to the EOF: ");
	 w_list* l_ptr = init();
	char wd[100];
	int w_size = 0;
	while ((scanf("%s", wd) != -1)) {
		w_size = add(l_ptr, wd);
	}
	
	w_ptr cursor;
	while (cursor = find(l_ptr, wd, w_size)) {
		delete_w(l_ptr, cursor);
	}

	add(l_ptr, wd);
	printf("After removing last word: ");
	print_l(l_ptr);
	printf("\n");
	clean_up(l_ptr);
	return 0;
}
