#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *temp_dest = dest;

  while (*temp_dest != '\0') {
    temp_dest++;
  }

  while (n-- && *src != '\0') {
    *temp_dest++ = *src++;
  }
  *temp_dest = '\0';

  return (char *)dest;
}