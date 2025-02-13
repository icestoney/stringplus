#include "s21_sprintf.h"

#include <math.h>
#include <stdio.h>
//  #include <string.h>

//  int main(){
//       // long double x =-235023468454368.52346;
//       // double x =(double)55.0;
//       //void* x = (void*)-0x12;
//       // float x = 0.12;
//       // char *x = "234adm132%%";
//       // short int y = 145;
//       //char x  = 'G';
//       // int width = 5;
//       // int prec = 3;
// //       void* null_str = s21_NULL;
// //       void* null_str_std = s21_NULL;
//       char my_str[1000] = {0};
//       char std_str[1000] = {0};
//       // int s21_n = 0;
//       // int n = 0;
//       // char str_0='c';
//       // char str0='\0';
//       // char *str01="32";
//       // char *str02="\0";
// //       s21_sprintf(out, "%0 15f %015f %0f", 1.1111111, +1.1111111,
// -1.1111111);
// //       sprintf(out2, "%0 15f %015f %0f", 1.1111111, +1.1111111,
// -1.1111111);
// //       printf("1 ->%s\n2 ->%s\n\n", out, out2);
// //       s21_sprintf(out, "%#x %#X %x %X %#x %#X %x %X", 0x0, 0x0, 0x0, 0x0,
// -0x0, -0x0, -0x0, -0x0);
// //       sprintf(out2, "%#x %#X %x %X %#x %#X %x %X", 0x0, 0x0, 0x0, 0x0,
// -0x0, -0x0, -0x0, -0x0);
// //       printf("1 ->%s\n2 ->%s\n\n", out, out2);
// //       s21_sprintf(out, "%#x %#X %x %X %#x %#X %x %X", 0x123, 0x123, 0x123,
// 0x123,  -0x123, -0x123, -0x123, -0x123);
// //       sprintf(out2, "%#x %#X %x %X %#x %#X %x %X", 0x123, 0x123, 0x123,
// 0x123,  -0x123, -0x123, -0x123, -0x123);
// //       printf("1 ->%s\n2 ->%s\n\n", out, out2);
// //       s21_sprintf(out, "%#x %#X %x %X", "(nil)", "(nil)", "(nil)",
// "(nil)");
// //       sprintf(out2, "%#x %#X %x %X", "(nil)", "(nil)", "(nil)", "(nil)");
// //       printf("1 ->%s\n2 ->%s\n\n", out, out2);
//         // s21_sprintf(my_str, "%0 10f %0 10lf", NAN, INFINITY);
//         // sprintf(std_str, "%0 10f %0 10lf", NAN, INFINITY);
//         s21_sprintf(my_str, "%0 10e %0 10e", 0.0, 0.0e+0);
//         sprintf(std_str, "%0 10e %0 10e", 0.0, 0.0e+0);
//         printf("1 ->%s\n2 ->%s\n\n", my_str, std_str);
//         s21_sprintf(my_str, "%0 10e %0 10e", 0.1, 0.1e+0);
//         sprintf(std_str, "%0 10e %0 10e", 0.1, 0.1e+0);
//         printf("1 ->%s\n2 ->%s\n\n", my_str, std_str);
//       // s21_sprintf(out, "24bnxc  _ |%-#15.5g_asdjhj", x);
//       // sprintf(out2, "24bnxc  _ |%-#15.5g_asdjhj", x);
//       // s21_sprintf(out, "%e %e %e", 0.0e10, 0.0e15, -2000000000.0e10);
//      // sprintf(out2, "%e %e %e", 0.0e10, 0.0e15, -2000000000.0e10);
//       // s21_sprintf(out, "%G %lG", 15345.672, 15345.61231237);
//      // sprintf(out2, "%G %lG", 15345.672, 15345.61231237);
//       // s21_sprintf(null_str, "%s", "Hello, world!");
//       // printf("%s", strerror(s21_sprintf(null_str, "%s", "Hello,
//       world!")));
//      // sprintf(null_str_std, "%s", "Hello, world!");
//       // s21_sprintf(out, "24bnxc  _ |%% %%%- 15.5f_asdjhj",x);
//       // sprintf(out2, "24bnxc  _ |%% %%%- 15.5LF_asdjhj",x);
//       // s21_sprintf(out, "24bnxc  _ |%c_asdjhj", x);
//       // sprintf(out2, "24bnxc  _ |%c_asdjhj", x);
//       // s21_sprintf(out, "24bnxc  _ |%% %%%0 15ld %0 15hd_asdjhj",x, y);
//       // sprintf(out2, "24bnxc  _ |%% %%%0 15ld %0 15hd_asdjhj",x, y);
//       // s21_sprintf(out, "24bnxc  _ |%% %%%ln_asdjhj",&y);
//       // sprintf(out2, "24bnxc  _ |%% %%%ln_asdjhj",&x);
//       // //printf("%ld\n", y);
//       // //printf("%ld\n", x);
//       // s21_n = s21_sprintf(out, "24bnxc  _ |%% %%%p_asdjhj",x);
//       // n = sprintf(out2, "24bnxc  _ |%% %%%p_asdjhj",x);
//       // s21_n = s21_sprintf(out, "24bnxc  _ |%% %%%#*.*Lf_asdjhj", width,
//       prec, x);
//       // n = sprintf(out2, "24bnxc  _ |%% %%%#*.*Lf_asdjhj", width, prec, x);
//       // s21_n = s21_sprintf(out, "asd %c bvc  %s qwe %030.6e", str_0, str01,
//       x);
//       // n = sprintf(out2, "asd %c bvc  %s qwe %030.6e", str_0, str01, x);
//       // s21_n = s21_sprintf(out, NULL);
//       // n = sprintf(out2, NULL);
//       // s21_sprintf(out, "24bnxc  _ |%% %%%*s_asdjhj", width, x);
//       // sprintf(out2, "24bnxc  _ |%% %%%*s_asdjhj", width, x);
//       // s21_sprintf(out, "24bnxc  _ |%% %%%030hu_asdjhj",x);
//       // sprintf(out2, "24bnxc  _ |%% %%%030hu_asdjhj",x);
//       // s21_sprintf(out, "24bnxc  _ |%% %%%-#30lo_asdjhj",x);
//       // sprintf(out2, "24bnxc  _ |%% %%%-#30lo_asdjhj",x);
//       // s21_sprintf(out, "24bnxc  _ |%% %%%-#30X_asdjhj",x);
//       // sprintf(out2, "24bnxc  _ |%% %%%-#30X_asdjhj",x);
//       //s21_sprintf(out, "24bnxc  _ |%% %%%030.6e_asdjhj",x);
//       //sprintf(out2, "24bnxc  _ |%% %%%030.6e_asdjhj",x);
//       // s21_sprintf(out, "24bnxc  _ |%% %%%-15.1f_asdjhj",x);
//       // sprintf(out2, "24bnxc  _ |%% %%%-15.1f_asdjhj",x);
//       // //printf("f -> s21->%s\n", out);
//       // //printf("f -> std->%s\n", out2);
//       // s21_sprintf(out, "24bnxc  _ |%% %%%-15.1e_asdjhj",x);
//       // sprintf(out2, "24bnxc  _ |%% %%%-15.1e_asdjhj",x);
//       // //printf("e -> s21->%s\n", out);
//       // //printf("e -> std->%s\n", out2);
//       // s21_sprintf(out, "24bnxc  _ |%% %%%-#.2g_asdjhj",x);
//       // sprintf(out2, "24bnxc  _ |%% %%%-#.2g_asdjhj",x);
//       // //printf("g -> s21->%s| n-> %d\n", out, s21_n);
//       // //printf("g -> std->%s| n-> %d\n", out2, n);
//       // s21_sprintf(out, "24bnxc  _ |%% %%%- 15i_asdjhj",x);
//       // sprintf(out2, "24bnxc  _ |%% %%%- 15i_asdjhj",x);
//       //printf("s21->%s| n-> %d\n", out, s21_n);
//       //printf("std->%s| n-> %d\n", out2, n);
//  }

int s21_sprintf(char *str, const char *format, ...) {
  // if ((void*)str == s21_NULL) {
  //      return 22;
  // }
  if (!format) return -1;
  va_list args;
  va_start(args, format);
  int result = s21_sprintf_parser(str, format, args);
  va_end(args);

  return result;
}

