#include <stdlib.h>
#include <stdio.h>

int* get_array(int size) {
	int* result = malloc(size*sizeof(int));
	for (int i = 0; i < size; i++) {
		int val = rand() % 100;
		result[i] = val;
	}

	return result;
}

void print(int* arr, int size) {
	while (size--) {
		printf("%d ", (int)*arr);
		*arr++;
	}

	printf("\n");
}

void buble_sort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (((int)*(arr + i)) > ((int)*(arr + j))) {
				int temp = (int)*(arr + i);
				*(arr + i) = (int)*(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}

void insert_sort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		int min = i;
		int j;
		for (int j = i + 1; j < size; j++) {
			if (((int)*(arr + j)) < ((int)*(arr + min))) {
				min = j;
			}
		}

		j = (int)*(arr + i);
		*(arr + i) = (int)*(arr + min);
		*(arr + min) = j;
	}
}

int main() {
	int* arr;
	arr = get_array(10);
	print(arr, 10);

	//buble_sort(arr, 10);
	insert_sort(arr, 10);
	print(arr, 10);
	
	free(arr);
	return 0;
}
