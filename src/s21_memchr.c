#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *temp_str = (char *)str;

  while (n--) {
    if (*temp_str == (unsigned char)c) {
      return (void *)temp_str;
    }
    temp_str++;
  }

  return s21_NULL;
}