int s21_sprintf_parser(char *str, const char *format, va_list args) {
  s21_size_t i = 0;
  // s21_size_t out_i = 0;
  char *tempstr = str;
  while (*str != 0) *str++ = '\0';
  str = tempstr;
  int n = 0;
  while (*format != 0) {
    if (*format != '%') {
      str[i++] = *format++;
      n++;
      continue;
    }
    options specs = {0};
    char buf[5000] = {0};
    format++;
    specs.prec = 6;
    parse_specs(&format, &specs, args);
    switch (*format++) {
      case 'f':
        // out_i=s21_strlen(str);
        i = 0;
        long double x = get_double(args, &specs);  // va_arg(args, double);
        // printf("x=%Lf\n", x);
        if (!inf_nan_check(buf, &i, x, specs)) {
          // printf("buf sign 1 ->%s_\n", buf);
          add_sign(buf, &i, specs, x);
          // printf("buf sign 2 ->%s_\n", buf);
          if (x < 0) x *= -1.0;
          add_int(buf, &i, (long int)x, &specs);
          // printf("buf int ->%s_\n", buf);
          x -= (long int)x;
          ////printf("xfractal=%F\n",x);
          add_fractal(buf, &i, x, &specs);
          // printf("buf fractal ->%s_\n", buf);
        }
        i = output(buf, str, specs, &n);
        // n+=i;
        break;
      case 'c':;
        int c = va_arg(args, int);
        specs.args_number++;
        str[i++] = c;
        n++;
        // printf("%s\n", str);
        break;
      case '%':;
        str[i++] = '%';
        n++;
        break;
      case 'i':
      case 'd':
        i = 0;
        if (specs.h) {
          short int int_number = va_arg(args, int);
          specs.args_number++;
          process_d(buf, &i, int_number, &specs);
        } else if (specs.l) {
          long int int_number = va_arg(args, long int);
          specs.args_number++;
          process_d(buf, &i, int_number, &specs);
        } else {
          int int_number = va_arg(args, int);
          specs.args_number++;
          process_d(buf, &i, int_number, &specs);
        }
        i = output(buf, str, specs, &n);
        // n+=i;
        break;
      case 'n':;
        // printf("%s\n",str);
        if (specs.h) {
          short int *ptr_number = va_arg(args, short int *);
          specs.args_number++;
          *ptr_number = n;
        } else if (specs.l) {
          long int *ptr_number = va_arg(args, long int *);
          specs.args_number++;
          *ptr_number = n;
        } else {
          int *ptr_number = va_arg(args, int *);
          specs.args_number++;
          *ptr_number = n;
        }
        // int *ptr_number = va_arg(args, int *);
        //  //printf("%s\n",str);

        // i++;
        //  //printf("%s\n",str);
        // i=output(buf, str, specs, &out_i);
        break;
      case 'p':;
        // out_i=s21_strlen(str);
        i = 0;
        s21_size_t ptr = va_arg(args, s21_size_t);
        // printf("ptr->%ld\n", ptr);
        specs.args_number++;
        add_ptr(buf, &i, ptr);
        i = output(buf, str, specs, &n);
        // n+=i;
        break;
      case 'x':;
        // out_i=s21_strlen(str);
        i = 0;
        if (specs.h) {
          unsigned short int intx = va_arg(args, unsigned int);
          specs.args_number++;
          process_x(buf, &i, intx, &specs);
        } else if (specs.l) {
          s21_size_t intx = va_arg(args, s21_size_t);
          specs.args_number++;
          process_x(buf, &i, intx, &specs);
        } else {
          unsigned int intx = va_arg(args, unsigned int);
          specs.args_number++;
          process_x(buf, &i, intx, &specs);
        }
        // s21_size_t intx = va_arg(args, s21_size_t);
        // process_x(buf, &i, intx, &specs);
        i = output(buf, str, specs, &n);
        // n+=i;
        break;
      case 'X':;
        // out_i=s21_strlen(str);
        i = 0;
        if (specs.h) {
          unsigned short int intX = va_arg(args, unsigned int);
          specs.args_number++;
          process_X(buf, &i, intX, &specs);
        } else if (specs.l) {
          s21_size_t intX = va_arg(args, s21_size_t);
          specs.args_number++;
          process_X(buf, &i, intX, &specs);
        } else {
          unsigned int intX = va_arg(args, unsigned int);
          specs.args_number++;
          process_X(buf, &i, intX, &specs);
        }
        i = output(buf, str, specs, &n);
        // n+=i;
        break;
      case 's':;
        // out_i=s21_strlen(str);
        i = 0;
        char *strx = va_arg(args, char *);
        specs.args_number++;
        add_str(buf, strx);
        i = output(buf, str, specs, &n);
        // n+=i;
        break;
      case 'u':
        // out_i=s21_strlen(str);
        i = 0;
        if (specs.h) {
          unsigned short int uint_number = va_arg(args, unsigned int);
          specs.args_number++;
          add_int(buf, &i, uint_number, &specs);
        } else if (specs.l) {
          s21_size_t uint_number = va_arg(args, s21_size_t);
          specs.args_number++;
          add_int(buf, &i, uint_number, &specs);
        } else {
          unsigned int uint_number = va_arg(args, unsigned int);
          specs.args_number++;
          add_int(buf, &i, uint_number, &specs);
        }
        // s21_size_t uint_number = va_arg(args, s21_size_t);
        // add_int(buf, &i, uint_number, &specs);
        i = output(buf, str, specs, &n);
        // n+=i;
        break;
      case 'o':;
        // out_i=s21_strlen(str);
        i = 0;
        if (specs.h) {
          unsigned short int int_o = va_arg(args, unsigned int);
          specs.args_number++;
          process_o(buf, &i, int_o, &specs);
        } else if (specs.l) {
          s21_size_t int_o = va_arg(args, s21_size_t);
          specs.args_number++;
          process_o(buf, &i, int_o, &specs);
        } else {
          unsigned int int_o = va_arg(args, unsigned int);
          specs.args_number++;
          process_o(buf, &i, int_o, &specs);
        }
        i = output(buf, str, specs, &n);
        // n+=i;
        break;
      case 'e':
        i = 0;
        long double ex = get_double(args, &specs);
        process_e(buf, &str, &i, ex, &specs, &n);
        break;
      case 'E':
        specs.E = true;
        // out_i=s21_strlen(str);
        i = 0;
        long double Ex = get_double(args, &specs);
        process_e(buf, &str, &i, Ex, &specs, &n);
        // int e = 0;
        // //printf("x=%LF\n", ex);
        // if(!inf_nan_check(buf, &i, ex, specs))
        // {
        //      add_sign(buf, &i, specs, ex);
        //      if(ex<0)
        //              ex*=-1;
        //      make_mantis(&ex, &e);
        //      add_int(buf, &i, (long int)ex, &specs);
        //      ex-= (long int)ex;
        //      //printf("xfractal=%LF\n",ex);
        //      add_fractal(buf, &i, ex, &specs);
        //      i=output_e(buf, str, specs, &n, e);
        // } else {
        //      i=output(buf, str, specs, &n);
        // }

        // //n+=i;
        break;
      case 'g':
        specs.g = true;
        specs.f = true;
        long double x1 = get_double(args, &specs);
        process_g(buf, &str, &i, x1, &specs, &n);
        break;
      case 'G':;
        specs.G = true;
        specs.f = true;
        long double x2 = get_double(args, &specs);
        // if(!specs.prec_custom)
        //      specs.prec = 6;
        process_g(buf, &str, &i, x2, &specs, &n);
        //----------------------------f
        // char buf1_G[500]={0};
        // //out_i=s21_strlen(str);
        // i=0;
        // long double x2 = get_double(args, &specs);
        // long double temp_x2 = x2;
        // s21_size_t temp_prec_G = specs.prec;
        // //printf("x=%LF\n", x2);
        // if(!inf_nan_check(buf, &i, x2, specs))
        // {
        //      add_sign(buf1_G, &i, specs, x2);
        //      if(x2<0)
        //              x2*=-1;
        //      add_int(buf1_G, &i, (long int)x2, &specs);
        //      x2-= (long int)x2;
        //      //printf("xfractal=%LF\n",x2);
        //      add_fractal(buf1_G, &i, x2, &specs);
        //      //printf("%s\n",buf1_G);
        //      s21_size_t buf1_G_len = s21_strlen(buf1_G);
        //      if(!specs.mode_show_dot)
        //              delete_last_zeroes(buf1_G, &buf1_G_len);
        //      specs.f = false;
        //      specs.prec = temp_prec_G;

        // //----------------------------e
        //      specs.e = true;
        //      char buf2[500]={0};
        //      //out_i=s21_strlen(str);
        //      i=0;
        //      int e1 = 0;
        //      x2=temp_x2;
        //      //printf("x2=%LF\n", x2);

        //      add_sign(buf2, &i, specs, x2);
        //      if(x2<0)
        //              x2*=-1;
        //      make_mantis(&x2, &e1);
        //      add_int(buf2, &i, (long int)x2, &specs);
        //      x2-= (long int)x2;
        //      //printf("xfractal=%LF\n",x2);
        //      add_fractal(buf2, &i, x2, &specs);
        //      //printf("%s\n",buf2);
        //      s21_size_t buf2_len = s21_strlen(buf2);
        //      if(!specs.mode_show_dot)
        //              delete_last_zeroes(buf2, &buf2_len);
        //      s21_size_t buf2_e_len = 2;
        //      if (e1>=10)
        //              buf2_e_len++;
        //      count_int(&buf2_e_len, e1);
        //      specs.e = false;
        //      specs.G = false;
        //      //printf("buf1_len -> %lu, buf2_len -> %lu\n", buf1_len,
        //      buf2_len
        //      + buf2_e_len); if ((buf1_G_len <= (buf2_len + buf2_e_len)) &&
        //      !(specs.g_e_prec_low || !specs.mode_show_dot)){
        //              s21_strncat(buf,buf1_G,buf1_G_len);
        //              i=output(buf, str, specs, &n);
        //              printf("here1\n");
        //              //n+=i;
        //      }
        //      else if ((buf1_G_len <= (buf2_len + buf2_e_len)) &&
        //      !(specs.g_e_prec_low)){
        //              s21_strncat(buf,buf2,buf1_G_len);
        //              i=output(buf, str, specs, &n);
        //              printf("here2\n");
        //              //n+=i;
        //      }
        //      else{
        //              s21_strncat(buf,buf2,buf2_len);
        //              //printf("%s\n",buf);
        //              i=output_e(buf, str, specs, &n, e1);
        //              printf("here3\n");
        //              //n+=i;
        //      }
        // }
        // else
        //      i=output(buf, str, specs, &n);
        break;
      default:
        n = -1;
    }
  }
  if (n != -1)
    str[n] = '\0';
  else
    str[0] = '\0';
  // n += s21_strlen(str);
  return n;
}

