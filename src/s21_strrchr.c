#include "s21_string.h"

// find the last occurrence of a character in a string
char *s21_strrchr(const char *str, int c) {
  const char *temp_str = s21_NULL;
  while (*str != '\0') {
    if (*str == (char)c) {
      temp_str = str;
    }
    str++;
  }
  if ((char)c == '\0') {
    return (char *)str;
  }
  return (char *)temp_str;
}