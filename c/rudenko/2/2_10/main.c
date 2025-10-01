#include <stdio.h>
#include <limits.h>

int main() {
	signed int y = 100;
	/* volatile - solves problem */ signed int x = INT_MAX;
	printf("%d", (x < x + y));
}

// gcc реально математически преобразует эту хрень ... он перекидывает икс налево!!!
// а вот clang порядочно считает правую часть
// https://godbolt.org/
//
//
// file:///home/tom/Downloads/C23%20latest%20working%20draft%20(2023-01-24).pdf p.14 Ex. 6 - можно переставить
// gcc main.c -ftrapv     вот тут ошибка овервлоу есть, то есть он уже не перекидывает
