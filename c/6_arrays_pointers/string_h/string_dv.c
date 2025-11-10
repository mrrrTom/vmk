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

char* strstr(const char* cs, const char* ct) {
	const char* c_l_p = cs;
	while (c_l_p && (*c_l_p != '\0')) {
		const char* c_r_p = c_l_p;
		bool has_match = true;
		const char* t_p = ct;
		while (has_match && t_p && (*t_p != '\0')) {
			if (*c_r_p != *t_p) has_match = false;
			c_r_p++;
			t_p++;
		}

		if (has_match) return c_l_p;
		c_l_p++;
	}

	return NULL;
}

bool is_in(char s, const char* t) {
	while (t && (*t != '\0')) {
		if (s == *t) return true;
		t++;
	}

	return false;
}

char* strtok(char* s, const char* ct) {
	if (!s) s++;
	char* s_p = s;
	while (s_p && (*s_p != '\0')) {
		if (is_in(*s_p, ct)) {
			*s_p = '\0';
			return s;
		}

		s_p++;
	}

	return s;
}

void* memcpy(void* s, const void* ct, size_t n) {
	char* s_p = s;
	char* t_p = ct;
	while (ct && (*s_p != '\0') && (*t_p != '\0') && n) {
		*s_p = *t_p;
		n--;
		t_p++;
	}

	return s;
}

void* memset(void* s, char c, size_t n) {
	char* s_p = s;
	while (s_p && (*s_p != '\0') && n) {
		*s_p = c;
		n--;
		s_p++;
	}

	return s;
}
