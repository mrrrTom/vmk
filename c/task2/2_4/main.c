#include <stdio.h>
#define _POINT_CODE -1
#define _E_CODE -2
#define _MINUS_CODE -3
#define _PLUS_CODE -4
#define _F_CODE -5
#define _PARSE_ERROR_CODE -6
#define _S_END_CODE -7
bool is_ascii_integer(char coded_symb) {
	return ((coded_symb > 47) && (coded_symb < 58));
}

int parse(char input) {
	if (is_ascii_integer(input)) {
		return (input - 48);
	}
	
	int parse_result;
	switch (input) {
		case 46:
			parse_result = _POINT_CODE; /* . -> -1 */
			break;
		case 69:
		case 101:
			parse_result = _E_CODE; /* e E -> -2 */
			break;
		case 45:
			parse_result = _MINUS_CODE; /* - -> -3 */
			break;
		case 43:
			parse_result = _PLUS_CODE; /* + -> -4 */
			break;
		case 70:
		case 102:
			parse_result = _F_CODE; /* f F -> -5 */
			break;
		case '\0':
			parse_result = _S_END_CODE;
			break;
		default:
			parse_result = _PARSE_ERROR_CODE; /* parsing error code */
			break;
	}

	return parse_result;
}

bool collect_sign(char** str, double* result) {
	int parsed = parse(**str);
	switch (parsed) {
		case _MINUS_CODE:
			*result = (-1 * (*result));
			(*str)++;
			return true;
			break;
		case _PARSE_ERROR_CODE:
		case _E_CODE:
		case _F_CODE:
			return false;
			break;
		case _PLUS_CODE:
			(*str)++;
		default:
			(*result) = 1;
			return true;
			break;
	}
}

bool collect_int(char** str, double* result) {
	int int_result = 0;
	int parsed = parse(**str);
	
	while (parsed >= 0) {
		int_result = ((int_result * 10) + parsed);
		(*str)++;
		parsed = parse(**str);
	}
	
	if (parsed == _PARSE_ERROR_CODE ||
		parsed == _PLUS_CODE ||
		parsed == _MINUS_CODE ||
		parsed == _F_CODE) {
		return false;
	}

	*result = (*result) * int_result;
	return true;
}

bool collect_fract(char** str, double* result) {
	int fract_part = 0;
	int devider = 1;
	int parsed = parse(**str);
	if (parsed == _E_CODE) return true;
	if (parsed != _POINT_CODE) return false;

	(*str)++;
	parsed = parse(**str);
	if (parsed == _E_CODE) return true;
	while (parsed >= 0) {
		devider = devider * 10;
		fract_part = (fract_part * 10) + parsed;
		(*str)++;
		parsed = parse(**str);
	}

	if (parsed != _E_CODE &&
			parsed != _S_END_CODE &&
			parsed != _F_CODE)	return false;
	(*result) = ((*result) + (((double)fract_part) / ((double)devider)));
	return true;
}

bool collect_tens(char** str, double* result) {
	int tens_count = 0;
	int sign = 1;
	int parsed = parse(**str);
	if (parsed == _F_CODE || parsed == _S_END_CODE) return true;
	if (parsed != _E_CODE) return false;
	(*str)++;
	parsed = parse(**str);
	if (parsed == _PLUS_CODE) {
		(*str)++;
		parsed = parse(**str);
	}

	if (parsed == _MINUS_CODE) {
		sign = -1;
		(*str)++;
		parsed = parse(**str);
	}

	if (parsed < 0) return false;
	while (parsed >= 0) {
		tens_count = (tens_count * 10) + parsed;
		(*str)++;
		parsed = parse(**str);
	}

	for (;tens_count >0; tens_count--) {
		if (sign < 0) {
			(*result) = ((*result) / 10);
		}
		else {
			(*result) = ((*result) * 10);
		}
	}

	return true;
}

double str2double(char str[]) {
	char* str_ptr = str;
	double result = 1;
	double sign = 1;
	bool sign_collected = collect_sign(&str_ptr, &sign);
	bool collected_int = collect_int(&str_ptr, &result);
	bool collected_fract = collect_fract(&str_ptr, &result);
	bool collected_tens = collect_tens(&str_ptr, &result);
	if ((!sign_collected) ||
		(!collected_int) ||
		(!collected_fract) ||
		(!collected_tens)) {
		printf("!  parsing failed  !: ");
	}
	else {
		printf("OK parsing succeeded OK: ");
	}

	return (sign * result);
}

int main() {
	printf("Welcome to the best double reader in the world!\n");
	while (true) {
		char num[100];
		if (scanf("%s", num) != 1) {
			if (feof(stdin)) return 0;
			//printf("Wrong input!\n");
			//return -1;
		}
		
		double result = str2double(num);
		printf("parsed double: %.10g\n", result);
	}

	return 0;
}
