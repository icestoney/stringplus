#include "s21_sscanf.h"

#include <math.h>
#include <stdio.h>

#include "s21_scan_print.h"

// int main(){
// 	// wchar_t b1, b2;
//   	// wchar_t* a1 = calloc(20, sizeof(wchar_t));
//   	// wchar_t* a2 = calloc(20, sizeof(wchar_t));
// 	//// double x =-2350.52346;
// 	//// double x =(double)55.0;
// 	// short int x = 0;
// 	// short int x_2 = 0;
// 	// //char *x = "234adm132%%";
// 	// //int y = 145;
// 	// //char x  = 'G';
//     // char str1[100]={0};
// 	// char str1_2[100]={0};
//     // char str2[100]={0};
//     // char str3[100]={0};
// 	// char str3_2[100]={0};
//     // int x2 = 0;
// 	// int x2_2 = 0;
// 	// // char out[1000] = {0};
// 	// // char out2[1000] = {0};
// 	// char c = 0;
// 	// char c_2 = 0;
// 	// //char procent=0;
// 	// double dnum=0.0;
// 	// double dnum_2=0.0;
// 	// int ch_int=0;
// 	// int ch_int_2=0;
// 	// int ox=0;
// 	// int ox_2=0;
// 	// int ox2=0;
// 	// int ox2_2=0;
// 	// float e = 0;
// 	// float e_2 = 0;
// 	// unsigned long int ux = 0;
// 	// unsigned long int ux_2 = 0;
// 	// unsigned int ux2 = 0;
// 	// unsigned int ux2_2 = 0;
// 	// void *p = s21_NULL;
// 	// void *p_2 = s21_NULL;
// 	// float g =0;
// 	// float g_2 =0;
// 	// float G =0;
// 	// float G_2 =0;
// 	// char *str = "hello %\ta21  2 44 5 4strike  k 1.10 65537 237
// +0XadF2 2.06 6 5 0xfd235 0xff 0x2ddf 2.567";
// 	// char *format = "hello%%%s%d%s%ld%s %c %4lf %i %o %x %e %u %u %p %n %g
// %G";
// 	// int n = 0;
// 	// int n_2 = 0;
// 	// int num = 0;
// 	// int s21_num = 0;
// 	// int s_n1 = 0;
// 	// int s_n2 = 0;
// 	// char str2_2[100]={0};
// 	// s21_num=s21_sscanf(str, format, str1, &x, str2, &x2, str3, &c, &dnum,
// &ch_int, &ox, &ox2, &e, &ux, &ux2, &n, &p, &g, &G);
// 	// printf("s21_sscanf -> %s, d %d, s %s, d %d, s %s, c %c, f %lf, i %d,
// o %o, x %x, e %e, e %f, %ld %d, p %p, n %d, %f, %G || s21_num %d\n", str1, x,
// str2, x2, str3, c, dnum, ch_int, ox, ox2, e, e, ux, ux2, p, n, g, G,
// s21_num);
//     // num=sscanf(str, format, str1_2, &x_2, str2_2, &x2_2, str3_2, &c_2,
//     &dnum_2, &ch_int_2, &ox_2, &ox2_2, &e_2, &ux_2, &ux2_2, &n_2, &p_2, &g_2,
//     &G_2);
//     // printf("    sscanf -> %s, d %d, s %s, d %d, s %s, c %c, f %lf, i %d, o
//     %o, x %x, e %e, e %f, %ld %d, p %p, n %d, %f, %G ||     num %d\n",
//     str1_2, x_2, str2_2, x2_2, str3_2, c_2, dnum_2, ch_int_2, ox_2, ox2_2,
//     e_2, e_2, ux_2, ux2_2, p_2, n_2, g_2, G_2, num);
// 	float c1 = -1, c2 = -1;
//  	double d1 = -1, d2 = -1;
//   	long double e1 = -1, e2 = -1;
// 	int std_res = sscanf("-0x.0 -0x.0 -0x.0", "%5f %5lf %5Lf", &c1, &d1,
// &e1); 	int my_res = s21_sscanf("-0x.0 -0x.0 -0x.0", "%5f %5lf %5Lf",
// &c2, &d2, &e2); 	printf("std_res ->%d\nmy_res ->%d\n", std_res, my_res);
// printf("c1 = %f / d1 = %lf / e1 = %LF\nc2 = %f / d2 = %lf / e2 = %LF\n", c1,
// d1, e1, c2, d2, e2);
// 	// if (a1 && a2) {
// 	// 	int std_res = sscanf("abcdef 000 0000", "%15ls", a1);
// 	// 	int my_res = s21_sscanf("abcdef 000 0000", "%15ls", a2);
// 	// }
// 	// printf("std_res ->%d\nmy_res ->%d\n", std_res, my_res);
// 	// printf("b1 ->%lc\nb2 ->%lc\n", b1, b2);
// 	// printf("a1 ->%ls\na2 ->%ls\n", a1, a2);
// 	// s_n1=s21_strlen(str2);
// 	// s_n2=s21_strlen(str2_2);
// 	//printf("%d %d\n", s_n1, s_n2);
// 	// s21_sscanf(str, format, str1, &x, str2, str3, &c, &dnum, &ch_int,
// &ox, &ox2, &e, &ux, &ux2, &n, &p, &g, &G);
// 	// //printf("s21_sscanf -> %s, %d, %s, %d, %s, %c, %f, %d, %o, %x, %e,
// %f, %ld %d, %p, %d, %g, %G\n", str1, x, str2, x2, str3, c, dnum, ch_int, ox,
// ox2, e, e, ux, ux2, p, n, g, G);
// 	// //printf("g -> s21->%s\n", out);
// 	// //printf("g -> std->%s\n", out2);
// 	// s21_s//printf(out, "24bnxc  _ |%% %%%- 15i_asdjhj",x);
// 	// s//printf(out2, "24bnxc  _ |%% %%%- 15i_asdjhj",x);
// 	// //printf("s21->%s\n", out);
// 	// //printf("std->%s\n", out2);
// 	// free(a1);
//   	// free(a2);
// }

