#include <std_list.h>

int main() {
	printf("Hello and welcome to the best words reader!\n");
	printf("Start insertind words to the EOF: ");
	 w_list* l_ptr = init();
	char word[100];
	int w_size = 0;
	while (true) {
		// toDo insertion with tabulation and etc
		if (scanf("%s", word) != 1) {
			if (feof(stdin)) break;
		}
		
		w_size = add(l_ptr, word);
	}
	
	w_ptr cursor;
	while (cursor = find(l_ptr, word, w_size)) {
		delete_w(l_ptr, cursor);
	}

	add(l_ptr, word);
	printf("Removed last word: ");
	print_l(l_ptr);
	clean_up(l_ptr);
	return 0;
}
