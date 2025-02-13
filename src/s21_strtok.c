#include "s21_string.h"

s21_size_t s21_strspn(const char *str, const char *accept);

char *s21_strtok(char *str, const char *delim) {
  static char *last = {0};
  if (str == s21_NULL) {
    str = last;
  }

  /* Scan leading delimiters.  */
  str += s21_strspn(str, delim);

  /* if *str points to the null byte \0, that means
          we have reached the end of the string and
          we return NULL */
  if (*str == '\0') {
    last = str;
    return s21_NULL;
  }

  /* Find the end of the token.  */
  char *token = str;
  str = s21_strpbrk(token, delim);
  if (str == s21_NULL) {
    /* This token finishes the string.  */
    last = s21_strchr(token, '\0');
  } else {
    /* Terminate the token and make OLDS point past it.  */
    *str = '\0';
    last = str + 1;
  }

  return (char *)token;
}

s21_size_t s21_strspn(const char *str, const char *accept) {
  const char *temp_str = str;
  const char *temp_accept = s21_NULL;
  s21_size_t counter = 0;

  while (*temp_str != '\0') {
    temp_accept = accept;
    while (*temp_accept != '\0') {
      if (*temp_str == *temp_accept) {
        counter++;
        break;
      }
      temp_accept++;
    }
    if (*temp_accept == '\0') {
      break;
    }
    temp_str++;
  }

  return counter;
}