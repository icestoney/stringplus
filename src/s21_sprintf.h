#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdarg.h>
#include <stdbool.h>

#include "s21_scan_print.h"
#include "s21_string.h"

int s21_sprintf_parser(char *str, const char *format, va_list args);
void process_d(char *buf, s21_size_t *i, long int_number, options *specs);
void process_x(char *buf, s21_size_t *i, long intx, options *specs);
void process_X(char *buf, s21_size_t *i, long intX, options *specs);
void process_o(char *buf, s21_size_t *i, long int_o, options *specs);
void process_g(char *buf, char **str, s21_size_t *i, long double x1,
               options *specs, int *n);
void process_e(char *buf, char **str, s21_size_t *i, long double ex,
               options *specs, int *n);
void make_mantis(long double *x, int *e);
void add_str(char *buf, const char *x);
void add_sign(char *buf, s21_size_t *i, options specs, long double x);
void add_X(char *buf, s21_size_t *i, s21_size_t x);
void add_x(char *buf, s21_size_t *i, s21_size_t x);
void add_ptr(char *buf, s21_size_t *i, s21_size_t x);
void add_o(char *buf, s21_size_t *i, s21_size_t x);
void count_int(s21_size_t *i, s21_size_t x);
void add_int(char *buf, s21_size_t *i, s21_size_t x, options *specs);
// void add_uint(char *buf, s21_size_t *i, s21_size_t x);
void add_fractal(char *buf, s21_size_t *i, long double x, options *specs);
// void rounding(char *buf, s21_size_t *i, options specs);
void rounding(char *buf, s21_size_t *i);
int inf_nan_check(char *buf, s21_size_t *i, long double x, options specs);
long double get_double(va_list args, options *specs);
s21_size_t output(char *buf, char *output, options specs, int *n);
s21_size_t output_e(char *buf, char *output, options specs, int *n, int e);
#endif