int s21_sscanf(const char *str, const char *format, ...) {
  // if (str == s21_NULL) {
  // 	//printf("%s", s21_strerror(22));
  // 	exit(22);
  // }
  va_list args;
  va_start(args, format);
  int result = s21_sscanf_parser(str, format, args);
  va_end(args);

  return result;
}

int s21_sscanf_parser(const char *str, const char *format, va_list args) {
  int num = 0;
  s21_size_t i = 0;
  bool stop_counting = false;
  const char *temp_str = str;
  bool have_args = false;

  while ((*format != 0 &&
          (*format == *str || *format == '%' || is_delimit(*format++))) &&
         !stop_counting) {
    options specs = {0};
    specs.sscanf = true;
    // printf("str ->%s || num ->%d\n", str, num);
    //  if((*str=='\0') && num==0)
    //  {
    //  	num = -1;
    //  	stop_counting = true;
    //  	break;
    //  }
    //  else
    //  if (*str == '\0')
    //  {
    //  	num = 0;
    //  	stop_counting = true;
    //  	break;
    //  }

    if (*format != '%') {
      str++;
      format++;
      continue;
    }
    if (is_delimit(*str) && !(*(format + 2) == 'c' && *(format + 1) == 'l')) {
      str++;
      continue;
    }
    format++;
    specs.prec = 0;
    parse_specs(&format, &specs, args);
    switch (*format++) {
      case 'e':;
      case 'E':;
      case 'g':;
      case 'G':;
      case 'f':;
        float *x = s21_NULL;
        long double *ld_x = s21_NULL;
        double *d_x = s21_NULL;
        long double ld_t_x = 0;
        double d_t_x = 0;
        float t_x = 0;
        bool success = false;
        ////printf("f -> %p\n", x);
        long double x_nan_inf = nan_inf(str, specs.width);
        if (x_nan_inf) {
          success = true;
          if (*str == '-' || *str == '+') str++;
          str += 3;

          if (!specs.skip) {
            if (specs.L) {
              ld_x = (long double *)va_arg(args, long double *);
              have_args = true;
              *ld_x = x_nan_inf;
            } else if (specs.l) {
              d_x = (double *)va_arg(args, double *);
              have_args = true;
              *d_x = (double)x_nan_inf;
            } else {
              x = (float *)va_arg(args, float *);
              have_args = true;
              *x = (float)x_nan_inf;
            }
            if (!success) stop_counting = true;
            counting(stop_counting, &specs);
          }
        } else if (((*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X')) &&
                    (specs.width >= 3 || specs.width == 0)) ||
                   (((*str == '-' || *str == '+') &&
                     (*(str + 1) == '0' &&
                      (*(str + 2) == 'x' || *(str + 2) == 'X'))) &&
                    (specs.width >= 4 || specs.width == 0))) {
          // str+=2;
          long int *arg_x = (long int *)&(specs.l_i_temp);
          // int *arg_x = arg_to_int(args, &specs);
          // printf("str hex->%s\n",str);
          s21_size_t width_left = add_hex(arg_x, &str, specs.width, &success);
          ////printf("arg hex->%ld\n",*arg_x);
          bool custom = false;
          if (specs.width > 0) custom = true;
          if (specs.skip) {
            if (specs.L) {
              long double skip_x = 0;
              add_hex_ldouble(&skip_x, &str, width_left, custom, &success);
            } else if (specs.l) {
              double skip_x = 0;
              add_hex_double(&skip_x, &str, width_left, custom, &success);
            } else {
              float skip_x = 0;
              add_hex_float(&skip_x, &str, width_left, custom, &success);
            }
          } else {
            // printf("last seen here %lx\n", *arg_x);

            if (specs.L) {
              ld_x = (long double *)va_arg(args, long double *);
              have_args = true;
              *ld_x = (long double)(*arg_x);
              // printf("here 2\n");
              // if(specs.width ==1 && *ld_x==0 && *(str-3) == '-' && (((*str)>=
              // '0' && (*str) <= '9')||((*str)>= 'a' && (*str) <=
              // 'f')||((*str)>= 'A' && (*str) <= 'F')))
              // {
              // 	printf("here Lf\n");
              // 	*ld_x*=-1;
              // 	success = true;
              // }
              add_hex_ldouble(ld_x, &str, width_left, custom, &success);
            } else if (specs.l) {
              d_x = (double *)va_arg(args, double *);
              have_args = true;
              // printf("started\n");
              *d_x = (double)(*arg_x);
              // if(specs.width ==1 && *d_x==0 && *(str-3) == '-' && (((*str)>=
              // '0' && (*str) <= '9')||((*str)>= 'a' && (*str) <=
              // 'f')||((*str)>= 'A' && (*str) <= 'F')))
              // {
              // 	printf("here lf\n");
              // 	*d_x*=-1;
              // 	success = true;
              // }
              add_hex_double(d_x, &str, width_left, custom, &success);

            } else {
              x = (float *)va_arg(args, float *);
              have_args = true;
              *x = (float)(*arg_x);
              // printf("started %f\n", *x);
              //  if(specs.width ==1 && *x==0 && *(str-3) == '-' && (((*str)>=
              //  '0'
              //  && (*str) <= '9')||((*str)>= 'a' && (*str) <= 'f')||((*str)>=
              //  'A' && (*str) <= 'F')))
              //  	{
              //  		printf("here f\n");
              //  		*x*=-1;
              //  		success = true;
              //  	}
              add_hex_float(x, &str, width_left, custom, &success);
            }
          }
          if (!success) stop_counting = true;
          if (!specs.skip) counting(stop_counting, &specs);
        } else {
          // printf("f -> %p\n", x);
          if (specs.L) {
            s21_size_t width_left = 0;
            if (specs.skip) {
              ld_x = &ld_t_x;
              width_left = add_ldouble(ld_x, &str, specs.width, &success);
            } else {
              ld_x = (long double *)va_arg(args, long double *);
              have_args = true;
              width_left = add_ldouble(ld_x, &str, specs.width, &success);
              ////printf("f -> %Lf\n", *ld_x);
              if (!success) stop_counting = true;
              counting(stop_counting, &specs);
            }
            bool custom = false;
            if (specs.width > 0) custom = true;
            add_e_ld(ld_x, &str, width_left, specs, custom);
            // printf("Lf -> %Lf\n", *ld_x);
          } else if (specs.l) {
            s21_size_t width_left = 0;
            if (specs.skip) {
              d_x = &d_t_x;
              width_left = add_double(d_x, &str, specs.width, &success);
            } else {
              d_x = (double *)va_arg(args, double *);
              have_args = true;
              // printf("here\n");
              // if(success)
              // printf("success\n");
              width_left = add_double(d_x, &str, specs.width, &success);
              // printf("f -> %lf\n", *d_x);
              if (!success) stop_counting = true;
              counting(stop_counting, &specs);
            }
            bool custom = false;
            if (specs.width > 0) custom = true;
            // printf("f -> %f\n", *d_x);
            add_e_d(d_x, &str, width_left, specs, custom);
            // printf("f -> %f\n", *d_x);
          } else {
            s21_size_t width_left = 0;
            if (specs.skip) {
              x = &t_x;
              width_left = add_float(x, &str, specs.width, &success);
            } else {
              x = (float *)va_arg(args, float *);
              have_args = true;
              // //printf("f -> %f\n", *x);
              width_left = add_float(x, &str, specs.width, &success);
              // //printf("f -> %f\n", *x);
              if (!success) stop_counting = true;
              counting(stop_counting, &specs);
            }
            bool custom = false;
            if (specs.width > 0) custom = true;
            add_e(x, &str, width_left, specs, custom);
            // printf("f -> %f\n", *x);
          }
        }
        ////printf("f -> %f", *x);
        break;
      case 'c':;
        if (!specs.skip) {
          if (specs.l) {
            wchar_t *dest = va_arg(args, wchar_t *);
            have_args = true;
            mbtowc(dest, str, 1);
            str++;
          } else {
            *(char *)va_arg(args, char *) = *(str++);
            have_args = true;
          }
          counting(stop_counting, &specs);
        } else
          str++;
        // printf("c ->%c\n", *(str-1));
        break;
      case '%':;
        str++;
        break;
      case 'i':;
        success = false;
        long int *arg = arg_to_int(args, &specs);
        have_args = true;
        flag_i(arg, &str, &specs, &success);
        if (!success) stop_counting = true;
        if (!specs.skip) counting(stop_counting, &specs);
        break;
      case 'd':;
        success = false;
        // printf("Here\n");
        long int *d = arg_to_int(args, &specs);
        have_args = true;
        //*d = arg_to_int(args, &specs);
        //*d = (long int)malloc(sizeof(short int));
        // printf("%ld %p\n", *d, d);
        add_integer(d, &str, specs, &success);

        if (!success) stop_counting = true;
        if (!specs.skip) counting(stop_counting, &specs);
        // printf("d-> %ld\n",*d);
        break;
      case 'n':;
        if (!stop_counting) {
          int *arg_n = s21_NULL;
          if (!specs.skip) {
            //   ////printf("here\n");
            //   // int *t_arg = &(specs->i_temp);
            //   arg_n = &(specs.i_temp);
            // } else {
            arg_n = ((int *)va_arg(args, int *));
            // counting(stop_counting, &specs);
          }
          if (*temp_str != 0)
            *arg_n = str - temp_str;
          else
            *arg_n = 0;
          str--;
        }
        break;
      case 'p':;
        void *arg_p = s21_NULL;
        const char *nil = "0x0";
        s21_size_t width = s21_strlen(str);
#if defined(__linux__)
        if (starts_with(str, "(nil)") && width >= 5) {
          arg_p = ((void *)va_arg(args, void *));
          have_args = true;
          add_hex((long int *)arg_p, &nil, specs.width, &success);
          success = true;
          str += 5;
          counting(stop_counting, &specs);
        }
#elif defined(__APPLE__) || defined(__MACH__)
        if (starts_with(str, "0x0") && width >= 3) {
          arg_p = ((void *)va_arg(args, void *));
          have_args = true;
          add_hex((long int *)arg_p, &nil, specs.width, &success);
          success = true;
          str += 5;
          counting(stop_counting, &specs);
        }
#endif
        else {
          success = false;
          if (specs.skip) {
            ////printf("here\n");
            // int *t_arg = &(specs->i_temp);
            arg_p = &(specs.i_temp);
            add_hex((long int *)arg_p, &str, specs.width, &success);
          } else {
            arg_p = ((void *)va_arg(args, void *));
            have_args = true;
            add_hex((long int *)arg_p, &str, specs.width, &success);
            if (!success) stop_counting = true;
            counting(stop_counting, &specs);
          }
        }
        break;
      case 'x':;
      case 'X':;
        success = false;
        long int *arg_x = arg_to_int(args, &specs);
        have_args = true;
        add_hex(arg_x, &str, specs.width, &success);
        if (!success) stop_counting = true;
        if (!specs.skip) counting(stop_counting, &specs);
        break;
      case 's':;
        i = 0;
        char *arg_s = s21_NULL;
        while (!is_delimit(*(str + i)) && (i <= specs.width - 1)) i++;
        if (!specs.skip) {
          //   arg_s = (char *)malloc(i * sizeof(char));
          //   if (!arg_s) {
          //     // printf("%s", s21_strerror(13));
          //     exit(13);
          //   }
          //   // arg_s = specs.t_str;
          // } else {
          if (specs.l) {
            wchar_t *arg_wc = va_arg(args, wchar_t *);
            have_args = true;
            i = 0;
            while (!is_delimit(str[i])) i++;
            mbstowcs(arg_wc, str, i);
            str += specs.width;
          } else {
            arg_s = ((char *)va_arg(args, char *));
            have_args = true;
            i = 0;
            while (!is_delimit(*str) && (i <= specs.width - 1))
              arg_s[i++] = *(str++);
            arg_s[i] = '\0';
          }
          counting(stop_counting, &specs);
        }
        // if (specs.skip) free(arg_s);
        break;
      case 'u':;
        long int *u = arg_to_int(args, &specs);
        have_args = true;
        success = false;
        add_integer(u, &str, specs, &success);
        // printf("u ->%lu\n", *u);
        if (!success) stop_counting = true;
        if (!specs.skip) counting(stop_counting, &specs);
        break;
      case 'o':;
        long int *arg_o = arg_to_int(args, &specs);
        have_args = true;
        success = false;
        add_oct(arg_o, &str, specs.width, &success);
        if (!success) stop_counting = true;
        if (!specs.skip) counting(stop_counting, &specs);
        break;
        // case 'e':
        // case 'E':;
        // bool success = false;
        // if(specs.L)
        // {
        // 	long double *ld_arg_e = s21_NULL;
        // 	s21_size_t width_left = 0;
        // 	if(specs.skip)
        // 	{
        // 		long double ld_t_arg_e = 0;
        // 		ld_arg_e = &ld_t_arg_e;
        // 		width_left = add_ldouble(ld_arg_e, &str, specs.width,
        // &success);
        // 	}
        // 	else
        // 	{
        // 		ld_arg_e = (long double *)va_arg(args, long double *);
        // 		width_left = add_ldouble(ld_arg_e, &str, specs.width,
        // &success); 		if(!success)
        // stop_counting = true; 		counting(stop_counting, &specs);
        // 	}
        // 	bool custom = false;
        // 	if (specs.width>0)
        // 		custom = true;
        // 	add_e_ld(ld_arg_e, &str, width_left, specs, custom);
        // }
        // else if(specs.l){
        // 	double *d_arg_e =s21_NULL;
        // 	s21_size_t width_left = 0;
        // 	if(specs.skip)
        // 	{
        // 		double d_t_arg_e = 0;
        // 		d_arg_e = &d_t_arg_e;
        // 		width_left = add_double(d_arg_e, &str, specs.width);
        // 	}
        // 	else
        // 	{
        // 		d_arg_e = (double *)va_arg(args, double*);
        // 		width_left = add_double(d_arg_e, &str, specs.width);
        // 		if(!success)
        // 			stop_counting = true;
        // 		counting(stop_counting, &specs);
        // 	}
        // 	bool custom = false;
        // 	if (specs.width>0)
        // 		custom = true;
        // 	add_e_d(d_arg_e, &str, width_left, specs, custom);
        // }
        // else{
        // 	float *arg_e = s21_NULL;
        // 	s21_size_t width_left = 0;
        // 	if(specs.skip)
        // 	{
        // 		float t_arg_e = 0;
        // 		arg_e = &t_arg_e;
        // 		width_left = add_float(arg_e, &str, specs.width);
        // 	}
        // 	else
        // 	{
        // 		arg_e = (float *)va_arg(args, float*);
        // 		width_left = add_float(arg_e, &str, specs.width);
        // 		if(!success)
        // 			stop_counting = true;
        // 		counting(stop_counting, &specs);
        // 	}
        // 	bool custom = false;
        // 	if (specs.width>0)
        // 		custom = true;
        // 	add_e(arg_e, &str, width_left, specs, custom);
        // 	//printf("e ->%f\n", *arg_e);
        // }
        // break;
        // case 'g':
        // case 'G':;
        // bool success = false;
        // s21_size_t width_left = 0;
        // if(specs.L)
        // {
        // 	bool e = false;
        // 	for (s21_size_t i=0; !is_delimit(str[i]); i++)
        // 		if(str[i]=='e')
        // 			e = true;
        // 	long double *ld_arg_g = s21_NULL;

        // 	if(specs.skip)
        // 	{
        // 		long double ld_t_arg_g = 0;
        // 		ld_arg_g = &ld_t_arg_g;
        // 		// if(e)
        // 		// {
        // 		// 	s21_size_t width_left = add_ldouble(ld_arg_g,
        // &str, specs.width);
        // 	}
        // 	else
        // 	{
        // 		ld_arg_g = (long double *)va_arg(args, long double *);
        // 		counting(stop_counting, &specs);
        // 	}
        // 	if(e)
        // 	{
        // 		s21_size_t width_left = add_ldouble(ld_arg_g, &str,
        // specs.width); 		bool custom = false; 		if
        // (specs.width>0) 			custom = true;
        // 		add_e_ld(ld_arg_g, &str, width_left, specs, custom);
        // 	}
        // 	else
        // 	{
        // 		add_ldouble(ld_arg_g, &str, specs.width);
        // 	}
        // }
        // else if(specs.l){
        // 	bool e = false;
        // 	for (s21_size_t i=0; !is_delimit(str[i]); i++)
        // 		if(str[i]=='e')
        // 			e = true;
        // 	double *d_arg_g =s21_NULL;
        // 	if(specs.skip)
        // 	{
        // 		double d_t_arg_g = 0;
        // 		d_arg_g = &d_t_arg_g;
        // 	}
        // 	else
        // 		{
        // 			d_arg_g = (double *)va_arg(args, double*);
        // 			counting(stop_counting, &specs);
        // 		}
        // 	if(e)
        // 	{
        // 		s21_size_t width_left = add_double(d_arg_g, &str,
        // specs.width); 		bool custom = false; 		if
        // (specs.width>0) 			custom = true;
        // add_e_d(d_arg_g, &str, width_left, specs, custom);
        // 	}
        // 	else
        // 	{
        // 		add_double(d_arg_g, &str, specs.width);
        // 	}
        // }
        // else{
        // 	bool e = false;
        // 	for (s21_size_t i=0; !is_delimit(str[i]); i++)
        // 		if(str[i]=='e')
        // 			e = true;
        // 	float *arg_g = s21_NULL;
        // 	if(specs.skip)
        // 	{
        // 		float t_arg_g = 0;
        // 		arg_g = &t_arg_g;
        // 	}
        // 	else
        // 		{
        // 			arg_g = (float *)va_arg(args, float*);
        // 			counting(stop_counting, &specs);
        // 		}
        // 	if(e)
        // 	{
        // 		s21_size_t width_left = add_float(arg_g, &str,
        // specs.width); 		bool custom = false; 		if
        // (specs.width>0) 			custom = true;
        // add_e(arg_g, &str, width_left, specs, custom);
        // 	}
        // 	else
        // 	{
        // 		add_float(arg_g, &str, specs.width);
        // 	}
        // }
        // break;
        // default:;
        //   break;
    }
    num += specs.args_number;
  }
  if (num == 0 && have_args && *temp_str == '\0') {
    num = -1;
  }
  // if(!(*format == *str || *format == '%' ) && num ==0)
  // 	num =-1;
  return num;
}

// long double ld_nan_inf(const char *str, int width){
// 	int nan_search = nan_str(str, width);
// 	if (nan_search != 0)
// 		return nan_search ? -NAN : NAN;

// 	int inf_search = inf_str(str, width);
// 	if (inf_search != 0)
// 		return inf_search ? -INFINITY : INFINITY;
// }

// double d_nan_inf(const char *str, int width){
// 	int nan_search = nan_str(str, width);
// 	if (nan_search != 0)
// 		return nan_search ? -NAN : NAN;

// 	int inf_search = inf_str(str, width);
// 	if (inf_search != 0)
// 		return inf_search ? -INFINITY : INFINITY;
// }

long double nan_inf(const char *str, int width) {
  long double res = 0;

  int nan_search = nan_str(str, width);
  if (nan_search != 0) res = nan_search > 0 ? NAN : -NAN;

  // printf("inf str ->%s\n", str);
  int inf_search = inf_str(str, width);
  if (inf_search != 0) res = inf_search > 0 ? INFINITY : -INFINITY;

  return res;
}

int inf_str(const char *str, int width) {
  int res = 0;
  bool custom = width > 0;
  int sign = str[0] == '-';
  if (sign || str[0] == '+') {
    str++;
    width--;
  }
  // printf("inf str2->%s\n", str);
  if ((width >= 3 || !custom) && starts_with(str, "inf")) {
    res = sign ? -1 : 1;
  }
  // printf("inf res ->%d\n", res);
  return res;
}

int nan_str(const char *str, int width) {
  int res = 0;
  bool custom = width > 0;
  int sign = str[0] == '-';
  if (sign || str[0] == '+') {
    str++;
    width--;
  }

  if ((width >= 3 || !custom) && starts_with(str, "nan")) {
    res = sign ? -1 : 1;
  }

  return res;
}

// void is_ch_float(bool *stop_counting, char *str)
// {

// 	if((*str >= '0' && *str <= '9') || (*str=='.'))
// }

void counting(bool stop_counting, options *specs) {
  if (!stop_counting) specs->args_number++;
}

long int *arg_to_int(va_list args, options *specs) {
  void *arg = s21_NULL;
  // printf("Here2\n");
  if (specs->h) {
    // printf("Here3\n");
    if (specs->skip) {
      // short int h_t_arg = 0;
      arg = &(specs->s_i_temp);
    } else {
      // printf("Here4\n");
      arg = (short int *)va_arg(args, short int *);
      // printf("here %p\n", arg);
      // printf("Here5\n");
      ////printf("%hd %p\n", *(short int*)arg, arg);
    }
  } else if (specs->l) {
    if (specs->skip) {
      // long int l_t_arg = 0;
      arg = &(specs->l_i_temp);
    } else {
      arg = (long int *)va_arg(args, long int *);
    }
  } else {
    if (specs->skip) {
      // //printf("here\n");
      // int *t_arg = &(specs->i_temp);
      arg = &(specs->i_temp);
    } else {
      arg = (int *)va_arg(args, int *);
    }
  }
  // printf("Here6\n");
  // printf("here %p\n", arg);
  return (long int *)arg;
}

void flag_i(long int *arg, const char **str, options *specs, bool *success) {
  bool sign = false;
  if ((*str)[0] == '-' || *str[0] == '+') {
    (*str)++;
    sign = true;
  }

  if ((*str)[0] == '0' && ((*str)[1] == 'x' || (*str)[1] == 'X'))  // x
  {
    if (sign) (*str)--;
    add_hex(arg, str, specs->width, success);
  } else if ((*str)[0] == '0')  // o
  {
    if (sign) (*str)--;
    add_oct(arg, str, specs->width, success);
  } else  // d
  {
    if (sign) (*str)--;
    add_integer(arg, str, *specs, success);
  }
}

void add_e_d(double *arg, const char **str, s21_size_t width, options specs,
             bool custom) {
  if (**str == 'e' && (width > 0 || !custom)) {
    (*str)++;
    if (width) width--;
    if (width > 0 || !custom) {
      long int temp_e = 0;
      bool success = false;
      specs.width = width;
      add_integer(&temp_e, str, specs, &success);

      if (temp_e >= 0) *arg *= powf(10.0, temp_e);
      // while(temp_e--)
      // {
      // 	*arg= (double)*arg * (double)10.0;
      // }
      else
        while (temp_e++) {
          *arg /= 10;
        }
    }
  }
}

void add_e_ld(long double *arg, const char **str, s21_size_t width,
              options specs, bool custom) {
  if (**str == 'e' && (width > 0 || !custom)) {
    (*str)++;
    if (width) width--;
    if (width > 0 || !custom) {
      long int temp_e = 0;
      bool success = false;
      specs.width = width;
      add_integer(&temp_e, str, specs, &success);

      if (temp_e >= 0) *arg *= powf(10.0, temp_e);
      // while(temp_e--)
      // {
      // 	*arg= (double)*arg * (double)10.0;
      // }
      else
        while (temp_e++) {
          *arg /= 10;
        }
    }
  }
}

void add_e(float *arg, const char **str, s21_size_t width, options specs,
           bool custom) {
  if (**str == 'e' && (width > 0 || !custom)) {
    (*str)++;
    if (width) width--;
    if (width > 0 || !custom) {
      long int temp_e = 0;
      bool success = false;
      specs.width = width;
      add_integer(&temp_e, str, specs, &success);

      if (temp_e >= 0) *arg *= powf(10.0, temp_e);
      // while(temp_e--)
      // {
      // 	*arg= (double)*arg * (double)10.0;
      // }
      else
        while (temp_e++) {
          *arg = (float)*arg / (float)10.0;
        }
    }
  }
}

void add_integer(long int *arg, const char **str, options specs,
                 bool *success) {
  bool custom = false;
  if (specs.width > 0) custom = true;
  int sign = 1;
  if (**str == '-') {
    sign *= -1;
    (*str)++;
    if (specs.width) specs.width--;
  } else if (**str == '+') {
    (*str)++;
    if (specs.width) specs.width--;
  }
  ////printf("here %d %p\n", *arg, arg);
  if (specs.width || custom) {
    ////printf("1\n");
    if (**str >= '0' && **str <= '9') *arg = 0;
    while (specs.width-- && (**str >= '0' && **str <= '9'))
      if (((*arg * 10 + ((*(*str) + 1) - '0')) <= 65537) || !specs.h) {
        *arg = *arg * 10 + ((*(*str)++) - '0');
        *success = true;
      } else
        (*str)++;
  } else {
    ////printf("2 %d\n", *arg);
    if (**str >= '0' && **str <= '9') *arg = 0;
    ////printf("2.5 %d\n", *arg);
    while (**str >= '0' && **str <= '9') {
      // //printf("7 %d\n", ((*arg) ));
      if ((*arg * 10 + ((*(*str) + 1) - '0')) <= 65537) {
        // //printf("4\n");
        *arg = *arg * 10 + ((*(*str)++) - '0');
        *success = true;
        // //printf("%d\n", *arg);
      } else if (!specs.h) {
        // //printf("5\n");
        *arg = *arg * 10 + ((*(*str)++) - '0');
        *success = true;
        // if(specs.h)
        // 	//printf("%6d h\n", *arg);
      } else {  //(*str)++;
        // //printf("6\n");
        *arg = ((*arg * 10 + ((*(*str)++) - '0')) % 65536);
        *success = true;
      }
    }
    ////printf("3\n");
  }
  if (*success) *arg *= sign;
}

void add_oct(long int *arg, const char **str, s21_size_t width, bool *success) {
  bool custom = false;
  if (width > 0) custom = true;
  int sign = 1;
  if (**str == '-') {
    sign *= -1;
    (*str)++;
    if (width) width--;
  } else if (**str == '+') {
    (*str)++;
    if (width) width--;
  }

  if (**str == '0') {
    (*str)++;  // 0
    if (width) width--;
  }
  int i = 0;
  while ((width - i || !custom) && ((*str)[i] >= '0' && (*str)[i] <= '7')) i++;
  i--;
  if (width || custom) {
    if ((*str)[0] >= '0' && (*str)[0] <= '7') *arg = 0;
    for (; i + 1 && width-- && (**str >= '0' && **str <= '7'); i--) {
      *arg += ((*(*str)++) - '0') * pow(8, i);
      *success = true;
    }
  } else {
    if ((*str)[0] >= '0' && (*str)[0] <= '7') *arg = 0;
    for (; i + 1 && **str >= '0' && **str <= '7'; i--) {
      *arg += ((*(*str)++) - '0') * pow(8, i);
      *success = true;
    }
  }
  if (*success) *arg *= sign;
}

void add_hex_ldouble(long double *arg, const char **str, s21_size_t width,
                     bool custom, bool *success) {
  // bool custom = false;
  // if(width>0)
  // 	custom = true;
  int sign = 1;
  // printf("*arg 1->%Lf\n", *arg);
  if (*arg < 0.0 || (*arg == 0.0 && (**str == '.') && (*(*str - 3) == '-'))) {
    sign *= -1;
    if (*arg == 0.0) {
      *arg *= -1;
      *success = !*success;
    }
    *arg *= sign;
  } else if (*arg == 0.0 && (**str == '.'))
    *success = true;
  // printf("*arg 2->%Lf, %d\n", *arg, sign);

  if (width || !custom) {
    if (**str == '.') {
      (*str)++;
      if (width) width--;
    }
    int i = 0;
    while ((width - i || !custom) && (((*str)[i] >= '0' && (*str)[i] <= '9') ||
                                      ((*str)[i] >= 'a' && (*str)[i] <= 'f') ||
                                      ((*str)[i] >= 'A' && (*str)[i] <= 'F')))
      i++;
    // printf("i ->%d\n",i);
    //  i--;
    for (int j = 1; i - j + 1 && (((**str) >= '0' && (**str) <= '9') ||
                                  ((**str) >= 'a' && (**str) <= 'f') ||
                                  ((**str) >= 'A' && (**str) <= 'F'));
         j++) {
      // printf("i-j+1 ->%d str->%c\n",i-j+1, **str);
      if (!custom || width--) {
        int pow_i = j + 1;
        long double pow = 16;
        while (pow_i) {
          pow /= (long double)16;
          pow_i--;
          // printf("pow ->%Lf, pow_i->%d, width %ld\n", pow, pow_i, width);
        }
        *arg += hex_int(*(*str)++) * pow;
        // printf("arg ->%Lf\n", *arg);
        *success = true;
      }
      // printf("i-j+1 ->%d str->%c\n",i-j+1, **str);
    }
    // for(int i = 1; width && **str>= '0' && **str <= '9'; i++)
    // 	{
    // 		*arg = *arg + ((double)((*(*str)++) - '0'))/(double)(pow(10,i));
    // 		*success = true;
    // 		width--;
    // 	}
  }
  if (*success) *arg *= sign;
  // printf("*arg 3->%Lf\n", *arg);
}

void add_hex_double(double *arg, const char **str, s21_size_t width,
                    bool custom, bool *success) {
  // bool custom = false;
  // if(width>0)
  // 	custom = true;
  int sign = 1;
  // if(*success)
  // printf("success\n");
  // printf("*arg 1->%lf\n", *arg);
  if (*arg < 0.0 || (*arg == 0.0 && (**str == '.') && (*(*str - 3) == '-'))) {
    sign *= -1;
    if (*arg == 0.0) {
      *arg *= -1;
      *success = !*success;
    }
    *arg *= sign;
  } else if (*arg == 0.0 && (**str == '.'))
    *success = true;
  // printf("*arg 2->%lf, %d\n", *arg, sign);
  // if(*success)
  // printf("success\n");
  if (width || !custom) {
    if (**str == '.') {
      (*str)++;
      if (width) width--;
    }
    int i = 0;
    while ((width - i || !custom) && (((*str)[i] >= '0' && (*str)[i] <= '9') ||
                                      ((*str)[i] >= 'a' && (*str)[i] <= 'f') ||
                                      ((*str)[i] >= 'A' && (*str)[i] <= 'F')))
      i++;
    // printf("i ->%d\n",i);
    //  i--;
    for (int j = 1; i - j + 1 && (((**str) >= '0' && (**str) <= '9') ||
                                  ((**str) >= 'a' && (**str) <= 'f') ||
                                  ((**str) >= 'A' && (**str) <= 'F'));
         j++) {
      // printf("i-j+1 ->%d str->%c\n",i-j+1, **str);
      if (!custom || width--) {
        int pow_i = j + 1;
        double pow = 16;
        while (pow_i) {
          pow /= (double)16;
          pow_i--;
          // printf("pow ->%lf, pow_i->%d, width %ld\n", pow, pow_i, width);
        }
        *arg += hex_int(*(*str)++) * pow;
        // printf("arg ->%lf\n", *arg);
        *success = true;
      }
      // printf("i-j+1 ->%d str->%c\n",i-j+1, **str);
    }
    // for(int i = 1; width && **str>= '0' && **str <= '9'; i++)
    // 	{
    // 		*arg = *arg + ((double)((*(*str)++) - '0'))/(double)(pow(10,i));
    // 		*success = true;
    // 		width--;
    // 	}
  }
  if (*success) *arg *= sign;
  // if(*success)
  // printf("*arg 3->%lf\n", *arg);
}

void add_hex_float(float *arg, const char **str, s21_size_t width, bool custom,
                   bool *success) {
  // bool custom = false;
  // if(width>0)
  // 	custom = true;
  int sign = 1;
  // printf("*arg 1->%f\n", *arg);
  if (*arg < 0.0 || (*arg == 0.0 && (**str == '.') && (*(*str - 3) == '-'))) {
    sign *= -1;
    if (*arg == 0.0) {
      *arg *= -1;
      *success = !*success;
    }
    *arg *= sign;
  } else if (*arg == 0.0 && (**str == '.'))
    *success = true;
  // printf("*arg 2->%f, %d\n", *arg, sign);

  if (width || !custom) {
    if (**str == '.') {
      (*str)++;
      if (width) width--;
    }
    int i = 0;
    while ((width - i || !custom) && (((*str)[i] >= '0' && (*str)[i] <= '9') ||
                                      ((*str)[i] >= 'a' && (*str)[i] <= 'f') ||
                                      ((*str)[i] >= 'A' && (*str)[i] <= 'F')))
      i++;
    // printf("i ->%d\n",i);
    //  i--;
    for (int j = 1; i - j + 1 && (((**str) >= '0' && (**str) <= '9') ||
                                  ((**str) >= 'a' && (**str) <= 'f') ||
                                  ((**str) >= 'A' && (**str) <= 'F'));
         j++) {
      // printf("i-j+1 ->%d str->%c\n",i-j+1, **str);
      if (!custom || width--) {
        int pow_i = j + 1;
        float pow = 16;
        while (pow_i) {
          pow /= (float)16;
          pow_i--;
          // printf("pow ->%f, pow_i->%d, width %ld\n", pow, pow_i, width);
        }
        *arg += hex_int(*(*str)++) * pow;
        // printf("arg ->%f\n", *arg);
        *success = true;
      }
      // printf("i-j+1 ->%d str->%c\n",i-j+1, **str);
    }
    // for(int i = 1; width && **str>= '0' && **str <= '9'; i++)
    // 	{
    // 		*arg = *arg + ((double)((*(*str)++) - '0'))/(double)(pow(10,i));
    // 		*success = true;
    // 		width--;
    // 	}
  }
  if (*success) *arg *= sign;
  // printf("*arg 3->%f\n", *arg);
}

s21_size_t add_hex(long int *arg, const char **str, s21_size_t width,
                   bool *success) {
  bool custom = false;
  if (width > 0) custom = true;
  int sign = 1;
  if (**str == '-') {
    sign *= -1;
    (*str)++;
    if (width) width--;
  } else if (**str == '+') {
    (*str)++;
    if (width) width--;
  }

  if (**str == '0' && (*((*str) + 1) == 'x' || *((*str) + 1) == 'X')) {
    (*str)++;  // 0
    if (width) width--;

    (*str)++;  // x
    if (width) width--;
  }
  int i = 0;
  while ((width - i || !custom) && (((*str)[i] >= '0' && (*str)[i] <= '9') ||
                                    ((*str)[i] >= 'a' && (*str)[i] <= 'f') ||
                                    ((*str)[i] >= 'A' && (*str)[i] <= 'F')))
    i++;
  i--;

  if (width || custom) {
    if (((**str) >= '0' && (**str) <= '9') ||
        ((**str) >= 'a' && (**str) <= 'f') ||
        ((**str) >= 'A' && (**str) <= 'F'))
      *arg = 0;
    for (; i + 1 && width-- &&
           (((*str)[i] >= '0' && (*str)[i] <= '9') ||
            ((*str)[i] >= 'a' && (*str)[i] <= 'f') ||
            ((*str)[i] >= 'A' && (*str)[i] <= 'F'));
         i--) {
      *arg += hex_int((*(*str)++)) * pow(16, i);
      *success = true;
    }
  } else {
    if (((**str) >= '0' && (**str) <= '9') ||
        ((**str) >= 'a' && (**str) <= 'f') ||
        ((**str) >= 'A' && (**str) <= 'F'))
      *arg = 0;
    for (; i + 1 && (((*str)[i] >= '0' && (*str)[i] <= '9') ||
                     ((*str)[i] >= 'a' && (*str)[i] <= 'f') ||
                     ((*str)[i] >= 'A' && (*str)[i] <= 'F'));
         i--) {
      *arg += hex_int((*(*str)++)) * pow(16, i);
      *success = true;
    }
  }
  if (*success) *arg *= sign;
  // if(*success)
  // 	//printf("success\n");
  return width;
}

int hex_int(char hex) {
  int res = 0;
  if ((hex >= '0' && hex <= '9')) res = hex - '0';
  if ((hex >= 'a' && hex <= 'f')) res = hex - 'a' + 10;
  if ((hex >= 'A' && hex <= 'F')) res = hex - 'A' + 10;
  return res;
}

s21_size_t add_double(double *arg, const char **str, s21_size_t width,
                      bool *success) {
  double sign = 1;
  bool custom = width > 0;
  if (**str == '-') {
    sign *= -1;
    (*str)++;
    if (width) width--;
  } else if (**str == '+') {
    (*str)++;
    if (width) width--;
  }
  // printf("width %lu\n", width);
  if (width) {
    if ((**str >= '0' && **str <= '9') || **str == '.') *arg = 0;
    while (width && **str >= '0' && **str <= '9') {
      *arg = *arg * 10 + ((*(*str)++) - '0');
      *success = true;
      width--;
    }
    if (width && width-- && **str == '.') (*str)++;
    for (int i = 1; width && **str >= '0' && **str <= '9'; i++) {
      *arg = *arg + ((double)((*(*str)++) - '0')) / (double)(pow(10, i));
      *success = true;
      width--;
    }
  } else if (!custom) {
    if ((**str >= '0' && **str <= '9') || **str == '.') *arg = 0;
    while (**str >= '0' && **str <= '9') {
      *arg = *arg * 10 + ((*(*str)++) - '0');
      *success = true;
    }
    if (**str == '.') (*str)++;
    for (int i = 1; **str >= '0' && **str <= '9'; i++) {
      *arg = *arg + ((double)((*(*str)++) - '0')) / (double)(pow(10, i));
      *success = true;
    }
  }
  // printf("double->%lf\n", *arg);
  if (*success) *arg *= sign;
  // printf("double->%lf\n", *arg);
  return width;
}

s21_size_t add_ldouble(long double *arg, const char **str, s21_size_t width,
                       bool *success) {
  long double sign = 1;
  bool custom = width > 0;
  if (**str == '-') {
    sign *= -1;
    (*str)++;
    if (width) width--;
  } else if (**str == '+') {
    (*str)++;
    if (width) width--;
  }
  if (width) {
    if ((**str >= '0' && **str <= '9') || **str == '.') *arg = 0;
    while (width && **str >= '0' && **str <= '9') {
      *arg = *arg * 10 + ((*(*str)++) - '0');
      *success = true;
      width--;
    }
    if (width && width-- && **str == '.') (*str)++;
    for (int i = 1; width && **str >= '0' && **str <= '9'; i++) {
      *arg =
          *arg + ((long double)((*(*str)++) - '0')) / (long double)(pow(10, i));
      *success = true;
      width--;
    }
  } else if (!custom) {
    if ((**str >= '0' && **str <= '9') || **str == '.') *arg = 0;
    while (**str >= '0' && **str <= '9') {
      *arg = *arg * 10 + ((*(*str)++) - '0');
      *success = true;
    }
    if (**str == '.') (*str)++;
    for (int i = 1; **str >= '0' && **str <= '9'; i++) {
      *arg =
          *arg + ((long double)((*(*str)++) - '0')) / (long double)(pow(10, i));
      *success = true;
    }
  }
  if (*success) *arg *= sign;
  return width;
}

s21_size_t add_float(float *arg, const char **str, s21_size_t width,
                     bool *success) {
  float sign = 1;
  bool custom = width > 0;
  if (**str == '-') {
    if (width > 1) sign *= -1;
    (*str)++;
    if (width) width--;
  } else if (**str == '+') {
    (*str)++;
    if (width) width--;
  }
  if (width) {
    if ((**str >= '0' && **str <= '9') || **str == '.') *arg = 0;
    while (width && **str >= '0' && **str <= '9') {
      *arg = *arg * 10 + ((*(*str)++) - '0');
      *success = true;
      width--;
    }
    if (width && width-- && **str == '.') (*str)++;
    for (int i = 1; width && **str >= '0' && **str <= '9'; i++) {
      *arg = *arg + ((float)((*(*str)++) - '0')) / (float)(pow(10, i));
      *success = true;
      width--;
    }
  } else if (!custom) {
    if ((**str >= '0' && **str <= '9') || **str == '.') *arg = 0;
    while (**str >= '0' && **str <= '9') {
      *arg = *arg * 10 + ((*(*str)++) - '0');
      *success = true;
    }
    if (**str == '.') (*str)++;
    for (int i = 1; **str >= '0' && **str <= '9'; i++) {
      *arg = *arg + ((float)((*(*str)++) - '0')) / (float)(pow(10, i));
      *success = true;
    }
  }
  // if (!custom)
  // {
  *arg *= sign;
  // }
  // printf("float f ->%f\n", *arg);
  return width;
}