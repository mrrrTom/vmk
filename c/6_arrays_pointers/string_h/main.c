#include <string_dv.h>
#include <stdio.h>
void strcpy_wrapper() {
	printf("***--strcpy--***\n");
	printf("copies src string to the dest string\n");
	printf("returns pointer to the dest string\n");
	printf("***----***\n");
	printf("insert dest string: ");
	char dest[100];
	if (scanf("%s", dest) != 1) {
		printf("wrong input!\n");
	}

	printf("insert source string: ");
	char source[100];
	if (scanf("%s", source) !=1) {
		printf("wrong input!\n");
	}

	char* result = strcpy(dest, source);
	printf("dest string after copy: \"%s\"\n", dest);
}

void strcat_wrapper() {
	printf("***--strcat--***\n");
	printf("appends the src string to the end of the dest string\n");
	printf("returns pointer to the dest string\n");
	printf("***----***\n");
	printf("insert dest string: ");
	char dest[100]; 
	if (scanf("%s", dest) != 1) {
		printf("wrong input!\n");
	}

	printf("insert src string: ");
	char src[100];
	if (scanf("%s", src) != 1) {
		printf("wrong input!\n");
	}

	char* result = strcat(dest, src);
	printf("dest tring after append: \"%s\"\n", result);
}

void strcmp_wrapper() {
	printf("***--strcmp--***\n");
	printf("compares two strings\n");
	printf("returns 0 - equal, > - >0, < - <0\n");
	printf("***----***\n");
	printf("insert left string: ");
	char left[100]; 
	if (scanf("%s", left) != 1) {
		printf("wrong input!\n");
	}

	printf("insert right string: ");
	char right[100];
	if (scanf("%s", right) != 1) {
		printf("wrong input!\n");
	}

	int result = strcmp(left, right);
	printf("Comparing result: %d\n", result);
}

void strchr_wrapper() {
	printf("***--strchr--***\n");
	printf("returns pointer of the first occurence of c in the cs string\n");
	printf("***----***\n");
	printf("insert cs string: ");
	char cs[100]; 
	if (scanf("%s", cs) != 1) {
		printf("wrong input!\n");
	}

	printf("insert char to find: ");
	char c;
	if (scanf(" %c", c) != 1) {
		printf("wrong input!\n");
	}

	char* result = strchr(cs, c);
	int position = result - cs;
	printf("Search result: 1) position char_ptr - str_ptr: %d\n", position);
	printf("2) symbol: %c", result);
}

void strrchr_wrapper() {
	printf("***--strrchr--***\n");
	printf("returns pointer of the last occurence of c in the cs string\n");
	printf("***----***\n");
	printf("insert cs string: ");
	char cs[100]; 
	if (scanf("%s", cs) != 1) {
		printf("wrong input!\n");
	}

	printf("insert char to find: ");
	char c;
	if (scanf(" %c", c) != 1) {
		printf("wrong input!\n");
	}

	char* result = strrchr(cs, c);
	int position = result - cs;
	printf("Search result: 1) position char_ptr - str_ptr: %d\n", position);
	printf("2) symbol: %c", result);
}

void strstr_wrapper() {
	printf("***--strstr--***\n");
	printf("returns pointer of the first occurence of ct in the cs string\n");
	printf("***----***\n");
	printf("insert cs string: ");
	char cs[100]; 
	if (scanf("%s", cs) != 1) {
		printf("wrong input!\n");
	}

	printf("insert string ct to find: ");
	char ct[100];
	if (scanf("%s", ct) != 1) {
		printf("wrong input!\n");
	}

	char* result = strstr(cs, ct);
	int position = result - cs;
	printf("Search result: 1) position ct_ptr - str_ptr: %d\n", position);
	printf("2) string: %s\n", result);
}

void strtok_wrapper() {
	printf("***--strtok--***\n");
	printf("searches first lexem in the s bounded with liters from ct\n");
	printf("***----***\n");
	printf("insert cs string: ");
	char cs[100]; 
	if (scanf("%s", cs) != 1) {
		printf("wrong input!\n");
	}

	printf("insert string ct for boundes: ");
	char ct[100];
	if (scanf("%s", ct) != 1) {
		printf("wrong input!\n");
	}

	char* result = strtok(cs, ct);
	printf("Current string part: %s\n", result);
}

void memcpy_wrapper() {
	printf("***--memcpy--***\n");
	printf("copies n chars from the ct to the s string\n");
	printf("returns pointer to the s\n");
	printf("***----***\n");
	printf("insert s string: ");
	char s[100]; 
	if (scanf("%s", s) != 1) {
		printf("wrong input!\n");
	}

	printf("insert ct string: ");
	char ct[100];
	if (scanf("%s", ct) != 1) {
		printf("wrong input!\n");
	}

	printf("insert n count: ");
	size_t count;
	if (!scanf("%d", count) != 1) {
		printf("wrong input\n");
	}

	char* result = memcpy(s, ct, count);
	printf("String s after copy: %s\n", result);
}

void memset_wrapper() {
	printf("***--memset--***\n");
	printf("puts char c in the first n positions of the string s\n");
	printf("returns pointer to the s\n");
	printf("***----***\n");
	printf("insert s string: ");
	char s[100]; 
	if (scanf("%s", s) != 1) {
		printf("wrong input!\n");
	}

	printf("insert c char: ");
	char c;
	if (scanf(" %c", c) != 1) {
		printf("wrong input!\n");
	}

	printf("insert n count: ");
	size_t count;
	if (!scanf("%d", count) != 1) {
		printf("wrong input\n");
	}

	char* result = memset(s, c, count);
	printf("String s after copy: %s\n", result);
}

void strlen_wrapper() {
	printf("returns the length of a given string except terminal zero char\n");
	printf("remarks: strings nullptr, ptr -> '\0' have length == 0\n");
	printf("insert string: ");
	char input[100];
	if (scanf("%s", input) != 1) {
		printf("wrong input!\n");
	}
	
	size_t len = strlen(input);
	printf("string length: %d\n", len);
}

struct func {
	char* name;
	void (*fp)();
};

struct func funcs[] = { { "strlen", &strlen_wrapper },
						{ "strcpy", &strcpy_wrapper },
						{ "strcat", &strcat_wrapper },
						{ "strcmp", &strcmp_wrapper },
						{ "strchr", &strchr_wrapper },
						{ "strrchr", &strrchr_wrapper },
						{ "strstr", &strstr_wrapper },
						{ "strtok", &strtok_wrapper },
						{ "memcpy", &memcpy_wrapper },
						{ "memset", &memset_wrapper} };

void call_func(const char* func_name) {
	for (int i = 0; i < (sizeof(funcs)/sizeof(funcs[0])); i++) {
		char* key = funcs[i].name;
		if (!strcmp(key, func_name)) (*funcs[i].fp)();
	}
}

int main() {
	printf("Welcome to the string functions test app!\n");
	printf("Select function for testing with command \\f <func name>\n");
	
	char input[10];
	printf("Enter function name: ");
	scanf("%s", input);
	call_func(input);
	
	while (strcmp(input,"q")) {
		printf("Continue with %s? y/n", input);
		char answer[10];
		scanf("%s", answer);
		if (!strcmp(answer, "y")) {
			call_func(input);
		}
		else if (!strcmp(answer, "n")) {
			printf("Enter function name: ");
			scanf("%s", input);
			call_func(input);
		}
	}
	
	return 0;
}
