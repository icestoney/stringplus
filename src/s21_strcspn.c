#include "s21_string.h"

// calculate the length of the initial substring of @str1 which does not contain
// letters in @str2
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *temp_str1 = str1;

  while (*temp_str1 != '\0') {
    const char *temp_str2 = str2;
    while (*temp_str2 != '\0') {
      if (*temp_str1 == *temp_str2) {
        return temp_str1 - str1;
      }
      temp_str2++;
    }
    temp_str1++;
  }

  return (s21_size_t)(temp_str1 - str1);
}