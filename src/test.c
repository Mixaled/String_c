#include "test.h"

// memchr
START_TEST(memchr_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  strcpy(str1, test[_i].str1);
  strcpy(str2, test[_i].str1);
  ck_assert_pstr_eq(memchr(str1, test[_i].c, test[_i].n),
                    s21_memchr(str2, test[_i].c, test[_i].n));
}
END_TEST

// memset
START_TEST(memset_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  strcpy(str1, test[_i].str1);
  strcpy(str2, test[_i].str1);
  ck_assert_pstr_eq(memset(str1, test[_i].c, test[_i].n),
                    s21_memset(str2, test[_i].c, test[_i].n));
}
END_TEST

// memcmp
START_TEST(memcmp_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  char str3[SIZE] = "";
  char str4[SIZE] = "";
  strcpy(str1, test[_i].str2);
  strcpy(str2, test[_i].str2);
  strcpy(str3, test[_i].str1);
  strcpy(str4, test[_i].str1);
  int i = 0, j = 0;
  i = memcmp(str3, str1, test[_i].n);
  j = s21_memcmp(str4, str2, test[_i].n);
  if (i == -1 || i == 1) {
    if (j < 0)
      j = -1;
    else if (j > 0)
      j = 1;
  }
  ck_assert_int_eq(i, j);
}
END_TEST

// memcpy
START_TEST(memcpy_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  char str3[SIZE] = "";
  char str4[SIZE] = "";
  strcpy(str1, test[_i].str1);
  strcpy(str2, test[_i].str1);
  strcpy(str3, test[_i].str2);
  strcpy(str4, test[_i].str2);
  ck_assert_pstr_eq(memcpy(str1, str3, test[_i].n),
                    s21_memcpy(str2, str4, test[_i].n));
}
END_TEST

// memmove
START_TEST(memmove_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  char str3[SIZE] = "";
  char str4[SIZE] = "";
  strcpy(str1, test[_i].str1);
  strcpy(str2, test[_i].str1);
  strcpy(str3, test[_i].str2);
  strcpy(str4, test[_i].str2);
  ck_assert_pstr_eq(memmove(str1, str3, test[_i].n),
                    s21_memmove(str2, str4, test[_i].n));
}
END_TEST

// strcat
START_TEST(strcat_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  strcpy(str1, test[_i].str1);
  strcpy(str2, test[_i].str1);
  ck_assert_pstr_eq(strcat(str1, test[_i].str2),
                    s21_strcat(str2, test[_i].str2));
}
END_TEST

// strncat
START_TEST(strncat_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  strcpy(str1, test[_i].str1);
  strcpy(str2, test[_i].str1);
  ck_assert_pstr_eq(strncat(str1, test[_i].str2, test[_i].n),
                    s21_strncat(str2, test[_i].str2, test[_i].n));
}
END_TEST

// strchr
START_TEST(strchr_test) {
  ck_assert_pstr_eq(strchr(test[_i].str2, test[_i].c),
                    s21_strchr(test[_i].str2, test[_i].c));
}
END_TEST

// strcmp
START_TEST(strcmp_test) {
  int i = 0, j = 0;
  i = strcmp(test[_i].str1, test[_i].str2);
  j = s21_strcmp(test[_i].str1, test[_i].str2);
  if (i == -1 || i == 1) {
    if (j < 0)
      j = -1;
    else if (j > 0)
      j = 1;
  }
  ck_assert_int_eq(i, j);
}
END_TEST

// strncmp
START_TEST(strncmp_test) {
  int i = 0, j = 0;
  i = strncmp(test[_i].str1, test[_i].str2, test[_i].n);
  j = s21_strncmp(test[_i].str1, test[_i].str2, test[_i].n);
  if (i == -1 || i == 1) {
    if (j < 0)
      j = -1;
    else if (j > 0)
      j = 1;
  }
  ck_assert_int_eq(i, j);
}
END_TEST

// strcpy
START_TEST(strcpy_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  strcpy(str1, test[_i].str1);
  strcpy(str2, test[_i].str1);
  ck_assert_pstr_eq(strcpy(str1, test[_i].str2),
                    s21_strcpy(str2, test[_i].str2));
}
END_TEST

