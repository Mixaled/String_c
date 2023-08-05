#include "s21_sprintf.h"

int s21_sprintf(char* buff, const char* format, ...) {
  va_list args;
  va_start(args, format);
  char* pointerToSpec = s21_NULL;
  s21_strcpy(buff, format);
  strchr_help(buff, '%');
  pointerToSpec = s21_strstr((char*)format, "%");
  char* temp = malloc(4096);
  int counterForReturn = 0;
  while (pointerToSpec) {
    Specificator spec = parseSpecificator(&pointerToSpec);
    parseAdditionalArguments(&spec, args);
    formatPrint(buff, spec, args);
    s21_strcpy(temp, pointerToSpec);
    strchr_help(temp, '%');
    s21_strcat(buff, temp);
    if (s21_strlen(pointerToSpec) == 1 && pointerToSpec[0] == '%')
      pointerToSpec = s21_NULL;
    else
      pointerToSpec = s21_strchr(pointerToSpec, '%');
    if (spec.type) counterForReturn++;
  }
  va_end(args);
  free(temp);
  return counterForReturn;
}

void formatPrint(char* buff, Specificator spec, va_list args) {
  char src[MAXLINE];
  char* alloc_str = s21_NULL;
  char* static_string = s21_NULL;
  wint_t wide_src[MAXLINE];
  wchar_t* wide_static_string = s21_NULL;
  long long num;
  long double floatNum;
  int* p;
  switch (spec.type) {
    case 'c':
      if (spec.length == 'l') {
        wide_src[0] = va_arg(args, wint_t);
        wide_src[1] = '\0';
        strcat_with_spec(buff, (char*)wide_src, spec);
      } else {
        src[0] = va_arg(args, int);
        src[1] = '\0';
        strcat_with_spec(buff, src, spec);
      }
      break;
    case 's':
      if (spec.length == 'l') {
        wide_static_string = va_arg(args, wchar_t*);
        strcat_with_spec(buff, (char*)wide_static_string, spec);
      } else {
        static_string = va_arg(args, char*);
        strcat_with_spec(buff, static_string, spec);
      }
      break;
    case 'i':
    case 'd':
      num = spec.length == 'l' ? va_arg(args, long) : va_arg(args, int);
      itoa(num, src, spec);
      strcat_with_spec(buff, src, spec);
      break;
    case 'u':
      num = spec.length == 'l' ? va_arg(args, unsigned long)
                               : va_arg(args, unsigned int);
      itoa(num, src, spec);
      strcat_with_spec(buff, src, spec);
      break;
    case 'o':
    case 'x':
      num = spec.length == 'l' ? va_arg(args, long) : va_arg(args, int);
      itoa(num, src, spec);
      strcat_with_spec(buff, src, spec);
      break;
    case 'X':
      num = spec.length == 'l' ? va_arg(args, long) : va_arg(args, int);
      itoa(num, src, spec);
      alloc_str = s21_to_upper(src);
      strcat_with_spec(buff, alloc_str, spec);
      free(alloc_str);
      break;
    case 'f':
      floatNum =
          spec.length == 'L' ? va_arg(args, long double) : va_arg(args, double);
      trimDouble(floatNum, src, spec);
      strcat_with_spec(buff, src, spec);
      break;
    case 'e':
    case 'E':
      floatNum =
          spec.length == 'L' ? va_arg(args, long double) : va_arg(args, double);
      trimE(floatNum, src, spec);
      strcat_with_spec(buff, src, spec);
      break;
    case 'g':
    case 'G':
      floatNum =
          spec.length == 'L' ? va_arg(args, long double) : va_arg(args, double);
      g_cut_converter(floatNum, src, spec);
      strcat_with_spec(buff, src, spec);
      break;
    case 'p':
      p = va_arg(args, int*);
      spec.flag_hash = true;
      itoa((long long)p, src, spec);
      strcat_with_spec(buff, src, spec);
      break;
    case 'n':
      p = va_arg(args, int*);
      *p = s21_strlen(buff);
      break;
    case '%':
      src[0] = '%';
      src[1] = '\0';
      strcat_with_spec(buff, src, spec);
      break;
  }
}