int inf_nan_check(char *buf, s21_size_t *i, long double x, options specs) {
  int res = 0;
  if (x == INFINITY || x == -INFINITY) {
    if (x == -INFINITY)
      buf[(*i)++] = '-';
    else {
      if (specs.plus) {
        buf[*i] = '+';
        (*i)++;
      } else if (specs.space) {
        buf[*i] = ' ';
        (*i)++;
      }
    }
    // //printf("sign %s\n",buf);
    if (specs.G) {
      s21_strncpy(&(buf[*i]), "INF", 3);
    } else {
      s21_strncpy(&(buf[*i]), "inf", 3);
    }
    // //printf("sign %s\n",buf);
    *i += 3;
    buf[*i] = '\0';
    res = 1;
  }

  if (x != x) {
    if (signbit(x))
      buf[(*i)++] = '-';
    else {
      if (specs.plus) {
        buf[*i] = '+';
        (*i)++;
      } else if (specs.space) {
        buf[*i] = ' ';
        (*i)++;
      }
    }
    ////printf("sign %s\n",buf);
    if (specs.G) {
      s21_strncpy(&(buf[*i]), "NAN", 3);
    } else {
      s21_strncpy(&(buf[*i]), "nan", 3);
    }
    ////printf("sign %s\n",buf);
    *i += 3;
    buf[*i] = '\0';
    res = -1;
  }
  return res;
}

void process_o(char *buf, s21_size_t *i, long int_o, options *specs) {
  add_o(buf, i, int_o);
  if (specs->mode_show_dot) {
    buf[(*i)++] = '0';
  }
  while (((int)specs->prec - (int)*i) > 0 && *buf != '0') {
    buf[(*i)++] = '0';
  }
  buf[*i] = '\0';
  reverse(buf);
}

void process_x(char *buf, s21_size_t *i, long intx, options *specs) {
  add_x(buf, i, intx);
  if (intx != 0 && specs->mode_show_dot) {
    buf[(*i)++] = 'x';
    buf[(*i)++] = '0';
  }
  // if(s21_strncmp(buf, "(nil)", 5) != 0)
  reverse(buf);
}

void process_X(char *buf, s21_size_t *i, long intX, options *specs) {
  add_X(buf, i, intX);
  if (intX != 0 && specs->mode_show_dot) {
    buf[(*i)++] = 'X';
    buf[(*i)++] = '0';
  }
  // if(s21_strncmp(buf, "(nil)", 5) != 0)
  reverse(buf);
}

void process_d(char *buf, s21_size_t *i, long int_number, options *specs) {
  // printf("x=%ld\n", int_number);
  add_sign(buf, i, *specs, int_number);
  if (int_number < 0) int_number *= -1;
  // printf("x=%ld\n", int_number);
  add_int(buf, i, (s21_size_t)int_number, specs);
}

void process_e(char *buf, char **str, s21_size_t *i, long double ex,
               options *specs, int *n) {
  if (!inf_nan_check(buf, i, ex, *specs)) {
    int e = 0;
    add_sign(buf, i, *specs, ex);
    if (ex < 0) ex *= -1;
    make_mantis(&ex, &e);
    add_int(buf, i, (long int)ex, specs);
    ex -= (long int)ex;
    // printf("xfractal=%LF\n",ex);
    add_fractal(buf, i, ex, specs);
    *i = output_e(buf, *str, *specs, n, e);
  } else {
    *i = output(buf, *str, *specs, n);
  }
}

void process_g(char *buf, char **str, s21_size_t *i, long double x1,
               options *specs, int *n) {
  //----------------------------f
  // out_i=s21_strlen(str);
  *i = 0;
  long double temp_x1 = x1;
  s21_size_t temp_prec_g = specs->prec;
  // printf("x=%LF\n", x1);
  if (!inf_nan_check(buf, i, x1, *specs)) {
    char buf1[500] = {0};
    add_sign(buf1, i, *specs, x1);
    if (x1 < 0) x1 *= -1;
    add_int(buf1, i, (long int)x1, specs);
    x1 -= (long int)x1;
    // printf("xfractal=%LF\n",x1);
    add_fractal(buf1, i, x1, specs);
    // printf("%s\n",buf1);
    s21_size_t buf1_len = s21_strlen(buf1);
    if (!specs->mode_show_dot) delete_last_zeroes(buf1, &buf1_len);
    specs->f = false;
    specs->prec = temp_prec_g;

    //----------------------------e
    specs->e = true;
    char buf2[500] = {0};
    // out_i=s21_strlen(str);
    *i = 0;
    int e1 = 0;
    x1 = temp_x1;
    add_sign(buf2, i, *specs, x1);
    if (x1 < 0) x1 *= -1;
    make_mantis(&x1, &e1);
    add_int(buf2, i, (long int)x1, specs);
    x1 -= (long int)x1;
    // printf("xfractal=%LF\n",x1);
    // printf("buf2 before fractal = %s\n*i = %lu\n", buf2, *i);
    add_fractal(buf2, i, x1, specs);
    // printf("buf2 after fractal = %s\n*i = %lu\n", buf2, *i);
    s21_size_t buf2_len = s21_strlen(buf2);
    if (!specs->mode_show_dot) delete_last_zeroes(buf2, &buf2_len);
    s21_size_t buf2_e_len = 2;
    if (e1 >= 10) buf2_e_len++;
    count_int(&buf2_e_len, e1);
    specs->e = false;
    specs->g = false;
    // printf("buf1_len -> %lu, buf2_len -> %lu\n", buf1_len, buf2_len +
    // buf2_e_len);
    if ((buf1_len <= (buf2_len + buf2_e_len)) &&
        !(specs->g_e_prec_low || !specs->mode_show_dot)) {
      s21_strncat(buf, buf1, buf1_len);
      *i = output(buf, *str, *specs, n);
      // n+=i;
    } else if ((buf1_len <= (buf2_len + buf2_e_len)) &&
               !(specs->g_e_prec_low)) {
      s21_strncat(buf, buf1, buf1_len);
      *i = output(buf, *str, *specs, n);
      // n+=i;
    } else {
      s21_strncat(buf, buf2, buf2_len);
      // printf("%s\n",buf);
      *i = output_e(buf, *str, *specs, n, e1);
      // n+=i;
    }
  } else
    *i = output(buf, *str, *specs, n);
}

long double get_double(va_list args, options *specs) {
  long double num = 0;
  if (specs->L) {
    // L - long double
    num = va_arg(args, long double);
    specs->args_number++;
  } else {
    // По умолчанию - double
    num = va_arg(args, double);
    specs->args_number++;
  }
  // Возврат полученного числа
  return num;
}

void make_mantis(long double *x, int *e) {
  while ((*x) > 0 && (long int)*x < 0) {
    *x /= 10;
    *e += 1;
  }
  while (!(((long int)*x) / 10 > 0 && ((long int)*x) / 10 <= 9)) {
    if (*x == 0.0) break;
    if (((long int)*x) / 10 == 0) {
      *x *= 10;
      *e -= 1;
    }
    if (((long int)*x) / 10 >= 10) {
      *x /= 10;
      *e += 1;
    }
  }
  if (((long int)*x) >= 10) {
    *x /= 10;
    *e += 1;
  }
  // if(*x != 0.0 && ((long int)*x)== 0){
  //      *x*=10;
  //      *e-=1;
  // }
}

void add_str(char *buf, const char *x) {
  s21_size_t xlen = s21_strlen(x);
  for (s21_size_t i = 0; i < xlen; i++) buf[i] = x[i];
  // s21_memcpy(buf, x, xlen+1);
}

void add_sign(char *buf, s21_size_t *i, options specs, long double x) {
  if (x >= 0) {
    if (specs.plus) {
      buf[*i] = '+';
      (*i)++;
    } else if (specs.space) {
      buf[*i] = ' ';
      (*i)++;
    }
  } else {
    buf[*i] = '-';
    (*i)++;
  }
  // printf("sign ->%s\n",buf);
}

void add_X(char *buf, s21_size_t *i, s21_size_t x) {
  if (x == 0) {
    buf[*i] = '0';
    (*i)++;
  }
  while (x != 0) {
    if (x % 16 == 15) buf[(*i)++] = 'F';
    if (x % 16 == 14) buf[(*i)++] = 'E';
    if (x % 16 == 13) buf[(*i)++] = 'D';
    if (x % 16 == 12) buf[(*i)++] = 'C';
    if (x % 16 == 11) buf[(*i)++] = 'B';
    if (x % 16 == 10) buf[(*i)++] = 'A';
    if (x % 16 < 10) {
      buf[(*i)++] = x % 16 + '0';
    }
    x /= 16;
  }
  buf[*i] = '\0';
}