// strncpy
START_TEST(strncpy_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  strcpy(str1, test[_i].str1);
  strcpy(str2, test[_i].str1);
  ck_assert_pstr_eq(strncpy(str1, test[_i].str2, test[_i].n),
                    s21_strncpy(str2, test[_i].str2, test[_i].n));
}
END_TEST

// strcspn
START_TEST(strcspn_test) {
  ck_assert_int_eq(strcspn(test[_i].str1, test[_i].str2),
                   s21_strcspn(test[_i].str1, test[_i].str2));
}
END_TEST

// strerror
START_TEST(strerror_test) {
  ck_assert_pstr_eq(strerror(test[_i].n), s21_strerror(test[_i].n));
}
END_TEST

// strlen
START_TEST(strlen_test) {
  ck_assert_int_eq(strlen(test[_i].str1), s21_strlen(test[_i].str1));
}
END_TEST

// strpbrk
START_TEST(strpbrk_test) {
  ck_assert_pstr_eq(strpbrk(test[_i].str1, test[_i].str2),
                    s21_strpbrk(test[_i].str1, test[_i].str2));
}
END_TEST

// strrchr
START_TEST(strrchr_test) {
  ck_assert_pstr_eq(strrchr(test[_i].str1, test[_i].c),
                    s21_strrchr(test[_i].str1, test[_i].c));
}
END_TEST

// strspn
START_TEST(strspn_test) {
  ck_assert_int_eq(strspn(test[_i].str1, test[_i].str2),
                   s21_strspn(test[_i].str1, test[_i].str2));
}
END_TEST

// strstr
START_TEST(strstr_test) {
  ck_assert_pstr_eq(strstr(test[_i].str1, test[_i].str2),
                    s21_strstr(test[_i].str1, test[_i].str2));
}
END_TEST

// strtok
START_TEST(strtok_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  strcpy(str1, test[_i].str1);
  strcpy(str2, test[_i].str1);
  ck_assert_pstr_eq(strtok(str1, test[_i].str2),
                    s21_strtok(str2, test[_i].str2));
}
END_TEST

// to_upper
START_TEST(to_upper_test) {
  char* s = NULL;
  if (test[_i].str1 != NULL) {
    char str1[SIZE] = "";
    char str2[SIZE] = "";
    strcpy(str1, test[_i].str1);
    strcpy(str2, test[_i].str1);
    for (size_t i = 0; i < strlen(test[_i].str1); i++) {
      str2[i] = toupper(str2[i]);
    }
    s = s21_to_upper(str1);
    ck_assert_pstr_eq(str2, s);
  } else {
    s = s21_to_upper(test[_i].str1);
    ck_assert_pstr_eq(NULL, s);
  }
  if (s) free(s);
}
END_TEST

// to_lower
START_TEST(to_lower_test) {
  char* s = NULL;
  if (test[_i].str1 != NULL) {
    char str1[SIZE] = "";
    char str2[SIZE] = "";
    strcpy(str1, test[_i].str1);
    strcpy(str2, test[_i].str1);
    for (size_t i = 0; i < strlen(test[_i].str1); i++) {
      str2[i] = tolower(str2[i]);
    }
    s = s21_to_lower(str1);
    ck_assert_pstr_eq(str2, s);
  } else {
    s = s21_to_lower(test[_i].str1);
    ck_assert_pstr_eq(NULL, s);
  }
  if (s) free(s);
}
END_TEST

// Verter completed insert
void* verter_insert(const char* src, const char* str, s21_size_t start_index) {
  char* dest = s21_NULL;
  if (src && str && s21_strlen(src) >= start_index) {
    dest =
        (char*)malloc((s21_strlen(src) + s21_strlen(str) + 1) * sizeof(char));
    if (dest) {
      s21_strncpy(dest, src, start_index);
      *(dest + start_index) = '\0';
      s21_strcat(dest, str);
      s21_strcat(dest, src + start_index);
    }
  }
  return dest;
}

