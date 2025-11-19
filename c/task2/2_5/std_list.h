#include <stdio.h>
#include <stdlib.h>

typedef struct w_struct* w_ptr;

typedef struct w_struct {
	char* str;
	int size;
	bool has_child;
	w_ptr child;
	w_ptr parent;
	bool has_parent;
} word;

typedef struct {
	w_ptr first;
	w_ptr last;
} w_list;

void alloc_error() {
	fprintf(stderr, "could not to allocate memory!");
	exit(-1);
}

w_list* init() {
	w_list* ptr = malloc(sizeof(w_list));
	if (ptr) {
		ptr -> first = NULL;
		ptr -> last = NULL;
	}

	return ptr;
};

void add_empty(w_list* target) {
	if (!target) return;
	w_ptr n_word = malloc(sizeof(word));
	if (!n_word) alloc_error();
	n_word->str = NULL;
	n_word->size = 0;
	n_word->has_child = false;
	if (!target->first) {
		target->first = n_word;
		n_word->has_parent = false;
	}
	else {
		target->last->has_child = true;
		target->last->child = n_word;
		n_word->has_parent = true;
		n_word->parent = target->last;
	}

	target->last = n_word;
};

int add(w_list* target, char* str) {
	int size = 0;
	char* cursor = str;
	while(*cursor != '\0') {
		size++;
	}
	
	if (size == 0) return 0;
	add_empty(target);
	char* target_str = calloc(size, sizeof(char));
	if (!target_str) alloc_error();
	for (int i = 0; i <= size; i++) {
		*target_str = *str;
	}

	target->last->size = size;
	target->last->str = target_str;
	return size;
};

bool str_equal(char* left, char* right) {
	bool result = true;
	do {
		if (*left != *right) result = false;
	}
	while (left && right && *left != '0');

	return result;
}

word* find(w_list* src, char* str, int count) {
	word* result = NULL;
	word* current = src->first;
	do {
		if (current->size != count) continue;
		if (str_equal(current->str, str)) return current;
		current = current->child;
	}
	while (current != src->last); 
};

void delete_w(w_list* src, w_ptr ptr) {
	if (!ptr) return;

	/* c */
	if ((!(ptr->has_parent)) && (!(ptr->has_child))) {
		free(ptr->str);
		free(ptr);
		src->first = NULL;
		src->last = NULL;
		return;
	}

	/* p->c */
	if ((ptr->has_parent) && (!(ptr->has_child))) {
		src->last = src->last->parent;
		src->last->has_child = false;
		src->last->child = NULL;
		free(ptr->str);
		free(ptr);
		return;
	}

	/* c->ch */
	if ((!(ptr->has_parent)) && (ptr->has_child)) {
		src->first = ptr->child;
		ptr->child->has_parent = false;
		ptr->child->parent = NULL;
		free(ptr->str);
		free(ptr);
		return;
	}

	/* p->c->ch */
	if ((ptr->has_parent) && (ptr->has_child)) {
		ptr->parent->child = ptr->child;
		ptr->child->parent = ptr->parent;
		free(ptr->str);
		free(ptr);
		return;
	}
};

void print_l(w_list* ptr) {
	if (!ptr) return;
	if (!(ptr->first)) return;
	w_ptr cursor = ptr->first;
	while (cursor) {
		printf("%s", cursor->str);
		if (cursor != ptr->last) printf(" ");
	}
};

void clean_up(w_list* ptr) {
	if (!ptr) return;
	if (!(ptr->first)) return;
	w_ptr cursor = ptr->first;
	while (cursor) {
		delete_w(ptr, cursor);
		cursor = cursor->child;
	}

	free(ptr);
};