void add_x(char *buf, s21_size_t *i, s21_size_t x) {
  if (x == 0) {
    buf[*i] = '0';
    (*i)++;
  }
  while (x != 0) {
    // printf("x->%ld\n", x);
    if (x % 16 == 15) buf[(*i)++] = 'f';
    if (x % 16 == 14) buf[(*i)++] = 'e';
    if (x % 16 == 13) buf[(*i)++] = 'd';
    if (x % 16 == 12) buf[(*i)++] = 'c';
    if (x % 16 == 11) buf[(*i)++] = 'b';
    if (x % 16 == 10) buf[(*i)++] = 'a';
    if (x % 16 < 10) {
      buf[(*i)++] = x % 16 + '0';
    }
    x /= 16;
  }
  buf[*i] = '\0';
}

void add_ptr(char *buf, s21_size_t *i, s21_size_t x) {
  if (x == 0) {
    s21_strncpy(buf, "(nil)", 5);
  } else {
    add_x(buf, i, x);
  }
  if (!starts_with(&(buf[*i]), "(nil)")) {
    buf[(*i)++] = 'x';
    buf[(*i)++] = '0';
    reverse(buf);
  }
  // printf("buf->%s\n", buf);
}

void add_o(char *buf, s21_size_t *i, s21_size_t x) {
  if (x == 0) {
    buf[*i] = '0';
    (*i)++;
  }
  while (x != 0) {
    buf[(*i)++] = x % 8 + '0';
    x /= 8;
  }
  buf[*i] = '\0';
}

void count_int(s21_size_t *i, s21_size_t x) {
  if (x == 0) {
    (*i)++;
  }
  while (x != 0) {
    x /= 10;
    (*i)++;
  }
}

void add_int(char *buf, s21_size_t *i, s21_size_t x, options *specs) {
  if (x == 0) {
    buf[*i] = '0';
    (*i)++;
  }
  // printf("int buf 0-> %s\n", buf);
  while (x != 0) {
    // printf("int buf 1-> %s\n", buf);
    // printf("int prec 1-> %lu\n", specs->prec);
    if ((specs->g || specs->G) && (x % 10 >= 1 || specs->g_prec_started)) {
      specs->g_prec_started = true;
      if (specs->prec > 0)
        specs->prec--;
      else {
        // printf("int prec 2-> %lu\n", specs->prec);
        specs->g_e_prec_low = true;
      }
      // printf("int prec 2-> %lu\n", specs->prec);
    }
    buf[(*i)++] = x % 10 + '0';
    // printf("int buf 25-> %s\n", buf);
    x /= 10;
    if ((specs->g || specs->G) && specs->g_e_prec_low) {
      // printf("int buf 3-> %s\n", buf);
      break;
    }
  }
  reverse(buf);
  buf[*i] = '\0';
}

void add_fractal(char *buf, s21_size_t *i, long double x, options *specs) {
  // if(x<0)
  //      x*=-1.0;
  // if(*i==0){
  //      (*i)++;
  // }
  // printf("prec = %lu\n", specs->prec);
  if ((specs->prec > 0 && !((specs->g || specs->G) && x == 0)) ||
      specs->mode_show_dot) {
    buf[(*i)++] = '.';
  }
  for (s21_size_t j = 0; j < specs->prec + 1; j++) {
    x *= 10;
    if ((int)x > 0) specs->g_prec_started = true;
    if ((specs->g || specs->G) && !specs->g_prec_started) specs->prec++;
    buf[(*i)++] = (long int)x + '0';
    x -= (long int)x;
  }
  // if (specs->e) {
  //      printf("buf fractal e->%s\n", buf);
  //      (*i)++;
  //      rounding(buf, i);
  //      (*i)--;
  // } else {
  //      printf("buf fractal no_e->%s\n", buf);
  rounding(buf, i);
  // }
  buf[*i] = '\0';
}

void rounding(char *buf, s21_size_t *i) {
  int temp_ind = (*i) - 1;
  if (buf[temp_ind] >= 5 + '0') {
    buf[temp_ind - 1]++;
  }
  // else if (buf[temp_ind]==5 + '0')
  // {
  //      if(buf[temp_ind-1]%2==0){
  //              buf[temp_ind-1]++;
  //      }
  // }
  temp_ind--;
  while (buf[temp_ind] == 10 + '0') {
    buf[temp_ind--] = '0';
    if (buf[temp_ind] == '.') {
      temp_ind--;
    }
    buf[temp_ind]++;
  }
  if (temp_ind == -1) {
    for (s21_size_t temp_end = *i; temp_end > 0; temp_end--) {
      buf[temp_end] = buf[temp_end - 1];
    }
    buf[0] = '1';
    (*i)++;
  }
  (*i)--;
}

s21_size_t output(char *buf, char *output, options specs, int *out_i) {
  s21_size_t spaces = 0;
  if (specs.width >= s21_strlen(buf)) spaces = specs.width - s21_strlen(buf);

  if (!specs.minus) {
    for (s21_size_t i = 0; i < spaces; i++) {
      if (!specs.zeroes) {
        output[(*out_i)++] = ' ';
      } else {
        if (specs.mode_show_dot && i == 1 && (buf[1] == 'x' || buf[1] == 'X')) {
          output[(*out_i)++] = buf[i];
          buf[i] = '0';
          buf++;
        }
        if (s21_strncmp(buf, "nan", 3) != 0 &&
            s21_strncmp(buf, "inf", 3) != 0 &&
            s21_strncmp(buf, "-nan", 4) != 0 &&
            s21_strncmp(buf, " nan", 4) != 0 &&
            s21_strncmp(buf, "+nan", 4) != 0 &&
            s21_strncmp(buf, "-inf", 4) != 0 &&
            s21_strncmp(buf, "+inf", 4) != 0 &&
            s21_strncmp(buf, " inf", 4) != 0) {
          // printf("output 1 ->%s\n", output);
          if (i == 0 && (buf[0] == '+' || buf[0] == '-' || buf[0] == ' ')) {
            output[(*out_i)++] = buf[i];
            buf++;
            //    printf("output 2 ->%s\n", output);
          }
          if (i != 0 || specs.width > s21_strlen(buf)) {
            output[(*out_i)++] = '0';
          }
          //  printf("output 3 ->%s\n", output);
        } else {
          output[(*out_i)++] = ' ';
        }
      }
    }
  }
  s21_size_t bufsize = s21_strlen(buf);
  s21_strncat(output + (*out_i), buf, bufsize);
  *out_i += bufsize;
  if (specs.minus && specs.width >= s21_strlen(buf)) {
    for (s21_size_t i = 0; i < spaces; i++) {
      output[(*out_i)++] = ' ';
    }
  }
  s21_size_t outputsize = (s21_size_t)(*out_i);
  output[outputsize] = '\0';
  return outputsize;
}

s21_size_t output_e(char *buf, char *output, options specs, int *out_i, int e) {
  s21_size_t spaces = 0;
  if (specs.width >= s21_strlen(buf)) spaces = specs.width - s21_strlen(buf);
  if (!specs.minus) {
    for (s21_size_t i = 0; i < spaces; i++) {
      if (!specs.zeroes)
        output[(*out_i)++] = ' ';
      else {
        // printf("output 1 ->%s\n", output);
        if (i == 0 && (buf[0] == '+' || buf[0] == '-' || buf[0] == ' ')) {
          output[(*out_i)++] = buf[i];
          buf++;
        }
        //  printf("output 2 ->%s\n", output);
        if (i != 0 || specs.width > s21_strlen(buf)) {
          output[(*out_i)++] = '0';
        }
        //  printf("output 3 ->%s\n", output);
      }
    }
  }

  s21_size_t bufsize = s21_strlen(buf);
  s21_size_t minus_spaces = 1;
  if (specs.G || specs.E)
    buf[bufsize++] = 'E';
  else
    buf[bufsize++] = 'e';

  if (e >= 0) {
    buf[bufsize++] = '+';
    minus_spaces += 1;
  } else {
    e *= -1;
    buf[bufsize++] = '-';
    minus_spaces += 1;
  }
  if (e < 10) {
    buf[bufsize++] = '0';
    minus_spaces += 1;
  }
  s21_size_t sum = 0;
  // printf("start %s\n", output);
  add_int(buf + bufsize, &sum, (s21_size_t)e, &specs);
  bufsize += sum;
  minus_spaces += sum;
  if (spaces >= minus_spaces) spaces -= minus_spaces;
  if (!specs.minus && specs.width >= s21_strlen(buf)) (*out_i) -= minus_spaces;
  for (s21_size_t j = 0; j < minus_spaces; j++) output[(*out_i)] = '\0';
  s21_strncat(output + (*out_i), buf, bufsize);
  *out_i += bufsize;
  // printf("2->%s\n",output);
  if (specs.minus) {
    for (s21_size_t i = 0; i < spaces; i++) {
      output[(*out_i)++] = ' ';
    }
  }
  s21_size_t outputsize = (s21_size_t)(*out_i);
  output[outputsize] = '\0';
  return outputsize;
}
// #include "s21_sprintf.h"
// #include <stdio.h>
// #include <math.h>
// #include <string.h>

