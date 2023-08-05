#include "../s21_string.h"

#include <stdio.h>
#include <stdlib.h>

#include "s21_strerror_codes.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  while (*str != '\0') {
    str++;
    len++;
  }
  return (s21_size_t)len;
}

char *s21_strstr(char *str1, char *str2) {
  s21_size_t i = 0, j = 0;
  char *a = s21_NULL;
  if (str1[0] == '\0' && str2[0] != '\0') {
    a = s21_NULL;
  } else if (str1[0] == '\0' && str2[0] == '\0') {
    a = "";
  } else {
    while (str1[i] != '\0' && a == s21_NULL) {
      if (str1[i] == str2[j]) {
        j++;
      } else {
        j = 0;
      }
      if (str2[j] == '\0') {
        if (j == s21_strlen(str2) && j != 0) {
          a = str1 + i - j + 1;
        } else if (j == s21_strlen(str2) && j == 0) {
          a = str1;
        }
      }
      i++;
    }
  }
  return a;
}

void *s21_memchr(const void *arr, int c, s21_size_t n) {
  void *sym = s21_NULL;
  void *tmp = (void *)arr;
  if (n > 0) {
    while ((*((int *)tmp) != c && *((unsigned char *)tmp) != c) && n > 1) {
      n--;
      tmp++;
    }
    if (*((int *)tmp) == c) {
      sym = tmp;
    } else if (*((unsigned char *)tmp) == c) {
      sym = tmp;
    }
  }
  return sym;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  char *tmp1 = (char *)str1;
  char *tmp2 = (char *)str2;
  while (n > 0) {
    result = *(char *)tmp1 - *(char *)tmp2;
    if (result != 0) {
      n = 0;
    } else {
      tmp1++;
      tmp2++;
      n--;
    }
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *tmp = dest;
  const char *s = src;
  while (n > 0) {
    *tmp = *s;
    tmp++;
    s++;
    n--;
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *tmp = dest;
  const char *s = src;
  char move[n];
  for (s21_size_t i = 0; i < n; i++) {
    move[i] = *s;
    s++;
  }
  for (s21_size_t i = 0; i < n; i++) {
    *tmp = move[i];
    tmp++;
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *tmp = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    *tmp = c;
    tmp++;
  }
  if (n == 0) {
  }
  return str;
}

char *s21_strchr(const char *str, int c) {
  char *sym = s21_NULL;
  int check = 1;
  while (*str && check) {
    if (*str == c) {
      sym = (char *)str;
      check = 0;
    }
    str++;
  }
  if (c == '\0') {
    sym = "";
  }
  return sym;
}

int s21_strcmp(const char *str1, const char *str2) {
  int check = 1, result = 0;
  while (*str1 && *str2 && check) {
    if (*str1 - *str2 != 0) {
      result = *str1 - *str2;
      check = 0;
    } else {
      str1++;
      str2++;
    }
  }
  if (!*str1 && !*str2) {
    result = 0;
  } else if (!*str2) {
    result = *str1;
  } else if (!*str1) {
    result = -*str2;
  }

  return result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int check = 1, result = 0;
  while (*str1 && *str2 && check && n) {
    if (*str1 - *str2 != 0) {
      result = *str1 - *str2;
      check = 0;
    } else {
      str1++;
      str2++;
      n--;
    }
  }
  if (!*str1 && !*str2 && n) {
    result = 0;
  } else if (!*str2 && n) {
    result = *str1;
  } else if (!*str1 && n) {
    result = -*str2;
  }

  return result;
}

s21_size_t s21_strspn_helper(const char *stringOne, const char *stringTwo,
                             bool isCspn) {
  int i = 0;
  s21_size_t returnValue = 0;
  bool whileBreak = false;
  bool check = false;

  while (stringOne[i] != '\0' && whileBreak != true) {
    if ((check = s21_match(stringTwo, stringOne[i])) == isCspn) {
      whileBreak = true;
      returnValue = i;
    }
    i++;
    if (stringOne[i] == '\0' && check == false && isCspn == true) {
      returnValue = i;
    }
  }
  if (stringOne[i] == '\0' && check == true && isCspn == false) {
    returnValue = i;
  }
  return (s21_size_t)returnValue;
}

// проверяет есть ли символ inputChar в массиве inputCharArr:
bool s21_match(const char *inputCharArr, char inputChar) {
  int match = false;
  int i = 0;
  while (inputCharArr[i] != '\0') {
    if (inputCharArr[i] == inputChar) {
      match = true;
    }
    i++;
  }
  return match;
}

s21_size_t s21_strspn(const char *stringOne, const char *stringTwo) {
  return s21_strspn_helper(stringOne, stringTwo, false);
}

s21_size_t s21_strcspn(const char *stringOne, const char *stringTwo) {
  return s21_strspn_helper(stringOne, stringTwo, true);
}

// char *s21_strrchr(const char *str, int c) {
//   bool whileBreak = false;
//   char *returnValue = s21_NULL;
//   long long int i = s21_strlen(str) - 1;
//   if (c == '\0') {
//     returnValue = "";
//   }
//   while (i >= 0 && whileBreak != true) {
//     if (str[i] == c) {
//       returnValue = (char *)str + i;
//       whileBreak = true;
//     }
//     i--;
//   }
//   return returnValue;
// }

char *s21_strrchr(const char *str, int c) {
  s21_size_t n = s21_strlen(str) + 1;
  void *src = (void *)str;
  void *res = s21_NULL;
  void *temp = s21_NULL;
  while ((temp = s21_memchr(src, c, n)) != s21_NULL) {
    res = temp;
    n -= (res - src + 1);
    src = temp + 1;
  }
  return ((char *)res);
}

char *s21_strcpy(char *dest, const char *src) {
  return s21_strcpy_helper(dest, src, 0, false);
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  return s21_strcpy_helper(dest, src, n, true);
}

char *s21_strcpy_helper(char *dest, const char *src, s21_size_t n,
                        bool isNcopy) {
  int i = 0;
  s21_size_t counter = 0;
  if (isNcopy == true) {
    while (src[i] != '\0' && counter < n) {
      dest[i] = src[i];
      counter++;
      i++;
    }
    while (counter < n) {
      dest[i] = '\0';
      counter++;
      i++;
    }
  } else {
    while (src[i] != '\0') {
      dest[i] = src[i];
      i++;
    }
    dest[i] = '\0';
  }
  return (char *)dest;
}

char *s21_strcat(char *dest, const char *src) {
  return s21_strcat_helper(dest, src, 0, false);
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  return s21_strcat_helper(dest, src, n, 1);
}

char *s21_strcat_helper(char *dest, const char *src, s21_size_t n,
                        bool isNcat) {
  s21_size_t destLen = s21_strlen(dest);
  int i = 0;
  s21_size_t counter = 0;
  if (isNcat == 1) {
    while (src[i] != '\0' && counter < n) {
      dest[destLen + i] = src[i];
      counter++;
      i++;
    }
  } else {
    while (src[i] != '\0') {
      dest[destLen + i] = src[i];
      i++;
    }
  }
  dest[destLen + i] = '\0';
  return (char *)dest;
}

char *s21_strtok(char *str, const char *delim) {
  static char *new_str;
  char *tmp = str;
  int check = 1;
  if (str != s21_NULL) {
    new_str = str;
  } else if (!new_str) {  // если строка закончилась, возвращаем 0
    tmp = 0;
    check = 0;
  }
  if (check != 0) {
    s21_size_t check1 =
        s21_strspn(new_str, delim);  // есть ли сейчас разделитель

    str = new_str + check1;  // перепрыгиваем разделитель
    tmp = new_str + check1;
    s21_size_t check2 =
        s21_strcspn(str, delim);  // длина до следующего разделителя
    new_str = str + check2;  // перепрыгиваем до следующего разделителя
    if (new_str == str) {  // для случая когда стартовая строка пустая
      tmp = 0;
      new_str = 0;
    } else {
      if (*new_str != 0) {  // зануляем разделитель
        *new_str = 0;
        new_str++;
      } else {
        new_str = s21_NULL;  // если строка закончилась то s21_NULL
      }
    }
  }
  return tmp;  // возвращаем строку до зануленного разделителя
}

char *s21_strpbrk(const char *str, const char *sym) {
  char *temp;
  s21_size_t check = s21_strcspn(str, sym);
  if (check == s21_strlen(str)) {
    temp = s21_NULL;
  } else {
    temp = (char *)str + check;
  }
  return temp;
}

char *s21_strerror(int errcode) {
  (void)errcode;
  char *error = s21_NULL;
#ifdef APPLE
  int max = 106;
  static char unknown[50] = "Unknown error: ";
#endif
#ifdef LINUX
  int max = 133;
  static char unknown[50] = "Unknown error ";
#endif
#if defined(LINUX) || defined(APPLE)
  if (errcode >= 0 && errcode <= max) {
#ifdef APPLE
    error = ErrorNames[errcode];
#else
    error = ErrorNamesLinux[errcode];
#endif
  } else {
    char num_error[20];
    s21_sprintf(num_error, "%d", errcode);  // поменять на свой
    s21_size_t i = s21_strlen(unknown);
    while (unknown[i] != ' ') {
      unknown[i] = '\0';
      i--;
    }
    s21_strcat(unknown, num_error);
    error = unknown;
  }
#endif
  return error;
}

// Part 5 Специальные функции обработки строк (вдохновленные классом String в
// языке C#)

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (!src || !str || s21_strlen(src) < start_index) {
    return NULL;  // Если один из аргументов - NULL или start_index больше длины
                  // src, то вернуть NULL
  }

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);
  s21_size_t dest_len =
      src_len + str_len + 1;  // Вычисляем длину строки для выделения памяти
  char *dest = (char *)malloc(dest_len * sizeof(char));  // выделяем память

  if (!dest) {
    return NULL;  // Если память не выделилась то NULL
  }

  s21_strncpy(dest, src, start_index);
  dest[start_index] =
      '\0';  // Добавляем NULL-терминатор для первой части строки
  s21_strcat(dest, str);  // Добавляем вставляемую строку
  s21_strcat(dest,
             src + start_index);  // Добавляем оставшуюся часть исходной строки

  return dest;
}