// insert
START_TEST(insert_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  char str3[SIZE] = "";
  char str4[SIZE] = "";
  char* s_s21 = NULL;
  char* s_verter = NULL;

  // Copy strings from test case
  strcpy(str2, test[_i].str2);
  strcpy(str1, test[_i].str1);
  strcpy(str3, test[_i].str1);
  strcpy(str4, test[_i].str2);

  // Test s21_insert
  if ((size_t)test[_i].n < strlen(str1)) {
    char res[SIZE] = "";
    strncpy(res, str1, test[_i].n);
    strcat(res, str2);
    size_t j = 0;
    char res1[SIZE] = "";
    for (size_t i = test[_i].n; i < strlen(str1); i++) {
      res1[j] = str1[i];
      j++;
    }
    strcat(res, res1);
    s_s21 = s21_insert(str3, str4, test[_i].n);
    ck_assert_pstr_eq(res, s_s21);
  } else {
    s_s21 = s21_insert(str3, str4, test[_i].n);
    ck_assert_pstr_eq(NULL, s_s21);
  }

  // Test verter_insert
  if ((size_t)test[_i].n < strlen(str1)) {
    char res[SIZE] = "";
    strncpy(res, str1, test[_i].n);
    strcat(res, str2);
    size_t j = 0;
    char res1[SIZE] = "";
    for (size_t i = test[_i].n; i < strlen(str1); i++) {
      res1[j] = str1[i];
      j++;
    }
    strcat(res, res1);
    s_verter = verter_insert(str3, str4, test[_i].n);
    ck_assert_pstr_eq(res, s_verter);
  } else {
    s_verter = verter_insert(str3, str4, test[_i].n);
    ck_assert_pstr_eq(NULL, s_verter);
  }

  // Check that both functions return the same result
  ck_assert_pstr_eq(s_s21, s_verter);

  // Free allocated memory
  if (s_s21) free(s_s21);
  if (s_verter) free(s_verter);
}
END_TEST

size_t reverser(char* src, char* pat, char* res) {
  size_t n = strspn(src, pat);
  size_t j = 0;
  for (size_t i = n; i < strlen(src); i++) {
    res[j] = src[i];
    j++;
  }
  res[j] = '\0';
  size_t size = strlen(src) - n;
  size_t i = 0;
  j = strlen(src) - n - 1;
  for (i = 0; i < size / 2; i++) {
    char c = res[i];
    res[i] = res[j];
    res[j] = c;
    j--;
  }
  res[size] = '\0';
  return n;
}

void* verter_trim(const char* src, const char* trim_chars) {
  char* res = s21_NULL;
  if (src && trim_chars) {
    char* new_str = s21_NULL;
    char* ptr_str = (char*)src;
    char* end_str = (char*)src + s21_strlen(src);
    for (; *ptr_str && s21_strchr(trim_chars, *ptr_str); ptr_str++) {
    }
    for (; end_str != ptr_str && s21_strchr(trim_chars, *(end_str - 1));
         end_str--) {
    }
    new_str = (char*)malloc((end_str - ptr_str + 1) * sizeof(char));
    if (new_str) {
      s21_strncpy(new_str, ptr_str, end_str - ptr_str);
      *(new_str + (end_str - ptr_str)) = '\0';
    }
    res = (void*)new_str;
  }
  if (!trim_chars && src) {
    res = malloc(s21_strlen(src) + 1);
    s21_strcpy(res, src);
  }
  return res;
}

// trim
START_TEST(trim_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  void* s = s21_NULL;
  strcpy(str1, test[_i].str1);
  strcpy(str2, test[_i].str2);
  if (test[_i].str1 != s21_NULL && test[_i].str2 != s21_NULL) {
    char res1[SIZE] = "";
    size_t count1 = (size_t)s21_trim(str1, str2);
    char res2[SIZE] = "";
    size_t count2 = (size_t)verter_trim(str1, str2);
    if (count1 + count2 != 0)
      ck_assert_pstr_eq(res1, res2);
    else
      ck_assert_ptr_null(res2);
  } else {
    s = verter_trim(str1, str2);
    ck_assert_ptr_null(s);
  }
  if (s) free(s);
}
END_TEST

