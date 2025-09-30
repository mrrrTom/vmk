#include <stdio.h>
#define KEY_LENGTH 4
int counter = KEY_LENGTH;
int key_word[KEY_LENGTH] = {'c', 'h', 'a', 'r'};

void process_match(int index) {
	key_word[index] = '.';
	counter--;
}

int match_at(int symb) {
	for (int i = 0; i < KEY_LENGTH; i++)
		if (key_word[i] == symb) return i;
	return -1;
}


int main() {
	int symb = getchar();
	
	while(symb != ((int)'.') && symb != EOF) {
		int match_index = match_at(symb);
		if (match_index >= 0) process_match(match_index);
		if (counter == 0) {
			printf("\nYes\n");
			return 0;
		}

		symb = getchar();
	}

	printf("\nNo\n");
	return 0;
}
