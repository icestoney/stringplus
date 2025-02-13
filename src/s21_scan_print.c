#include "s21_scan_print.h"

#include <stdio.h>

void delete_last_zeroes(char *buf, s21_size_t *buf_len) {
  // printf("buf before delete ->%s\n", buf);
  while (buf[(*buf_len) - 1] == '0' && (s21_strncmp(buf, "0", *buf_len) != 0 &&
                                        s21_strncmp(buf, "-0", *buf_len) != 0 &&
                                        s21_strncmp(buf, "+0", *buf_len) != 0 &&
                                        s21_strncmp(buf, " 0", *buf_len) != 0))
    buf[--(*buf_len)] = '\0';
  // printf("buf before delete ->%s\n", buf);
}

void parse_specs(const char **str, options *specs, va_list args) {
  bool none = false;
  specs->width = 0;
  while (!(**str >= '1' && **str <= '9') && !(**str == '.') &&
         !(**str == '0' && (*((*str) + 1) == '0' || *((*str) + 1) == '.')) &&
         !(**str == '%') && !(**str == '0' && *((*str) + 1) == '.')) {
    if (none) break;
    switch (**str) {
      case '#':
        (*str)++;
        specs->mode_show_dot = true;  //#
        break;
      case '-':
        (*str)++;
        specs->minus = true;  //-
        break;
      case '+':
        (*str)++;
        specs->plus = true;  //+
        break;
      case ' ':
        (*str)++;
        specs->space = true;  //' '
        break;
      case '0':
        (*str)++;
        specs->zeroes = true;  // 0
        break;
      default:
        none = true;
        break;
    }
  }

  while ((**str >= '0' && **str <= '9') || **str == '*') {
    if (specs->sscanf && **str == '*') {
      specs->skip = true;
      (*str)++;
    } else if (!specs->sscanf && **str == '*') {
      specs->add_width = true;
      specs->width = (s21_size_t)va_arg(args, int);
      specs->args_number++;
      (*str)++;
    } else
      specs->width = specs->width * 10 + ((*(*str)++) - '0');
  }

  if (**str == '.') {
    specs->prec = 0;
    (*str)++;
    while ((**str >= '0' && **str <= '9') || **str == '*') {
      if (specs->sscanf && **str == '*') {
        specs->skip = true;
        (*str)++;
      } else if (!specs->sscanf && **str == '*') {
        specs->add_prec = true;
        specs->prec = (s21_size_t)va_arg(args, int);
        specs->args_number++;
        (*str)++;
      } else {
        specs->prec_custom = true;
        specs->prec = specs->prec * 10 + ((*(*str)++) - '0');
      }
    }
  }

  if (**str == 'h' || **str == 'l' || **str == 'L') {
    if (**str == 'h') specs->h = true;
    if (**str == 'l') specs->l = true;
    if (**str == 'L') specs->L = true;
    (*str)++;
  }
}

void reverse(char *buf) {
  int len = s21_strlen(buf);
  int start = 0;
  if (buf[0] == '+' || buf[0] == '-' || buf[0] == ' ') start = 1;
  for (int i = start, j = len - 1; i <= j; i++, j--) {
    char c = buf[i];
    buf[i] = buf[j];
    buf[j] = c;
  }
}

bool is_delimit(const char ch) {
  int ch_int = (int)ch & 0x7F;
  const bool DELIMIT[128] = {
      ['\n'] = true, ['\t'] = true, [' '] = true,  ['\0'] = true,
      ['\v'] = true, ['\r'] = true, ['\f'] = true,
      // ...
  };
  ////printf("%c|%d\n",ch_int, ch_int);
  return DELIMIT[ch_int];
}

int starts_with(const char *str, const char *substr) {
  s21_size_t len = s21_strlen(substr);
  for (s21_size_t i = 0; i < len; ++i) {
    if (lower(substr[i]) != lower(str[i])) {
      return 0;
    }
  }
  return 1;
}

int lower(int ch) {
  // 65 90
  // 192 223
  if (ch >= 65 && ch <= 90) ch += 32;
  return ch;
}