#include "s21_string.h"

// find the first substring in a %NUL terminated string
char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') {
    return (char *)haystack;
  }
  while (*haystack != '\0') {
    const char *temp_haystack = haystack;
    const char *temp_needle = needle;
    while (*temp_needle != '\0' && *temp_haystack == *temp_needle) {
      temp_haystack++;
      temp_needle++;
    }
    if (*temp_needle == '\0') {
      return (char *)haystack;
    }
    haystack++;
  }
  return s21_NULL;
}