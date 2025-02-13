#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *temp_dest = dest;

  while (n--) {
    if ((*temp_dest = *src) != 0) {
      src++;
    }
    temp_dest++;
  }
  *temp_dest = '\0';

  return (char *)dest;
}