// // int main(){
// // 	// long double x =-235023468454368.52346;
// // 	// double x =(double)55.0;
// // 	//void* x = (void*)-0x12;
// // 	// float x = 0.12;
// // 	// char *x = "234adm132%%";
// // 	// short int y = 145;
// // 	//char x  = 'G';
// // 	// int width = 5;
// // 	// int prec = 3;
// // 	char out[1000] = {0};
// // 	char out2[1000] = {0};
// // 	// int s21_n = 0;
// // 	// int n = 0;
// // 	// char str_0='c';
// // 	// char str0='\0';
// // 	// char *str01="32";
// // 	// char *str02="\0";
// // 	// s21_sprintf(out, "24bnxc  _ |%-#15.5g_asdjhj", x);
// // 	// sprintf(out2, "24bnxc  _ |%-#15.5g_asdjhj", x);
// // 	// s21_sprintf(out, "%e %e %e", 0.0e10, 0.0e15, -2000000000.0e10);
// //     // sprintf(out2, "%e %e %e", 0.0e10, 0.0e15, -2000000000.0e10);
// // 	s21_sprintf(out, "%.2e %.2le", 15345.67, 15345.67);
// //     sprintf(out2, "%.2e %.2le", 15345.67, 15345.67);
// // 	printf("%s\n%s\n", out, out2);
// // 	// s21_sprintf(out, "24bnxc  _ |%% %%%- 15.5f_asdjhj",x);
// // 	// sprintf(out2, "24bnxc  _ |%% %%%- 15.5LF_asdjhj",x);
// // 	// s21_sprintf(out, "24bnxc  _ |%c_asdjhj", x);
// // 	// sprintf(out2, "24bnxc  _ |%c_asdjhj", x);
// // 	// s21_sprintf(out, "24bnxc  _ |%% %%%0 15ld %0 15hd_asdjhj",x, y);
// // 	// sprintf(out2, "24bnxc  _ |%% %%%0 15ld %0 15hd_asdjhj",x, y);
// // 	// s21_sprintf(out, "24bnxc  _ |%% %%%ln_asdjhj",&y);
// // 	// sprintf(out2, "24bnxc  _ |%% %%%ln_asdjhj",&x);
// // 	// //printf("%ld\n", y);
// // 	// //printf("%ld\n", x);
// // 	// s21_n = s21_sprintf(out, "24bnxc  _ |%% %%%p_asdjhj",x);
// // 	// n = sprintf(out2, "24bnxc  _ |%% %%%p_asdjhj",x);
// // 	// s21_n = s21_sprintf(out, "24bnxc  _ |%% %%%#*.*Lf_asdjhj", width,
// prec, x);
// // 	// n = sprintf(out2, "24bnxc  _ |%% %%%#*.*Lf_asdjhj", width, prec, x);
// // 	// s21_n = s21_sprintf(out, "asd %c bvc  %s qwe %030.6e", str_0, str01,
// x);
// // 	// n = sprintf(out2, "asd %c bvc  %s qwe %030.6e", str_0, str01, x);
// // 	// s21_n = s21_sprintf(out, NULL);
// // 	// n = sprintf(out2, NULL);
// // 	// s21_sprintf(out, "24bnxc  _ |%% %%%*s_asdjhj", width, x);
// // 	// sprintf(out2, "24bnxc  _ |%% %%%*s_asdjhj", width, x);
// // 	// s21_sprintf(out, "24bnxc  _ |%% %%%030hu_asdjhj",x);
// // 	// sprintf(out2, "24bnxc  _ |%% %%%030hu_asdjhj",x);
// // 	// s21_sprintf(out, "24bnxc  _ |%% %%%-#30lo_asdjhj",x);
// // 	// sprintf(out2, "24bnxc  _ |%% %%%-#30lo_asdjhj",x);
// // 	// s21_sprintf(out, "24bnxc  _ |%% %%%-#30X_asdjhj",x);
// // 	// sprintf(out2, "24bnxc  _ |%% %%%-#30X_asdjhj",x);
// // 	//s21_sprintf(out, "24bnxc  _ |%% %%%030.6e_asdjhj",x);
// // 	//sprintf(out2, "24bnxc  _ |%% %%%030.6e_asdjhj",x);
// // 	// s21_sprintf(out, "24bnxc  _ |%% %%%-15.1f_asdjhj",x);
// // 	// sprintf(out2, "24bnxc  _ |%% %%%-15.1f_asdjhj",x);
// // 	// //printf("f -> s21->%s\n", out);
// // 	// //printf("f -> std->%s\n", out2);
// // 	// s21_sprintf(out, "24bnxc  _ |%% %%%-15.1e_asdjhj",x);
// // 	// sprintf(out2, "24bnxc  _ |%% %%%-15.1e_asdjhj",x);
// // 	// //printf("e -> s21->%s\n", out);
// // 	// //printf("e -> std->%s\n", out2);
// // 	// s21_sprintf(out, "24bnxc  _ |%% %%%-#.2g_asdjhj",x);
// // 	// sprintf(out2, "24bnxc  _ |%% %%%-#.2g_asdjhj",x);
// // 	// //printf("g -> s21->%s| n-> %d\n", out, s21_n);
// // 	// //printf("g -> std->%s| n-> %d\n", out2, n);
// // 	// s21_sprintf(out, "24bnxc  _ |%% %%%- 15i_asdjhj",x);
// // 	// sprintf(out2, "24bnxc  _ |%% %%%- 15i_asdjhj",x);
// // 	//printf("s21->%s| n-> %d\n", out, s21_n);
// // 	//printf("std->%s| n-> %d\n", out2, n);
// // }

// int s21_sprintf(char *str, const char *format, ...) {
// 	// if (str == s21_NULL) {
// 	//  	return 22;
// 	// }
// 	if(!format)
// 		return -1;
// 	va_list args;
// 	va_start(args, format);
// 	int result = s21_sprintf_parser(str, format, args);
// 	va_end(args);

// 	return result;
// }

// int s21_sprintf_parser(char *str, const char *format, va_list args) {
// 	s21_size_t i = 0;
// 	//s21_size_t out_i = 0;
// 	char * tempstr = str;
// 	while(*str!=0)
// 		*str++ = '\0';
// 	str = tempstr;
// 	int n = 0;
// 	while(*format!=0) {
// 		if(*format != '%'){
// 			str[i++] = *format++;
// 			n++;
// 			continue;
// 		}
// 		options specs = {0};
// 		char buf[5000] = {0};
// 		format++;
// 		specs.prec=6;
// 		parse_specs(&format, &specs, args);
// 		switch(*format++){
// 			case 'f':
// 				//out_i=s21_strlen(str);
// 				i=0;
// 				long double x = get_double(args,
// &specs);//va_arg(args, double);
// 				//printf("x=%Lf\n", x);
// 				if(!inf_nan_check(buf, &i, x, specs))
// 				{
// 					add_sign(buf, &i, specs, x);
// 					if(x<0)
// 						x*=-1.0;
// 					add_int(buf, &i, (long int)x, &specs);
// 					x-= (long int)x;
// 					////printf("xfractal=%F\n",x);
// 					add_fractal(buf, &i, x, &specs);
// 				}
// 				i=output(buf, str, specs, &n);
// 				//n+=i;
// 				break;
// 			case 'c':;
// 				int c = va_arg(args, int);
// 				specs.args_number++;
// 				str[i++] = c;
// 				n++;
// 				//printf("%s\n", str);
// 				break;
// 			case '%':;
// 				str[i++] = '%';
// 				n++;
// 				break;
// 			case 'i':
// 			case 'd':
// 				i=0;
// 				if(specs.h)
// 				{
// 					short int int_number = va_arg(args,
// int); 					specs.args_number++;
// process_d(buf, &i, int_number, &specs);
// 				}
// 				else if(specs.l)
// 				{
// 					long int int_number = va_arg(args, long
// int); 					specs.args_number++;
// process_d(buf, &i, int_number, &specs);
// 				}
// 				else
// 				{
// 					int int_number = va_arg(args, int);
// 					specs.args_number++;
// 					process_d(buf, &i, int_number, &specs);
// 				}
// 				i=output(buf, str, specs, &n);
// 				//n+=i;
// 				break;
// 			case 'n':;
// 				//printf("%s\n",str);
// 				if(specs.h)
// 				{
// 					short int *ptr_number = va_arg(args,
// short int
// *); 					specs.args_number++;
// *ptr_number = n;
// 				}
// 				else if(specs.l)
// 				{
// 					long int *ptr_number = va_arg(args, long
// int
// *); 					specs.args_number++;
// *ptr_number = n;
// 				}
// 				else
// 				{
// 					int *ptr_number = va_arg(args, int *);
// 					specs.args_number++;
// 					*ptr_number = n;
// 				}
// 				//int *ptr_number = va_arg(args, int *);
// 				// //printf("%s\n",str);

