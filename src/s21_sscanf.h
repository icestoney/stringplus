#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <stdarg.h>

#include "s21_scan_print.h"

int s21_sscanf_parser(const char *str, const char *format, va_list args);
void counting(bool stop_counting, options *specs);
void add_integer(long int *arg, const char **str, options specs, bool *success);
s21_size_t add_float(float *arg, const char **str, s21_size_t width,
                     bool *success);
s21_size_t add_ldouble(long double *arg, const char **str, s21_size_t width,
                       bool *success);
s21_size_t add_double(double *arg, const char **str, s21_size_t width,
                      bool *success);
void add_oct(long int *arg, const char **str, s21_size_t width, bool *success);
s21_size_t add_hex(long int *arg, const char **str, s21_size_t width,
                   bool *success);
void add_hex_float(float *arg, const char **str, s21_size_t width, bool custom,
                   bool *success);
void add_hex_double(double *arg, const char **str, s21_size_t width,
                    bool custom, bool *success);
void add_hex_ldouble(long double *arg, const char **str, s21_size_t width,
                     bool custom, bool *success);
void add_e(float *arg, const char **str, s21_size_t width, options specs,
           bool custom);
void add_e_ld(long double *arg, const char **str, s21_size_t width,
              options specs, bool custom);
void add_e_d(double *arg, const char **str, s21_size_t width, options specs,
             bool custom);
int hex_int(char hex);
void flag_i(long int *arg, const char **str, options *specs, bool *success);
long int *arg_to_int(va_list args, options *specs);
int inf_str(const char *str, int width);
int nan_str(const char *str, int width);
// long double ld_nan_inf(const char *str, int width);
// double d_nan_inf(const char *str, int width);
long double nan_inf(const char *str, int width);

#endif