void *s21_to_upper(const char *str) {
  char *temp = s21_NULL;
  if (str != s21_NULL) {
    temp = calloc(s21_strlen(str) + 1, sizeof(char));
    s21_size_t i = 0;
    for (i = 0; i < s21_strlen(str); i++) {
      if (str[i] >= 97 && str[i] <= 122) {
        temp[i] = str[i] - 32;
      } else {
        temp[i] = str[i];
      }
    }
    temp[i] = '\0';
  }
  return temp;
}

void *s21_to_lower(const char *str) {
  char *temp = s21_NULL;
  if (str != s21_NULL) {
    temp = calloc(s21_strlen(str) + 1, sizeof(char));
    s21_size_t i = 0;
    for (i = 0; i < s21_strlen(str); i++) {
      if (str[i] >= 65 && str[i] <= 90) {
        temp[i] = str[i] + 32;
      } else {
        temp[i] = str[i];
      }
    }
    temp[i] = '\0';
  }
  return temp;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (!src) {
    return s21_NULL;
  }

  const char *start = src;
  const char *end = src + s21_strlen(src);

  if (trim_chars) {
    while (*start && s21_strchr(trim_chars, *start)) {
      ++start;
    }
    while (end != start && s21_strchr(trim_chars, *(end - 1))) {
      --end;
    }
  }

  const size_t len = end - start;
  char *res = malloc(len + 1);
  if (!res) {
    return NULL;
  }

  s21_strncpy(res, start, len);
  res[len] = '\0';

  return res;
}