// 				//i++;
// 				// //printf("%s\n",str);
// 				//i=output(buf, str, specs, &out_i);
// 				break;
// 			case 'p':;
// 				//out_i=s21_strlen(str);
// 				i=0;
// 				s21_size_t ptr = va_arg(args, s21_size_t);
// 				//printf("ptr->%ld\n", ptr);
// 				specs.args_number++;
// 				add_ptr(buf, &i, ptr);
// 				i=output(buf, str, specs, &n);
// 				//n+=i;
// 				break;
// 			case 'x':;
// 				//out_i=s21_strlen(str);
// 				i=0;
// 				if(specs.h)
// 				{
// 					unsigned short int intx = va_arg(args,
// unsigned int
// ); 					specs.args_number++;
// process_x(buf, &i, intx, &specs);
// 				}
// 				else if(specs.l)
// 				{
// 					s21_size_t intx = va_arg(args,
// s21_size_t
// ); 					specs.args_number++;
// process_x(buf, &i, intx, &specs);
// 				}
// 				else
// 				{
// 					unsigned int intx = va_arg(args,
// unsigned int
// ); 					specs.args_number++;
// process_x(buf, &i, intx, &specs);
// 				}
// 				// s21_size_t intx = va_arg(args, s21_size_t);
// 				// process_x(buf, &i, intx, &specs);
// 				i=output(buf, str, specs, &n);
// 				//n+=i;
// 				break;
// 			case 'X':;
// 				//out_i=s21_strlen(str);
// 				i=0;
// 				if(specs.h)
// 				{
// 					unsigned short int intX = va_arg(args,
// unsigned int
// ); 					specs.args_number++;
// process_X(buf, &i, intX, &specs);
// 				}
// 				else if(specs.l)
// 				{
// 					s21_size_t intX = va_arg(args,
// s21_size_t
// ); 					specs.args_number++;
// process_X(buf, &i, intX, &specs);
// 				}
// 				else
// 				{
// 					unsigned int intX = va_arg(args,
// unsigned int
// ); 					specs.args_number++;
// process_X(buf, &i, intX, &specs);
// 				}
// 				i=output(buf, str, specs, &n);
// 				//n+=i;
// 				break;
// 			case 's':;
// 				//out_i=s21_strlen(str);
// 				i=0;
// 				char *strx = va_arg(args, char*);
// 				specs.args_number++;
// 				add_str(buf, strx);
// 				i=output(buf, str, specs, &n);
// 				//n+=i;
// 				break;
// 			case 'u':
// 				//out_i=s21_strlen(str);
// 				i=0;
// 				if(specs.h)
// 				{
// 					unsigned short int uint_number =
// va_arg(args, unsigned int );
// specs.args_number++; 					add_int(buf, &i,
// uint_number, &specs);
// 				}
// 				else if(specs.l)
// 				{
// 					s21_size_t uint_number = va_arg(args,
// s21_size_t
// ); 					specs.args_number++;
// add_int(buf, &i, uint_number, &specs);
// 				}
// 				else
// 				{
// 					unsigned int uint_number = va_arg(args,
// unsigned int
// ); 					specs.args_number++;
// add_int(buf, &i, uint_number, &specs);
// 				}
// 				// s21_size_t uint_number = va_arg(args,
// s21_size_t);
// 				// add_int(buf, &i, uint_number, &specs);
// 				i=output(buf, str, specs, &n);
// 				//n+=i;
// 				break;
// 			case 'o':;
// 				//out_i=s21_strlen(str);
// 				i=0;
// 				if(specs.h)
// 				{
// 					unsigned short int int_o = va_arg(args,
// unsigned int
// ); 					specs.args_number++;
// process_o(buf, &i, int_o, &specs);
// 				}
// 				else if(specs.l)
// 				{
// 					s21_size_t int_o = va_arg(args,
// s21_size_t
// ); 					specs.args_number++;
// process_o(buf, &i, int_o, &specs);
// 				}
// 				else
// 				{
// 					unsigned int int_o = va_arg(args,
// unsigned int
// ); 					specs.args_number++;
// process_o(buf, &i, int_o, &specs);
// 				}
// 				i=output(buf, str, specs, &n);
// 				//n+=i;
// 				break;
// 			case 'e':
// 				i=0;
// 				long double ex = get_double(args, &specs);
// 				process_e(buf, &str, &i, ex, &specs, &n);
// 				break;
// 			case 'E':
// 				specs.E = true;
// 				//out_i=s21_strlen(str);
// 				i=0;
// 				long double Ex = get_double(args, &specs);
// 				process_e(buf, &str, &i, Ex, &specs, &n);
// 				// int e = 0;
// 				// //printf("x=%LF\n", ex);
// 				// if(!inf_nan_check(buf, &i, ex, specs))
// 				// {
// 				// 	add_sign(buf, &i, specs, ex);
// 				// 	if(ex<0)
// 				// 		ex*=-1;
// 				// 	make_mantis(&ex, &e);
// 				// 	add_int(buf, &i, (long int)ex, &specs);
// 				// 	ex-= (long int)ex;
// 				// 	//printf("xfractal=%LF\n",ex);
// 				// 	add_fractal(buf, &i, ex, &specs);
// 				// 	i=output_e(buf, str, specs, &n, e);
// 				// } else {
// 				// 	i=output(buf, str, specs, &n);
// 				// }

// 				// //n+=i;
// 				break;
// 			case 'g':
// 				specs.g = true;
// 				specs.f = true;
// 				long double x1 = get_double(args, &specs);
// 				process_g(buf, &str, &i, x1, &specs, &n);
// 				break;
// 			case 'G':;
// 				specs.G = true;
// 				specs.f = true;
// 				long double x2 = get_double(args, &specs);
// 				if(!specs.prec_custom)
// 					specs.prec = 5;
// 				process_g(buf, &str, &i, x2, &specs, &n);
// 				//----------------------------f
// 				// char buf1_G[500]={0};
// 				// //out_i=s21_strlen(str);
// 				// i=0;
// 				// long double x2 = get_double(args, &specs);
// 				// long double temp_x2 = x2;
// 				// s21_size_t temp_prec_G = specs.prec;
// 				// //printf("x=%LF\n", x2);
// 				// if(!inf_nan_check(buf, &i, x2, specs))
// 				// {
// 				// 	add_sign(buf1_G, &i, specs, x2);
// 				// 	if(x2<0)
// 				// 		x2*=-1;
// 				// 	add_int(buf1_G, &i, (long int)x2,
// &specs);
// 				// 	x2-= (long int)x2;
// 				// 	//printf("xfractal=%LF\n",x2);
// 				// 	add_fractal(buf1_G, &i, x2, &specs);
// 				// 	//printf("%s\n",buf1_G);
// 				// 	s21_size_t buf1_G_len =
// s21_strlen(buf1_G);
// 				// 	if(!specs.mode_show_dot)
// 				// 		delete_last_zeroes(buf1_G,
// &buf1_G_len);
// 				// 	specs.f = false;
// 				// 	specs.prec = temp_prec_G;

// 				// //----------------------------e
// 				// 	specs.e = true;
// 				// 	char buf2[500]={0};
// 				// 	//out_i=s21_strlen(str);
// 				// 	i=0;
// 				// 	int e1 = 0;
// 				// 	x2=temp_x2;
// 				// 	//printf("x2=%LF\n", x2);

// 				// 	add_sign(buf2, &i, specs, x2);
// 				// 	if(x2<0)
// 				// 		x2*=-1;
// 				// 	make_mantis(&x2, &e1);
// 				// 	add_int(buf2, &i, (long int)x2, &specs);
// 				// 	x2-= (long int)x2;
// 				// 	//printf("xfractal=%LF\n",x2);
// 				// 	add_fractal(buf2, &i, x2, &specs);
// 				// 	//printf("%s\n",buf2);
// 				// 	s21_size_t buf2_len = s21_strlen(buf2);
// 				// 	if(!specs.mode_show_dot)
// 				// 		delete_last_zeroes(buf2,
// &buf2_len);
// 				// 	s21_size_t buf2_e_len = 2;
// 				// 	if (e1>=10)
// 				// 		buf2_e_len++;
// 				// 	count_int(&buf2_e_len, e1);
// 				// 	specs.e = false;
// 				// 	specs.G = false;
// 				// 	//printf("buf1_len -> %lu, buf2_len ->
// %lu\n", buf1_len, buf2_len + buf2_e_len);
// 				// 	if ((buf1_G_len <= (buf2_len +
// buf2_e_len))
// &&
// !(specs.g_e_prec_low || !specs.mode_show_dot)){
// 				//
// s21_strncat(buf,buf1_G,buf1_G_len);
// 				// 		i=output(buf, str, specs, &n);
// 				// 		printf("here1\n");
// 				// 		//n+=i;
// 				// 	}
// 				// 	else if ((buf1_G_len <= (buf2_len +
// buf2_e_len))
// && !(specs.g_e_prec_low)){
// 				// s21_strncat(buf,buf2,buf1_G_len);
// 				// 		i=output(buf, str, specs, &n);
// 				// 		printf("here2\n");
// 				// 		//n+=i;
// 				// 	}
// 				// 	else{
// 				// 		s21_strncat(buf,buf2,buf2_len);
// 				// 		//printf("%s\n",buf);
// 				// 		i=output_e(buf, str, specs, &n,
// e1);
// 				// 		printf("here3\n");
// 				// 		//n+=i;
// 				// 	}
// 				// }
// 				// else
// 				// 	i=output(buf, str, specs, &n);
// 				break;
// 			default:
// 				n=-1;
// 		}
// 	}
// 	if (n==-1)
// 	{
// 		str[0] = '\0';
// 	} else {
// 		str[n] = '\0';
// 	}

// 	//n += s21_strlen(str);
// 	return n;
// }

// int inf_nan_check(char *buf, s21_size_t *i, long double x, options specs){
// 	int res = 0;
// 	if(x==INFINITY || x==-INFINITY)
// 	{
// 		if(x == -INFINITY)
// 			buf[(*i)++] = '-';
// 		else
// 		{
// 			if(specs.plus){
// 				buf[*i] = '+';
// 				(*i)++;
// 			}
// 			else if (specs.space){
// 			buf[*i] = ' ';
// 			(*i)++;
// 			}
// 		}
// 		// //printf("sign %s\n",buf);
// 		if (specs.G)
// 		{
// 			s21_strncpy(&(buf[*i]), "INF", 3);
// 		} else {
// 			s21_strncpy(&(buf[*i]), "inf", 3);
// 		}
// 		// //printf("sign %s\n",buf);
// 		*i+=3;
// 		buf[*i] = '\0';
// 		res = 1;
// 	}