void strcat_with_spec(char* buff, char* src, Specificator spec) {
  int length = s21_strlen(src);
  char* temp = malloc(length * 2 + 1);
  if (is_digit(spec.type) && src[0] != '-') {
    if (spec.flag_space && !spec.flag_plus) {
      s21_strcpy(temp, " ");
      s21_strcat(temp, src);
      length++;
    } else if (spec.flag_plus) {
      s21_strcpy(temp, "+");
      s21_strcat(temp, src);
      length++;
    } else {
      s21_strcpy(temp, src);
    }
  } else {
    s21_strcpy(temp, src);
  }
  if (spec.flag_minus) {
    s21_strcat(buff, temp);
    while (spec.width - length > 0) {
      s21_strcat(buff, " ");
      length++;
    }
  }
  if (!spec.flag_minus) {
    while (spec.width - length > 0) {
      spec.flag_zero ? s21_strcat(buff, "0") : s21_strcat(buff, " ");
      length++;
    }
    s21_strcat(buff, temp);
  }
  free(temp);
}

bool is_digit(char type) {
  bool digit = false;
  if (type == 'd' || type == 'i' || type == 'e' || type == 'E' || type == 'f' ||
      type == 'g' || type == 'G' || type == 'o' || type == 'x' || type == 'X' ||
      type == 'u')
    digit = true;
  return digit;
}

void itoa(long long num, char* src, Specificator spec) {
  int i = 0, j = 0;
  int digit;
  int radix;
  int flag_minus = (num < 0) ? 1 : 0;
  if (flag_minus) num = -num;
  if (num == 0) src[j++] = 48;
  if (spec.type == 'o')
    radix = 8;
  else if (spec.type == 'x' || spec.type == 'X' || spec.type == 'p')
    radix = 16;
  else
    radix = 10;
  while (num >= pow(radix, i)) {
    digit = (long long)(num / pow(radix, i++)) % radix;
    src[j++] =
        (digit >= 0 && digit <= 9) ? (char)(digit + 48) : (char)(digit + 87);
  }
  if (spec.flag_hash) {
    src[j++] = 'x';
    src[j++] = '0';
  }
  if (flag_minus) src[j++] = '-';
  src[j] = '\0';
  reverse(src);
}

void reverse(char* string) {
  char temp[MAXLINE];
  s21_strcpy(temp, string);
  int length = s21_strlen(string);
  int i;
  for (i = 0; i < length; i++) string[i] = temp[length - i - 1];
  string[i] = '\0';
}

void trimE(double inputDouble, char* buf, Specificator spec) {
  char temp;
  int e_counter = 0;
  if (inputDouble < 1 && inputDouble > -1 && inputDouble != 0) {
    inputDouble = inputDouble * 10;
    e_counter--;
  }
  trimDouble(inputDouble, buf, spec);
  char* dot_pointer = s21_strchr(buf, '.');
  int len = s21_strlen(buf);
  if (!dot_pointer) dot_pointer = buf + len;
  while ((inputDouble > 0 && dot_pointer - buf != 1) ||
         (inputDouble < 0 && dot_pointer - buf != 2)) {
    temp = *(dot_pointer - 1);
    *(dot_pointer - 1) = '.';
    *dot_pointer = temp;
    dot_pointer--;
    e_counter++;
  }
  int position = spec.precision == 0 ? spec.precision + 1 : spec.precision + 2;
  if (buf[0] == '-') position++;
  buf[position++] = spec.type == 'e' || spec.type == 'g' ? 'e' : 'E';
  buf[position++] = e_counter >= 0 ? '+' : '-';
  if (e_counter < 0) e_counter = -e_counter;
  buf[position++] = e_counter / 10 + 48;
  buf[position++] = e_counter % 10 + 48;
  buf[position] = '\0';
}

