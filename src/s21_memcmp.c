#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *temp_str1 = str1;
  const char *temp_str2 = str2;

  while (n--) {
    if (*temp_str1 != *temp_str2) {
      return (int)(*temp_str1 - *temp_str2);
    }
    temp_str1++;
    temp_str2++;
  }

  return 0;
}