// 	if(x!=x)
// 	{
// 		if(signbit(x))
// 			buf[(*i)++] = '-';
// 		else
// 		{
// 			if(specs.plus){
// 				buf[*i] = '+';
// 				(*i)++;
// 			}
// 			else if (specs.space){
// 			buf[*i] = ' ';
// 			(*i)++;
// 			}
// 		}
// 		////printf("sign %s\n",buf);
// 		if (specs.G)
// 		{
// 			s21_strncpy(&(buf[*i]), "NAN", 3);
// 		} else {
// 			s21_strncpy(&(buf[*i]), "nan", 3);
// 		}
// 		////printf("sign %s\n",buf);
// 		*i+=3;
// 		buf[*i] = '\0';
// 		res = -1;
// 	}
// 	return res;
// }

// void process_o(char *buf, s21_size_t *i, long int_o, options *specs)
// {
// 	add_o(buf, i, int_o);
// 	if(specs->mode_show_dot){
// 		buf[(*i)++] ='0';
// 	}
// 	while(((int)specs->prec - (int)*i) > 0 && *buf != '0') {
// 		buf[(*i)++] ='0';
// 	}
// 	buf[*i] = '\0';
// 	reverse(buf);
// }

// void process_x(char *buf, s21_size_t *i, long intx, options *specs)
// {
// 	add_x(buf, i, intx);
// 	if(specs->mode_show_dot){
// 		buf[(*i)++] ='x';
// 		buf[(*i)++] ='0';
// 	}
// 	// if(s21_strncmp(buf, "(nil)", 5) != 0)
// 		reverse(buf);
// }

// void process_X(char *buf, s21_size_t *i, long intX, options *specs)
// {
// 	add_X(buf, i, intX);
// 	if(specs->mode_show_dot){
// 		buf[(*i)++] ='X';
// 		buf[(*i)++] ='0';
// 	}
// 	// if(s21_strncmp(buf, "(nil)", 5) != 0)
// 		reverse(buf);
// }

// void process_d(char *buf, s21_size_t *i, long int_number, options *specs)
// {
// 	//printf("x=%ld\n", int_number);
// 	add_sign(buf, i, *specs, int_number);
// 	if(int_number<0)
// 		int_number*=-1;
// 	//printf("x=%ld\n", int_number);
// 	add_int(buf, i, (s21_size_t)int_number, specs);
// }

// void process_e(char *buf, char **str, s21_size_t *i, long double ex, options
// *specs, int *n) { 	if(!inf_nan_check(buf, i, ex, *specs))
// 	{
// 		int e = 0;
// 		add_sign(buf, i, *specs, ex);
// 		if(ex<0)
// 			ex*=-1;
// 		make_mantis(&ex, &e);
// 		add_int(buf, i, (long int)ex, specs);
// 		ex-= (long int)ex;
// 		//printf("xfractal=%LF\n",ex);
// 		add_fractal(buf, i, ex, specs);
// 		*i=output_e(buf, *str, *specs, n, e);
// 	} else {
// 		*i=output(buf, *str, *specs, n);
// 	}
// }

// void process_g(char *buf, char **str, s21_size_t *i, long double x1, options
// *specs, int *n) {
// 				//----------------------------f
// 				char buf1[500]={0};
// 				//out_i=s21_strlen(str);
// 				*i=0;
// 				long double temp_x1 = x1;
// 				s21_size_t temp_prec_g = specs->prec;
// 				//printf("x=%LF\n", x1);
// 				if(!inf_nan_check(buf, i, x1, *specs))
// 				{
// 					add_sign(buf1, i, *specs, x1);
// 					if(x1<0)
// 						x1*=-1;
// 					add_int(buf1, i, (long int)x1, specs);
// 					x1-= (long int)x1;
// 					//printf("xfractal=%LF\n",x1);
// 					add_fractal(buf1, i, x1, specs);
// 					//printf("%s\n",buf1);
// 					s21_size_t buf1_len = s21_strlen(buf1);
// 					if(!specs->mode_show_dot)
// 						delete_last_zeroes(buf1,
// &buf1_len); 					specs->f = false;
// specs->prec = temp_prec_g;

// 				//----------------------------e
// 					specs->e = true;
// 					char buf2[500]={0};
// 					//out_i=s21_strlen(str);
// 					*i=0;
// 					int e1 = 0;
// 					x1=temp_x1;
// 					add_sign(buf2, i, *specs, x1);
// 					if(x1<0)
// 						x1*=-1;
// 					make_mantis(&x1, &e1);
// 					add_int(buf2, i, (long int)x1, specs);
// 					x1-= (long int)x1;
// 					// printf("xfractal=%LF\n",x1);
// 					// printf("buf2 before fractal = %s\n*i
// =
// %lu\n", buf2, *i); 					add_fractal(buf2, i, x1,
// specs);
// 					// printf("buf2 after fractal = %s\n*i =
// %lu\n", buf2, *i); 					s21_size_t buf2_len =
// s21_strlen(buf2); if(!specs->mode_show_dot)
// delete_last_zeroes(buf2,
// &buf2_len); 					s21_size_t buf2_e_len = 2;
// if (e1>=10) 						buf2_e_len++;
// 					count_int(&buf2_e_len, e1);
// 					specs->e = false;
// 					specs->g = false;
// 					//printf("buf1_len -> %lu, buf2_len ->
// %lu\n",
// buf1_len, buf2_len + buf2_e_len); 					if
// ((buf1_len
// <= (buf2_len + buf2_e_len))
// && !(specs->g_e_prec_low || !specs->mode_show_dot)){
// 						s21_strncat(buf,buf1,buf1_len);
// 						*i=output(buf, *str, *specs, n);
// 						//n+=i;
// 					}
// 					else if ((buf1_len <= (buf2_len +
// buf2_e_len))
// &&
// !(specs->g_e_prec_low)){
// s21_strncat(buf,buf1,buf1_len);
// *i=output(buf, *str, *specs, n);
// 						//n+=i;
// 					}
// 					else{
// 						s21_strncat(buf,buf2,buf2_len);
// 						//printf("%s\n",buf);
// 						*i=output_e(buf, *str, *specs,
// n, e1);
// 						//n+=i;
// 					}
// 				}
// 				else
// 					*i=output(buf, *str, *specs, n);
// }

// long double get_double(va_list args, options *specs) {
//   long double num = 0;
//   if (specs->L) {
//     // L - long double
//     num = va_arg(args, long double);
// 	specs->args_number++;
//   } else {
//     // По умолчанию - double
//     num = va_arg(args, double);
// 	specs->args_number++;
//   }
//   // Возврат полученного числа
//   return num;
// }

// void make_mantis(long double *x, int *e){
// 	// printf("\n       x = %Lf\n", *x);
// 	// printf("\n       x = %ld\n", (long int)*x);
// 	while((*x) > 0 && (long int)*x < 0) {
// 		*x/=10;
// 		*e+=1;
// 	}

// 	while(!(((long int)*x)/10>0 && ((long int)*x)/10<=9)){
// 		if (*x == 0.0)
// 			break;
// 		if(((long int)*x)/10==0){
// 			*x*=10;
// 			*e-=1;
// 		}
// 		if(((long int)*x)/10>=10){
// 			*x/=10;
// 			*e+=1;
// 		}
// 		// printf("\n       x = %ld\n", (long int)*x);
// 		// printf("\nmantis e = %d\n", *e);
// 	}
// 	if(((long int)*x)>=10){
// 		*x/=10;
// 		*e+=1;
// 	}
// 	if(*x != 0.0 && ((long int)*x)== 0){
// 		*x*=10;
// 		*e-=1;
// 	}
// 	// printf("\nmantis e_result = %d\n", *e);
// }

// void add_str(char *buf, const char *x){
// 	s21_size_t xlen = s21_strlen(x);
// 	for(s21_size_t i=0;i<xlen;i++)
// 		buf[i]=x[i];
// 	//s21_memcpy(buf, x, xlen+1);
// }

// void add_sign(char *buf, s21_size_t *i, options specs, long double x)
// {
// 	if(x>=0){
// 		if(specs.plus){
// 			buf[*i] = '+';
// 			(*i)++;
// 		}
// 		else if (specs.space){
// 			buf[*i] = ' ';
// 			(*i)++;
// 		}
// 	}
// 	else
// 	{
// 			buf[*i] = '-';
// 			(*i)++;
// 	}
// 	//printf("sign ->%s\n",buf);
// }

// void add_X(char *buf, s21_size_t *i, s21_size_t x){
// 	if(x==0){
// 		buf[*i] = '0';
// 		(*i)++;
// 	}
// 	while(x!=0)
// 	{
// 		if(x%16==15)
// 			buf[(*i)++] = 'F';
// 		if(x%16==14)
// 			buf[(*i)++] = 'E';
// 		if(x%16==13)
// 			buf[(*i)++] = 'D';
// 		if(x%16==12)
// 			buf[(*i)++] = 'C';
// 		if(x%16==11)
// 			buf[(*i)++] = 'B';
// 		if(x%16==10)
// 			buf[(*i)++] = 'A';
// 		if(x%16<10){
// 			buf[(*i)++] = x%16 + '0';
// 		}
// 		x/=16;
// 	}
// 	buf[*i]='\0';
// }

