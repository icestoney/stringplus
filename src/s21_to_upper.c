#include "s21_string.h"

void *s21_to_upper(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }

  s21_size_t len = s21_strlen(str);
  char *new_str = (char *)calloc(len + 1, sizeof(char));
  if (new_str == s21_NULL) {
    return s21_NULL;
  }

  char *temp_new_str = new_str;
  while (len--) {
    if (*str < 'a' || *str > 'z') {
      *new_str++ = *str++;
    } else {
      *new_str++ = *str++ - 32;
    }
  }
  *new_str = '\0';

  return (void *)temp_new_str;
}