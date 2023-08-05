#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdbool.h>
#include <stddef.h>

#include "string/s21_sprintf.h"

#define s21_size_t unsigned long long
#define s21_NULL (void *)0

#include "string/s21_sscanf.h"

s21_size_t s21_strlen(const char *str);
char *s21_strstr(char *str1, char *str2);
void *s21_memchr(const void *arr, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy_helper(char *dest, const char *src, s21_size_t n,
                        bool isNcopy);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strcat_helper(char *dest, const char *src, s21_size_t n, bool isNcat);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *stringOne, const char *stringTwo);
s21_size_t s21_strcspn(const char *stringOne, const char *stringTwo);
char *s21_strtok(char *str, const char *delim);
char *s21_strpbrk(const char *str, const char *sym);
char *s21_strerror(int errcode);
bool s21_match(const char *inputCharArr, char inputChar);
s21_size_t s21_strspn_helper(const char *stringOne, const char *stringTwo,
                             bool isCspn);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_trim(const char *src, const char *trim_chars);

#endif  // SRC_S21_STRING_H_