// sprintf
START_TEST(sprintf_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  sprintf(str1, "Value of Pi = %f", 3.1419);
  s21_sprintf(str2, "Value of Pi = %f", 3.1419);
  ck_assert_pstr_eq(str1, str2);
  sprintf(str1, "%f", 0.2);
  s21_sprintf(str2, "%f", 0.2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_extra_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  int var = 0;
  unsigned int i = 0, j = 0;
  double f1 = 0, f2 = 0;
  s21_sprintf(
      str1,
      "Takaya shtuka: -#o %% Float %0.1f Int %+i Exp %20e Hex %#X Oct %lo\n"
      "String %s Char %c Pointer %p Length %n %% Unsigned %u Double %g",
      -4.44, -300, 0.0, 718, 10434534534, "zepi", 6, &var, &var, i, f1);
  sprintf(str2,
          "Takaya shtuka: -#o %% Float %0.1f Int %+i Exp %20e Hex %#X Oct %lo\n"
          "String %s Char %c Pointer %p Length %n %% Unsigned %u Double %g",
          -4.44, -300, 0.0, 718, 10434534534, "zepi", 6, &var, &var, j, f2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// sscanf
START_TEST(sscanf_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  int i = 0, j = 0, ni = 0, nj = 0;
  long int li = 0, lj = 0;
  short int si = 0, sj = 0;
  unsigned short int ho1 = 0, ho2 = 0;
  unsigned long int lu1, lu2;
  unsigned int u1 = 0, u2 = 0;
  sscanf("123", "%ho", &ho1);
  s21_sscanf("123", "%ho", &ho2);
  ck_assert_int_eq(ho1, ho2);

  sscanf("123", "%lo", &lu1);
  s21_sscanf("123", "%lo", &lu2);
  ck_assert_int_eq(lu1, lu2);

  sscanf("023", "%i", &i);
  s21_sscanf("023", "%i", &j);
  ck_assert_int_eq(i, j);

  sscanf("02A6", "%i", &i);
  s21_sscanf("02A6", "%i", &j);
  ck_assert_int_eq(i, j);

  sscanf("-123", "%o", &u1);
  s21_sscanf("-123", "%o", &u2);
  ck_assert_int_eq(u1, u2);

  sscanf("hello 001 2 3 4 5 10000000000", "%s %hd %2d %d %ld %lx %hx", str1,
         &si, &ni, &i, &li, &lu1, &ho1);
  s21_sscanf("hello 001 2 3 4 5 10000000000", "%s %hd %2d %d %ld %lx %hx", str2,
             &sj, &nj, &j, &lj, &lu2, &ho2);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(si, sj);
  ck_assert_int_eq(ni, nj);
  ck_assert_int_eq(li, lj);
  ck_assert_int_eq(lu1, lu2);
  ck_assert_int_eq(ho1, ho2);
}
END_TEST

START_TEST(sscanf_extra_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  int i = 0, j = 0;
  double n = 0, m = 0;
  float e1 = 0, e2 = 0, inf1 = 0, inf2 = 0, e_w = 0, e1_w = 0, f_1 = 0, f_2 = 0;
  char ch = 0, c = 0;
  long double li = 0, lj = 0, li_ = 0, lj_ = 0, l_i = 0, l_j = 0;
  unsigned int u1 = 0, u2 = 0, u_1 = 0, u_2 = 0;
  sscanf("NAN INF", "%f %f", &f_1, &e1);
  s21_sscanf("NAN INF", "%f %f", &f_2, &e2);

  sscanf("NAN INF", "%Lf %Lf", &li, &li);
  s21_sscanf("NAN INF", "%Lf %Lf", &lj, &lj);

  sscanf("-0.1 +0.3", "%f %f", &f_1, &e1);
  s21_sscanf("-0.1 +0.3", "%f %f", &f_2, &e2);
  ck_assert_float_eq(f_1, f_2);
  ck_assert_float_eq(e1, e2);

  sscanf("-9.7656e-05 +9.7656e-05", "%e %e", &f_1, &e1);
  s21_sscanf("-9.7656e-05 +9.7656e-05", "%e %e", &f_2, &e2);
  ck_assert_float_eq(f_1, f_2);
  ck_assert_float_eq(e1, e2);

  sscanf("0x1faf", "%i", &i);
  s21_sscanf("0x1faf", "%i", &j);
  ck_assert_int_eq(i, j);

  sscanf("0.000000001", "%Lf", &li);
  s21_sscanf("0.000000001", "%Lf", &lj);
  ck_assert_double_eq(li, lj);

  sscanf("0.000000001", "%n", &i);
  s21_sscanf("0.000000001", "%n", &j);
  ck_assert_int_eq(i, j);

  sscanf("shrek -0x1 +1 0.05 h 1.0000000001 NAN INF NAN INF 0.003",
         "%s* %X %2X %lf %c %Lf %Lf %Lf %2e %2f %2e+1", str1, &u1, &u_1, &n,
         &ch, &li, &li_, &l_i, &e1, &inf1, &e_w);
  s21_sscanf("shrek -0x1 +1 0.05 h 1.0000000001 NAN INF NAN INF 0.003",
             "%s* %X %2X %lf %c %Lf %Lf %Lf %2e %2f %2e+1", str2, &u2, &u_2, &m,
             &c, &lj, &lj_, &l_j, &e2, &inf2, &e1_w);
  ck_assert_double_eq(n, m);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(u_1, u_2);
  ck_assert_int_eq(ch, c);
  ck_assert_double_eq(li, lj);
  ck_assert_float_eq(e_w, e1_w);
}
END_TEST

START_TEST(sscanf_bonus_test) {
  char str1[SIZE] = "";
  char str2[SIZE] = "";
  int k = 0, l = 0;
  long unsigned int i = 0, j = 0;
  short n = 0, n_ = 0;
  float h = 0, m = 0;
  char *p, *p1;

  sscanf(" \t sdsd", "%p", &p);
  s21_sscanf(" \t sdsd", "%p", &p1);

  sscanf(" \t sdsd % 4 010 0.891", "[ \t]%s %% %lo %i %hn %2f", str1, &i, &k,
         &n, &h);
  s21_sscanf(" \t sdsd % 4 010 0.891", "[ \t]%s %% %lo %i %hn %2f", str2, &j,
             &l, &n_, &m);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_uint_eq(i, j);
  ck_assert_int_eq(k, l);
  ck_assert_int_eq(n, n_);
  ck_assert_float_eq(h, m);
}
END_TEST

TCase* create_tc(size_t index, size_t size) {
  TCase* tc = tcase_create(tcases[index].name);
  tcase_set_timeout(tc, 10);
  add_cases(&tc, index, size);
  return tc;
}

void print_log(double n_checks) {
  FILE* f = fopen("log.xml", "r");
  if (f != NULL) {
    printf("\n");
    size_t len = 0;
    int found_err = 0, found_name = 0, counter = 0;
    double fails = 0;
    char* line = NULL;
    ssize_t read = getline(&line, &len, f);
    char name[SIZE] = "", num[SIZE] = "", prev_name[SIZE] = "";
    while (read != -1) {
      if (!found_err && found_pattern(line, "failure")) found_err = 1;
      if (!found_name && found_err && found_pattern(line, "<id>")) {
        memset(name, 0, sizeof(name));
        for (size_t i = 0; line[i + 10] != '<'; i++) name[i] = line[i + 10];
        found_name = 1;
      }
      if (found_name && found_pattern(line, "<iteration>")) {
        memset(num, 0, sizeof(num));
        for (size_t i = 0; line[i + 17] != '<'; i++) num[i] = line[i + 17];
        int iteration = atoi(num);
        if (strcmp(prev_name, name) != 0) {
          if (counter > MAX_ERRLOG_SIZE)
            printf("----------SEE OTHER %d ERRORS IN LOG-------------\n",
                   counter - MAX_ERRLOG_SIZE);
          counter = 0;
        }
        if (!is_special(name)) print_error(name, iteration, counter);
        memset(prev_name, 0, sizeof(prev_name));
        strcpy(prev_name, name);
        counter++;
        fails++;
        found_err = 0;
        found_name = 0;
      }
      read = getline(&line, &len, f);
    }
    if (counter > MAX_ERRLOG_SIZE)
      printf("----------SEE OTHER %d ERRORS IN LOG-------------\n",
             counter - MAX_ERRLOG_SIZE);
    double perc = 100 - ((fails * 100) / n_checks);
    printf("%lf%c checks: %d, failures: %d", perc, 37, (int)n_checks,
           (int)fails);
    if (line) free(line);
    fclose(f);
  }
}

int is_special(char name[SIZE]) {
  size_t size = sizeof(special_test) / sizeof(special_test[0]);
  int isSpecial = 0;
  for (size_t i = 0; i < size; i++) {
    if (strcmp(special_test[i].name, name) == 0) {
      printf("-------------------------------------------------\n");
      printf("FAILED %s\n", name);
      isSpecial = 1;
    }
  }
  return isSpecial;
}

void print_error(char name_test[SIZE], int index, int counter) {
  if (counter <= MAX_ERRLOG_SIZE) {
    printf("-------------------------------------------------\n");
    printf("FAILED %s №%d:", name_test, index);
    printf("\t{ |%s|, |%s|, |%d|, |%d| }\n", test[index].str1, test[index].str2,
           test[index].c, test[index].n);
  } else {
    printf("''''''''''''''''''''''''''''''''''''''''''''''''\n");
    printf("failed %s №%d:", name_test, index);
    printf("\t/'%s', '%s', '%d', '%d'/\n", test[index].str1, test[index].str2,
           test[index].c, test[index].n);
  }
}

int found_pattern(char* line, char* pattern) {
  int res = 0;
  regex_t regex = {};
  regmatch_t pmatch[1] = {};
  regcomp(&regex, pattern, REG_NEWLINE);
  if (regexec(&regex, line, 1, pmatch, 0) == 0) {
    res = 1;
  }
  regfree(&regex);
  return res;
}

void add_cases(TCase** tc, size_t index, size_t size) {
  switch (index) {
    case 0:
      tcase_add_loop_test(*tc, memchr_test, 0, size);
      break;
    case 1:
      tcase_add_loop_test(*tc, memcmp_test, 0, size);
      break;
    case 2:
      tcase_add_loop_test(*tc, memcpy_test, 0, size);
      break;
    case 3:
      tcase_add_loop_test(*tc, memset_test, 0, size);
      break;
    case 4:
      tcase_add_loop_test(*tc, memmove_test, 0, size);
      break;
    case 5:
      tcase_add_loop_test(*tc, strcat_test, 0, size);
      break;
    case 6:
      tcase_add_loop_test(*tc, strncat_test, 0, size);
      break;
    case 7:
      tcase_add_loop_test(*tc, strchr_test, 0, size);
      break;
    case 8:
      tcase_add_loop_test(*tc, strcmp_test, 0, size);
      break;
    case 9:
      tcase_add_loop_test(*tc, strncmp_test, 0, size);
      break;
    case 10:
      tcase_add_loop_test(*tc, strcpy_test, 0, size);
      break;
    case 11:
      tcase_add_loop_test(*tc, strncpy_test, 0, size);
      break;
    case 12:
      tcase_add_loop_test(*tc, strcspn_test, 0, size);
      break;
    case 13:
      tcase_add_loop_test(*tc, strerror_test, 0, size);
      break;
    case 14:
      tcase_add_loop_test(*tc, strlen_test, 0, size);
      break;
    case 15:
      tcase_add_loop_test(*tc, strpbrk_test, 0, size);
      break;
    case 16:
      tcase_add_loop_test(*tc, strrchr_test, 0, size);
      break;
    case 17:
      tcase_add_loop_test(*tc, strstr_test, 0, size);
      break;
    case 18:
      tcase_add_loop_test(*tc, strtok_test, 0, size);
      break;
    case 19:
      tcase_add_loop_test(*tc, strspn_test, 0, size);
      break;
    case 20:
      tcase_add_loop_test(*tc, to_upper_test, 0, size);
      break;
    case 21:
      tcase_add_loop_test(*tc, to_lower_test, 0, size);
      break;
    case 22:
      tcase_add_loop_test(*tc, insert_test, 0, size);
      break;
    case 23:
      tcase_add_loop_test(*tc, trim_test, 0, size);
      break;
    case 24:
      tcase_add_test(*tc, sscanf_test);
      tcase_add_test(*tc, sscanf_extra_test);
      tcase_add_test(*tc, sscanf_bonus_test);
      break;
    case 25:
      tcase_add_test(*tc, sprintf_test);
      tcase_add_test(*tc, sprintf_extra_test);
      break;
    default:
      break;
  }
}

Suite* create_str_suite(size_t size_) {
  Suite* str_suite = suite_create("s21_string_test_suite");
  size_t size = sizeof(tcases) / sizeof(tcases[0]);
  for (size_t i = 0; i < size; i++) {
    TCase* tc = create_tc(i, size_);
    suite_add_tcase(str_suite, tc);
  }
  return str_suite;
}

list* add_elem(list* elem, char* str1) {
  struct list* tmp = (list*)malloc(sizeof(list));
  tmp->str1 = str1;
  if (elem == NULL) {
    tmp->next = NULL;
    elem = tmp;
  } else {
    list* p = elem;
    while (p->next != NULL) p = p->next;
    p->next = tmp;
    tmp->next = NULL;
  }
  return elem;
}

void destroy(list* root) {
  while (root != NULL) {
    list* p = root;
    root = root->next;
    free(p->str1);
    free(p);
  }
}

size_t set_test(char* filename, list** tmp) {
  size_t size = START_STRUCT_SIZE;
  *tmp = set_params(filename, *tmp);
  FILE* f = fopen(filename, "rb");
  if (f != NULL) {
    size_t len = 0;
    char* line = NULL;
    ssize_t read = getline(&line, &len, f);
    while (read != -1) {
      list* p = *tmp;
      while (p != NULL) {
        for (int i = MIN_C; i <= MAX_C; i++) {
          for (int j = MIN_N; j <= MAX_N; j++) {
            char* buf = strdup(line);
            char* buf1 = strdup(p->str1);
            test[size] = (struct test_struct){buf, buf1, i, j};
            size++;
          }
        }
        p = p->next;
      }
      read = getline(&line, &len, f);
    }
    if (line) free(line);
    fclose(f);
  }
  return size;
}

list* set_params(char* filename, list* tmp) {
  FILE* f = fopen(filename, "rb");
  if (f != NULL) {
    size_t len = 0;
    char* line = NULL;
    ssize_t read = getline(&line, &len, f);
    while (read != -1) {
      char* buf = strdup(line);
      tmp = add_elem(tmp, buf);
      read = getline(&line, &len, f);
    }
    if (line) free(line);
    fclose(f);
  }
  return tmp;
}

void printAllCases(size_t size) {
  printf("Cases\n");
  for (size_t i = 0; i < size; i++) {
    printf("case %d: [%s],[%s],[%d],[%d]\n", (int)i, test[i].str1, test[i].str2,
           test[i].c, test[i].n);
    printf("::::::::::::::::::::::::::::::::::\n");
  }
  printf("\n");
}

int main(void) {
  list* tmp = NULL;
  size_t size = START_STRUCT_SIZE;
  size = set_test(FILENAME, &tmp);
  printAllCases(size);
  Suite* str_suite = create_str_suite(size - 1);
  SRunner* suite_runner = srunner_create(str_suite);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_set_xml(suite_runner, "log.xml");
  srunner_run_all(suite_runner, CK_NORMAL);
  srunner_ntests_failed(suite_runner);
  double N = (TC_STRUCT_SIZE * (double)size) + EXTRA_TESTS_COUNT;
  print_log(N);
  srunner_free(suite_runner);
  destroy(tmp);
  return EXIT_SUCCESS;
}
