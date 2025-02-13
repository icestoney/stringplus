#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t src_len = s21_strlen(src);
  if (start_index > src_len) {
    return s21_NULL;
  }
  s21_size_t str_len = s21_strlen(str);
  s21_size_t summary_len = src_len + str_len;

  char *new_str = (char *)calloc(summary_len + 1, sizeof(char));
  if (new_str == s21_NULL) {
    return s21_NULL;
  }

  for (s21_size_t i = 0; i < summary_len; i++) {
    if (i < start_index) {
      new_str[i] = src[i];
    } else if (i < str_len + start_index) {
      new_str[i] = str[i - start_index];
    } else {
      new_str[i] = src[i - str_len];
    }
  }
  return (void *)new_str;
}