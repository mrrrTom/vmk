#include <stdio.h>
#include <limits.h>

int main() {
	printf("%s", (CHAR_MAX == SCHAR_MAX ? "Signed" : "Unsigned"));
}
