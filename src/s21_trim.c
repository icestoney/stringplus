#include "s21_string.h"

int s21_trim_start(const char *src, const char *trim_chars,
                   s21_size_t start_offset);
int s21_trim_end(const char *src, const char *trim_chars,
                 s21_size_t end_offset);

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL) {
    return s21_NULL;
  }
  if (trim_chars == s21_NULL || s21_strlen(trim_chars) == 0) {
    trim_chars = " \t\n\r\v\f\0";
  }

  s21_size_t start_offset = 0;
  s21_size_t end_offset = s21_strlen(src);
  while (s21_trim_start(src, trim_chars, start_offset)) {
    start_offset++;
  }

  while (end_offset > start_offset &&
         s21_trim_end(src, trim_chars, end_offset)) {
    end_offset--;
  }

  s21_size_t new_len = end_offset - start_offset;
  char *new_str = (char *)calloc(new_len + 1, sizeof(char));
  if (new_str == s21_NULL) {
    return s21_NULL;
  }

  for (s21_size_t i = 0; start_offset < end_offset; i++) {
    new_str[i] = src[start_offset++];
  }
  new_str[new_len] = '\0';

  return (void *)new_str;
}

int s21_trim_start(const char *src, const char *trim_chars,
                   s21_size_t start_offset) {
  int result = 0;
  s21_size_t len = s21_strlen(trim_chars);

  for (s21_size_t i = 0; i < len; i++) {
    if (src[start_offset] == trim_chars[i]) {
      result = 1;
    }
  }

  return result;
}

int s21_trim_end(const char *src, const char *trim_chars,
                 s21_size_t end_offset) {
  int result = 0;
  s21_size_t len = s21_strlen(trim_chars);
  end_offset--;

  for (s21_size_t i = 0; i < len; i++) {
    if (src[end_offset] == trim_chars[i]) {
      result = 1;
    }
  }

  return result;
}