void trimDouble(double inputDouble, char* buf, Specificator spec) {
  char rightPartStr[1024] = {0};
  char leftPartStr[1024] = {0};
  double leftPartDouble;
  double rightPart = modf(inputDouble, &leftPartDouble);

  ourGcvt((long double)rightPart, rightPartStr, spec);

  itoa((long long)leftPartDouble, leftPartStr, spec);
  int lIdx = s21_strlen(leftPartStr) + 1;
  int rIdx = rightPartStr[0] == '-' ? 3 : 2;

  if (rightPartStr[rIdx] != '\0') {
    leftPartStr[s21_strlen(leftPartStr)] = '.';
    while (rightPartStr[rIdx] != '\0') {
      leftPartStr[lIdx] = rightPartStr[rIdx];
      lIdx++;
      rIdx++;
    }
  }
  s21_strcpy(buf, leftPartStr);
}

void ourGcvt(long double value, char* buf, Specificator spec) {
  long double localValue = value;
  bool isNegative = false;
  if (value < 0) {
    isNegative = true;
    localValue = localValue * -1;
  }
  long long leftPartInt = localValue;
  char* leftPartStr = calloc(1024, sizeof(char));
  long double leftPartDouble = leftPartInt;
  long double rightPartDouble = localValue - leftPartDouble;
  bool firstOneAdded = false;
  char* finalStr = calloc(1024, sizeof(char));
  if (leftPartInt != 0) {
    itoa(leftPartInt, leftPartStr, spec);
  } else {
    leftPartStr[0] = '0';
  }
  if ((rightPartDouble - 0.1) < 0) {
    rightPartDouble += 0.1;
    firstOneAdded = true;
  } else {
    // do nothing
  }
  char leftPartChunk[1024] = {0};
  char finalRightPart[1024] = {0};
  bool whileBreak = false;
  int rightPartIntTemp = 0;
  int i = 0;
  while (i < 15 && whileBreak == false) {
    rightPartDouble = rightPartDouble - (long double)rightPartIntTemp;
    rightPartDouble = rightPartDouble * 10;
    rightPartIntTemp = rightPartDouble;
    itoa(rightPartIntTemp, leftPartChunk, spec);
    if (s21_strcmp(leftPartChunk, "") == 0) {
      s21_strcat(finalRightPart, "0");
    } else {
      s21_strcat(finalRightPart, leftPartChunk);
    }
    i++;
  }
  if (finalRightPart[spec.precision] >= '5' &&
      finalRightPart[spec.precision + 1] <= '9') {
    finalRightPart[spec.precision] = '\0';
    int lenBefore = s21_strlen(finalRightPart);
    long long rightRounded = atoll(finalRightPart) + 1;
    itoa(rightRounded, finalRightPart, spec);
    int lenAfter = s21_strlen(finalRightPart);
    if (lenAfter > lenBefore) {
      s21_strcpy(finalRightPart, (char*)finalRightPart + 1);
      long long leftRounded = atoll(leftPartStr) + 1;
      itoa(leftRounded, leftPartStr, spec);
    }
  }
  if (firstOneAdded) finalRightPart[0] = '0';
  finalRightPart[spec.precision] = '\0';
  if (isNegative) {
    if (zeroOs(leftPartStr) && zeroOs(finalRightPart)) {
      // do nothing
    } else {
      s21_strcat(finalStr, "-");
    }
  }
  s21_strcat(finalStr, leftPartStr);
  if (spec.precision != 0) s21_strcat(finalStr, ".");
  s21_strcat(finalStr, finalRightPart);
  s21_strcpy(buf, finalStr);
  free(leftPartStr);
  free(finalStr);
}

int zeroOs(char* str) {
  int result = 1;
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] != '0') {
      result = 0;
      break;
    }
    i++;
  }
  return result;
}

