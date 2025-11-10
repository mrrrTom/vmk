#include <string_dv.h>
#include <stdio.h>
void strcpy_wrapper() {
	printf("copies src string to the dest string\n");
	printf("returns pointer to the dest string\n");
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
						{ "strcpy", &strcpy_wrapper} };

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
