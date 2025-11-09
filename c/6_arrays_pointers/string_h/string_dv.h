#include <stddef.h>

#ifndef STRING_DV_H
#define STRING_DV_H

// returns the length of a given string except terminal zero char
// strings nullptr, ptr -> '\0' have length == 0
size_t strlen(const char* str);

// copies src string to the dest string
// returns pointer to the dest string
char* strcpy(char* dest, const char* src);

// appends the src string to the end of the dest string
// returns pointer to the dest string
char *strcat(char* dest, const char* src);

// compares to strings
// returns 0 - equal, left > right => 1, left < right => -1
int strcmp(const char* left, const char* right);

// returns pointer to the first occurence of the c in the cs string
char* strchr(const char* cs, char c);

// returns pointer to the last occurence of the c in the cs string
char* strrchr(const char* cs, char c);

// returns pointer to the first occurence of the ct string in the cs string
char* strstr(const char* cs, const char* ct);

// searches first lexem in the s bounded with liters from the ct
char* strtok(char* s, const char* ct);

// copies n chars from the ct to the s
// returns pointer to the s
void* memcpy(void* s, const void* ct, size_t n);

// puts char c in the first n positions of the string s
// return pointer to the s
void* memset(void* s, char c, size_t n);

#endif
