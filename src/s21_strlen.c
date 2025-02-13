#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  const char *temp_str = str;

  while (*temp_str != '\0') {
    temp_str++;
  }

  return (s21_size_t)(temp_str - str);
}