void g_cut_converter(double floatNum, char* buf, Specificator spec) {
  bool e_format =
      floatNum < 0.0001 || floatNum >= pow(10, spec.precision) ? true : false;

  if (e_format) {
    trimE(floatNum, buf, spec);
    char* e_position = s21_strchr(buf, 'e');
    if (*(e_position + 2) == '0' && *(e_position + 3) == '0')
      *e_position = '\0';
    char* digit_pointer = e_position - 1;
    while ((*digit_pointer == '0' || *digit_pointer == '.') &&
           digit_pointer != buf) {
      *digit_pointer = '\0';
      digit_pointer--;
    }
    s21_strcat(buf, e_position);
  } else {
    trimDouble(floatNum, buf, spec);
    int last_digit_position = s21_strlen(buf) - 1;
    while (
        (buf[last_digit_position] == '0' || buf[last_digit_position] == '.') &&
        last_digit_position != 0)
      buf[last_digit_position--] = '\0';
  }
}

Specificator parseSpecificator(char** pointerToSpec) {
  Specificator spec = {0, 6, 0, 0, 0, 0, 0, 0, 0, 0};
  char allspec[] = "cdieEfgGosuxXpn";
  char allnumb[] = "1234567890";
  char alllength[] = "Llh";
  char* width_temp = calloc(s21_strlen(*pointerToSpec) + 1, sizeof(char));
  int count = 0;
  char* str = *pointerToSpec;
  if (s21_strcmp(str, OUR_ERROR_) != 0) {
    s21_size_t i = 0;
    for (; i < s21_strlen(str);) {
      if (s21_strchr("-", str[i]) != s21_NULL) {
        spec.flag_minus = 1;
        i++;
      } else if (str[i] == '+') {
        spec.flag_plus = 1;
        spec.flag_space = 0;
        i++;
      } else if (str[i] == ' ' && !spec.flag_plus) {
        spec.flag_space = 1;
        i++;
      } else if (str[i] == '0' && spec.width == 0) {
        spec.flag_zero = 1;
        i++;
      } else if (str[i] == '#') {
        spec.flag_hash = 1;
        i++;
      } else if (s21_strchr(allnumb, str[i])) {
        strcpy_help(width_temp, str, i);
        while (s21_strchr(allnumb, width_temp[count]) &&
               width_temp[count] != '.') {
          count++;
        }
        width_temp[count] = '\0';
        spec.width = atoi(width_temp);
        i += s21_strlen(width_temp);
      } else if (str[i] == '*') {
        spec.width = -1;
        i++;
      } else if (str[i] == '.') {
        strcpy_help(width_temp, str, i + 1);
        count = 0;
        while (s21_strchr(allnumb, width_temp[count])) {
          count++;
        }
        if (width_temp[0] == '*') {
          spec.precision = -1;
          i += 2;
        } else {
          width_temp[count] = '\0';
          spec.precision = atoi(width_temp);
          i += s21_strlen(width_temp) + 1;
        }
      } else if (s21_strchr(alllength, str[i])) {
        spec.length = str[i];
        i++;
      } else if (s21_strchr(allspec, str[i])) {
        spec.type = str[i];
        i++;
        break;
      } else if (str[i] == '%' && s21_strlen(str) >= i + 1 &&
                 str[i + 1] == '%') {
        spec.type = str[i];
        i += 2;
        break;
      } else {
        i++;
      }
    }
    if (spec.type == 0) {
      spec.flag_noargumet = 1;
    }

    *pointerToSpec += i;
  }
  if (width_temp) free(width_temp);
  return spec;
}

void strcpy_help(char* str1, char* str2, int index) {
  s21_size_t i = 0;
  for (; i < s21_strlen(str2); i++) {
    if ((s21_size_t)index <= i) {
      str1[i - index] = str2[i];
    }
  }
  str1[i - index + 1] = '\0';
}

void strchr_help(char* str1, char s) {
  s21_size_t i = 0;
  for (; i < s21_strlen(str1); i++) {
    if (str1[i] == s) {
      str1[i] = '\0';
    }
  }
}

void parseAdditionalArguments(Specificator* spec, va_list args) {
  if (spec->width == -1) spec->width = va_arg(args, int);
  if (spec->precision == -1) spec->precision = va_arg(args, int);
}
