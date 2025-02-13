#include "s21_string.h"

// find the first occurrence of a character in a string
char *s21_strchr(const char *str, int c) {
  while (*str != (unsigned char)c) {
    if (*str == '\0') {
      return s21_NULL;
    }
    str++;
  }

  return (char *)str;
}