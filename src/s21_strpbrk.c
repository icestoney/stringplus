#include "s21_string.h"

// find the first occurrence of a set of characters
char *s21_strpbrk(const char *str1, const char *str2) {
  while (*str1 != '\0') {
    const char *temp_str2 = str2;
    while (*temp_str2 != '\0') {
      if (*str1 == *temp_str2) {
        return (char *)str1;
      }
      temp_str2++;
    }
    str1++;
  }
  return s21_NULL;
}