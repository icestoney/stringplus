#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *temp_str = str;

  while (n--) {
    *temp_str++ = (unsigned char)c;
  }

  return (void *)str;
}