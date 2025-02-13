#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *temp_dest = dest;
  const char *temp_src = src;

  while (n--) {
    *temp_dest++ = *temp_src++;
  }

  return (void *)dest;
}