// void add_x(char *buf, s21_size_t *i, s21_size_t x){
// 	if(x==0){
// 		buf[*i] = '0';
// 		(*i)++;
// 	}
// 	while(x!=0)
// 	{
// 		//printf("x->%ld\n", x);
// 		if(x%16==15)
// 			buf[(*i)++] = 'f';
// 		if(x%16==14)
// 			buf[(*i)++] = 'e';
// 		if(x%16==13)
// 			buf[(*i)++] = 'd';
// 		if(x%16==12)
// 			buf[(*i)++] = 'c';
// 		if(x%16==11)
// 			buf[(*i)++] = 'b';
// 		if(x%16==10)
// 			buf[(*i)++] = 'a';
// 		if(x%16<10){
// 			buf[(*i)++] = x%16 + '0';
// 		}
// 		x/=16;
// 	}
// 	buf[*i]='\0';
// }

// void add_ptr(char *buf, s21_size_t *i, s21_size_t x){
// 	if (x==0)
// 	{
// 		s21_strncpy(buf, "(nil)", 5);
// 	} else {
// 		add_x(buf, i, x);
// 	}
// 	if(!starts_with(&(buf[*i]), "(nil)"))
// 	{
// 			buf[(*i)++] = 'x';
// 			buf[(*i)++] = '0';
// 			reverse(buf);
// 	}

// 	//printf("buf->%s\n", buf);
// }

// void add_o(char *buf, s21_size_t *i, s21_size_t x){
// 	if(x==0){
// 		buf[*i] = '0';
// 		(*i)++;
// 	}
// 	while(x!=0)
// 	{
// 		buf[(*i)++] = x%8 + '0';
// 		x/=8;
// 	}
// 	buf[*i]='\0';
// }

// void count_int(s21_size_t *i, s21_size_t x){
// 	if(x==0){
// 		(*i)++;
// 	}
// 	while(x!=0)
// 	{
// 		x/=10;
// 		(*i)++;
// 	}
// }

// void add_int(char *buf, s21_size_t *i, s21_size_t x, options *specs){
// 	if(x==0){
// 		buf[*i] = '0';
// 		(*i)++;
// 	}
// 	//printf("int buf 0-> %s\n", buf);
// 	while(x!=0)
// 	{
// 		// printf("int buf 1-> %s\n", buf);
// 		// printf("int prec 1-> %lu\n", specs->prec);
// 		if((specs->g || specs->G) && (x % 10 >= 1 ||
// specs->g_prec_started)){ 			specs->g_prec_started = true;
// if(specs->prec>0) 				specs->prec--;
// else
// 			{
// 				// printf("int prec 2-> %lu\n", specs->prec);
// 				specs->g_e_prec_low = true;
// 			}
// 			// printf("int prec 2-> %lu\n", specs->prec);
// 		}
// 		buf[(*i)++] = x%10 + '0';
// 		// printf("int buf 25-> %s\n", buf);
// 		x/=10;
// 		if((specs->g || specs->G) && specs->g_e_prec_low)
// 		{
// 			// printf("int buf 3-> %s\n", buf);
// 			break;
// 		}
// 	}
// 	reverse(buf);
// 	buf[*i]='\0';
// }

// void add_fractal(char *buf, s21_size_t *i, long double x, options *specs){
// 	// if(x<0)
// 	// 	x*=-1.0;
// 	// if(*i==0){
// 	// 	(*i)++;
// 	// }
// 	// printf("prec = %lu\n", specs->prec);
// 	if((specs->prec>0 && (!(specs->prec>0) || !((specs->g || specs->G) && x
// == 0))) || specs->mode_show_dot){ 		buf[(*i)++] = '.';
// 	}
// 	for(s21_size_t j =0; j < specs->prec + 1; j++){
// 		x*=10;
// 		if((int)x>0)
// 			specs->g_prec_started = true;
// 		if((specs->g || specs->G) && !specs->g_prec_started)
// 			specs->prec++;
// 		buf[(*i)++] = (long int)x + '0';
// 		x -= (long int)x;
// 	}
// 	// if (specs->e) {
// 	// 	printf("buf fractal e->%s\n", buf);
// 	// 	(*i)++;
// 	// 	rounding(buf, i);
// 	// 	(*i)--;
// 	// } else {
// 	// 	printf("buf fractal no_e->%s\n", buf);
// 		rounding(buf, i);
// 	// }
// 	buf[*i] = '\0';
// }

// void rounding(char *buf, s21_size_t *i){
// 	int temp_ind = (*i) - 1;
// 	if(buf[temp_ind]>= 5 + '0'){
// 		buf[temp_ind-1]++;
// 	}
// 	// else if (buf[temp_ind]==5 + '0')
// 	// {
// 	// 	if(buf[temp_ind-1]%2==0){
// 	// 		buf[temp_ind-1]++;
// 	// 	}
// 	// }
// 	temp_ind--;
// 	while(buf[temp_ind]== 10 + '0')
// 	{
// 		buf[temp_ind--] = '0';
// 		if(buf[temp_ind]=='.'){
// 			temp_ind--;
// 		}
// 		buf[temp_ind]++;
// 	}
// 	(*i)--;
// }

// s21_size_t output(char *buf, char *output, options specs, int *out_i){
// 	s21_size_t spaces = 0;
// 	if(specs.width >= s21_strlen(buf))
// 		spaces = specs.width - s21_strlen(buf);

// 	if (!specs.minus){
// 		for(s21_size_t i=0; i < spaces; i++){
// 			if(!specs.zeroes)
// 			{
// 				output[(*out_i)++] = ' ';
// 			}
// 			else{
// 				// if(s21_strncmp(buf, "nan", 3) != 0 &&
// s21_strncmp(buf, "inf", 3) != 0 && s21_strncmp(buf, "-nan", 4) != 0 &&
// s21_strncmp(buf,
// "+nan", 4) != 0 && s21_strncmp(buf, "-inf", 4) != 0 && s21_strncmp(buf,
// "+inf", 4) != 0)
// 				// {
// 				// 	// if(specs.mode_show_dot && i==1 &&
// (buf[1]=='x'
// || buf[1]=='X')){
// 				// 	// 	output[(*out_i)++] = buf[i];
// 				// 	// 	buf[i]='0';
// 				// 	// 	buf++;
// 				// 	// }
// 				// 	// if(i==0 &&( buf[0]=='+' ||
// buf[0]=='-'
// || buf[0]==' ')){
// 				// 	// 	output[(*out_i)++] = buf[i];
// 				// 	// 	buf++;
// 				// 	// }
// 					output[(*out_i)++] = '0';
// 				// }
// 				// else
// 				// 	output[(*out_i)++] = ' ';
// 			}
// 		}
// 	}
// 	s21_size_t bufsize = s21_strlen(buf);
// 	s21_strncat(output+(*out_i), buf, bufsize);
// 	*out_i+=bufsize;
// 	if (specs.minus && specs.width >= s21_strlen(buf)){
// 		for(s21_size_t i=0; i < spaces; i++){
// 			output[(*out_i)++] = ' ';
// 		}
// 	}
// 	s21_size_t outputsize = (s21_size_t)(*out_i);
// 	output[outputsize] = '\0';
// 	return outputsize;
// }

// s21_size_t output_e(char *buf, char *output, options specs, int *out_i, int
// e){ 	s21_size_t spaces=0; 	if(specs.width >= s21_strlen(buf))
// spaces = specs.width - s21_strlen(buf); 	if (!specs.minus){
// for(s21_size_t i=0; i <
// spaces; i++){ 			if(!specs.zeroes)
// output[(*out_i)++] = ' '; 			else{
// if(i==0
// &&(
// buf[0]=='+' || buf[0]=='-' || buf[0]==' ')){
// output[(*out_i)++] = buf[i]; 					buf++;
// 				}
// 				output[(*out_i)++] = '0';
// 			}
// 		}
// 	}

// 	s21_size_t bufsize = s21_strlen(buf);
// 	s21_size_t minus_spaces = 1;
// 	if (specs.G || specs.E)
// 		buf[bufsize++] = 'E';
// 	else
// 		buf[bufsize++] = 'e';

// 	if(e>=0){
// 		buf[bufsize++] = '+';
// 		minus_spaces+=1;
// 	}
// 	else{
// 		e*=-1;
// 		buf[bufsize++] = '-';
// 		minus_spaces+=1;
// 	}
// 	if(e<10)
// 	{
// 		buf[bufsize++] = '0';
// 		minus_spaces+=1;
// 	}
// 	s21_size_t sum = 0;
// 	//printf("start %s\n", output);
// 	add_int(buf + bufsize, &sum, (s21_size_t)e, &specs);
// 	bufsize+=sum;
// 	minus_spaces+=sum;
// 	if(spaces>=minus_spaces)
// 		spaces-=minus_spaces;
// 	if(!specs.minus && specs.width >= s21_strlen(buf))
// 		(*out_i)-=minus_spaces;
// 	for (s21_size_t j=0; j<minus_spaces; j++)
// 		output[(*out_i)] = '\0';
// 	s21_strncat(output+(*out_i), buf, bufsize);
// 	*out_i += bufsize;
// 	//printf("2->%s\n",output);
// 	if (specs.minus){
// 		for(s21_size_t i=0; i < spaces; i++){
// 			output[(*out_i)++] = ' ';
// 		}
// 	}
// 	s21_size_t outputsize = (s21_size_t)(*out_i);
// 	output[outputsize] = '\0';
// 	return outputsize;
// }