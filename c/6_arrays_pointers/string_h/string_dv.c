#include <string_dv.h>

int strcmp(const char* left, const char* right) {
	char* l_p = left;
	char* r_p = right;
	int cmp = 0;
	
	while (*l_p == *r_p && *l_p != '\0') {
		l_p++;
		r_p++;
	}

	return (*l_p - *r_p);
}

size_t strlen(const char* str) {
	size_t size = 0;
	const char* cursor = str;
	while (cursor && *cursor != '\0') {
		size++;
		cursor++;
	}

	return size;
}

char* strcpy(char* dest, const char* src) {
	char* d_p = dest;
	const char* s_p = src;

	while (d_p && s_p && (*s_p != '\0')) {
		*d_p = *s_p;
		d_p++;
		s_p++;
	}

	*d_p = *s_p;
	return dest;
}

char* strcat(char* dest, const char* src) {
	char* d_p = dest;
	const char* s_p = src;
	while (d_p && *d_p != '\0') d_p++;

	while(d_p && s_p && (*s_p != '\0')) {
		*d_p = *s_p;
		d_p++;
		s_p++;
	}

	*d_p = *s_p;
	return dest;
}

char* strchr(const char* cs, char c) {
	const char* s_p = cs;
	while (s_p) {
		if (*s_p == c) return s_p;
		s_p++;
	}

	return NULL;
}

char* strrchr(const char* cs, char c) {
	const char* s_p = cs;
	char* result = NULL;
	while (s_p && (*s_p != '\0')) {
		if (*s_p == c) result = s_p;
		s_p++;
	}

	return result;
}
