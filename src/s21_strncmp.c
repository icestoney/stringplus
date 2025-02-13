#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  const unsigned char *temp_str1 = (unsigned char *)str1;
  const unsigned char *temp_str2 = (unsigned char *)str2;

  while (n--) {
    if (*temp_str1 != *temp_str2) {
      return (int)(*temp_str1 - *temp_str2);
    }
    temp_str1++;
    temp_str2++;
  }

  return 0;
}