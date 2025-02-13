#include "s21_string_tests.h"

#include <math.h>

START_TEST(s21_strlen_test) {
  char test_1[] = "Hello";
  char test_2[] = "12345";
  char test_3[] = "1234\0";
  char test_4[] = "123\045";
  char test_5[] = "\012345";
  char test_6[] = " ";
  char test_7[] = "";
  char test_8[] = "\0";

  ck_assert_int_eq(s21_strlen(test_1), strlen(test_1));
  ck_assert_int_eq(s21_strlen(test_2), strlen(test_2));
  ck_assert_int_eq(s21_strlen(test_3), strlen(test_3));
  ck_assert_int_eq(s21_strlen(test_4), strlen(test_4));
  ck_assert_int_eq(s21_strlen(test_5), strlen(test_5));
  ck_assert_int_eq(s21_strlen(test_6), strlen(test_6));
  ck_assert_int_eq(s21_strlen(test_7), strlen(test_7));
  ck_assert_int_eq(s21_strlen(test_8), strlen(test_8));
}
END_TEST

START_TEST(s21_strncmp_test) {
  char test_1_str_1[] = "Hello";
  char test_1_str_2[] = "Hell0";

  char test_2_str_1[] = "Hello World";
  char test_2_str_2[] = "Hell0 W0rld";

  ck_assert_int_eq(s21_strncmp(test_1_str_1, test_1_str_2, 5) > 0,
                   strncmp(test_1_str_1, test_1_str_2, 5) > 0);
  ck_assert_int_eq(s21_strncmp(test_2_str_1, test_2_str_2, 11) > 0,
                   strncmp(test_2_str_1, test_2_str_2, 11) > 0);
  ck_assert_int_eq(s21_strncmp(test_1_str_1, test_1_str_2, 4) == 0,
                   strncmp(test_1_str_1, test_1_str_2, 4) == 0);
  ck_assert_int_eq(s21_strncmp(test_1_str_1, test_1_str_2, 0) == 0,
                   strncmp(test_2_str_1, test_2_str_2, 0) == 0);
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char test_1_str_1[] = "Implementation";
  char test_1_str_2[] = "qwnr";
  char test_1_str_3[] = "Implementation";
  char test_1_str_4[] = "qwnr";

  char *test_2_str_1 = "Implementation";
  char *test_2_str_2 = "";
  char *test_2_str_3 = "Implementation";
  char *test_2_str_4 = "";

  char *test_3_str_1 = "Implementation";
  char *test_3_str_2 = "\0";
  char *test_3_str_3 = "Implementation";
  char *test_3_str_4 = "\0";

  char *test_4_str_1 = "Impleme\0ntation";
  char *test_4_str_2 = "\0";
  char *test_4_str_3 = "Impleme\0ntation";
  char *test_4_str_4 = "\0";

  ck_assert_str_eq(s21_strpbrk(test_1_str_1, test_1_str_2),
                   strpbrk(test_1_str_3, test_1_str_4));
  ck_assert_int_eq((s21_size_t)s21_strpbrk(test_2_str_1, test_2_str_2),
                   (s21_size_t)strpbrk(test_2_str_3, test_2_str_4));
  ck_assert_pstr_eq(s21_strpbrk(test_3_str_1, test_3_str_2),
                    strpbrk(test_3_str_3, test_3_str_4));
  ck_assert_pstr_eq(s21_strpbrk(test_4_str_1, test_4_str_2),
                    strpbrk(test_4_str_3, test_4_str_4));
}
END_TEST

START_TEST(s21_strcspn_test) {
  char test_1_str_1[] = "Implementation";
  char test_1_str_2[] = "qwnr";

  char *test_2_str_1 = "Implementation";
  char *test_2_str_2 = "";

  char *test_3_str_1 = "Implementation";
  char *test_3_str_2 = "\0";

  char *test_4_str_1 = "Impleme\0ntation";
  char *test_4_str_2 = "\0";

  ck_assert_int_eq(s21_strcspn(test_1_str_1, test_1_str_2),
                   strcspn(test_1_str_1, test_1_str_2));
  ck_assert_int_eq(s21_strcspn(test_2_str_1, test_2_str_2),
                   strcspn(test_2_str_1, test_2_str_2));
  ck_assert_int_eq(s21_strcspn(test_3_str_1, test_3_str_2),
                   strcspn(test_3_str_1, test_3_str_2));
  ck_assert_int_eq(s21_strcspn(test_4_str_1, test_4_str_2),
                   strcspn(test_4_str_1, test_4_str_2));
}
END_TEST

START_TEST(s21_strchr_test) {
  char test_1_str_1[] = "Implementation";
  int test_1_str_2 = 110;
  char test_1_str_3[] = "Implementation";
  int test_1_str_4 = 110;

  char *test_2_str_1 = "Implementation";
  char test_2_str_2 = 'n';
  char *test_2_str_3 = "Implementation";
  char test_2_str_4 = 'n';

  char *test_3_str_1 = "Implementation";
  char test_3_str_2 = 'q';
  char *test_3_str_3 = "Implementation";
  char test_3_str_4 = 'q';

  char *test_4_str_1 = "Implementation";
  char test_4_str_2 = '\0';
  char *test_4_str_3 = "Implementation";
  char test_4_str_4 = '\0';

  char *test_5_str_1 = "Impleme\0ntation";
  char test_5_str_2 = '\0';
  char *test_5_str_3 = "Impleme\0ntation";
  char test_5_str_4 = '\0';

  ck_assert_str_eq(s21_strchr(test_1_str_1, test_1_str_2),
                   strchr(test_1_str_3, test_1_str_4));
  ck_assert_str_eq(s21_strchr(test_2_str_1, test_2_str_2),
                   strchr(test_2_str_3, test_2_str_4));
  ck_assert_pstr_eq(s21_strchr(test_3_str_1, test_3_str_2),
                    strchr(test_3_str_3, test_3_str_4));
  ck_assert_str_eq(s21_strchr(test_4_str_1, test_4_str_2),
                   strchr(test_4_str_3, test_4_str_4));
  ck_assert_str_eq(s21_strchr(test_5_str_1, test_5_str_2),
                   strchr(test_5_str_3, test_5_str_4));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char test_1_str_1[] = "Implementation";
  int test_1_str_2 = 110;
  char test_1_str_3[] = "Implementation";
  int test_1_str_4 = 110;

  char *test_2_str_1 = "Implementation";
  char test_2_str_2 = 'n';
  char *test_2_str_3 = "Implementation";
  char test_2_str_4 = 'n';

  char *test_3_str_1 = "Implementation";
  char test_3_str_2 = 'q';
  char *test_3_str_3 = "Implementation";
  char test_3_str_4 = 'q';

  char *test_4_str_1 = "Implementation";
  char test_4_str_2 = '\0';
  char *test_4_str_3 = "Implementation";
  char test_4_str_4 = '\0';

  char *test_5_str_1 = "Impleme\0ntation";
  char test_5_str_2 = '\0';
  char *test_5_str_3 = "Impleme\0ntation";
  char test_5_str_4 = '\0';

  ck_assert_str_eq(s21_strrchr(test_1_str_1, test_1_str_2),
                   strrchr(test_1_str_3, test_1_str_4));
  ck_assert_str_eq(s21_strrchr(test_2_str_1, test_2_str_2),
                   strrchr(test_2_str_3, test_2_str_4));
  ck_assert_pstr_eq(s21_strrchr(test_3_str_1, test_3_str_2),
                    strrchr(test_3_str_3, test_3_str_4));
  ck_assert_str_eq(s21_strrchr(test_4_str_1, test_4_str_2),
                   strrchr(test_4_str_3, test_4_str_4));
  ck_assert_str_eq(s21_strrchr(test_5_str_1, test_5_str_2),
                   strrchr(test_5_str_3, test_5_str_4));
}
END_TEST

START_TEST(s21_strncat_test) {
  char test_1_str_1[12] = "Hello";
  char test_1_str_2[7] = " World";
  char test_1_str_3[12] = "Hello";
  char test_1_str_4[7] = " World";

  char test_2_str_1[12] = "Hello";
  char test_2_str_2[7] = " World";
  char test_2_str_3[12] = "Hello";
  char test_2_str_4[7] = " World";

  char test_3_str_1[20] = "Hello";
  char test_3_str_2[] = " World";
  char test_3_str_3[20] = "Hello";
  char test_3_str_4[] = " World";

  char test_4_str_1[6] = "Hello";
  char test_4_str_2[] = "";
  char test_4_str_3[6] = "Hello";
  char test_4_str_4[] = "";

  ck_assert_str_eq(s21_strncat(test_1_str_1, test_1_str_2, 7),
                   strncat(test_1_str_3, test_1_str_4, 7));
  ck_assert_str_eq(s21_strncat(test_2_str_1, test_2_str_2, 3),
                   strncat(test_2_str_3, test_2_str_4, 3));
  ck_assert_str_eq(s21_strncat(test_3_str_1, test_3_str_2, 6),
                   strncat(test_3_str_3, test_3_str_4, 6));
  ck_assert_str_eq(s21_strncat(test_4_str_1, test_4_str_2, 6),
                   strncat(test_4_str_3, test_4_str_4, 6));
}
END_TEST

START_TEST(s21_strstr_test) {
  char test_1_str_1[] = "Implementation";
  char test_1_str_2[] = "men";
  char test_1_str_3[] = "Implementation";
  char test_1_str_4[] = "men";

  char test_2_str_1[] = "Implementation";
  char test_2_str_2[] = "nem";
  char test_2_str_3[] = "Implementation";
  char test_2_str_4[] = "nem";

  char test_3_str_1[] = "Implementation";
  char test_3_str_2[] = "\0";
  char test_3_str_3[] = "Implementation";
  char test_3_str_4[] = "\0";

  char test_4_str_1[] = "Implementation";
  char test_4_str_2[] = "";
  char test_4_str_3[] = "Implementation";
  char test_4_str_4[] = "";

  ck_assert_str_eq(s21_strstr(test_1_str_1, test_1_str_2),
                   strstr(test_1_str_3, test_1_str_4));
  ck_assert_pstr_eq(s21_strstr(test_2_str_1, test_2_str_2),
                    strstr(test_2_str_3, test_2_str_4));
  ck_assert_str_eq(s21_strstr(test_3_str_1, test_3_str_2),
                   strstr(test_3_str_3, test_3_str_4));
  ck_assert_str_eq(s21_strstr(test_4_str_1, test_4_str_2),
                   strstr(test_4_str_3, test_4_str_4));
}
END_TEST

START_TEST(s21_strncpy_test) {
  char test_1_str_1[6] = "";
  char test_1_str_2[] = "Hello";
  char test_1_str_3[6] = "";
  char test_1_str_4[] = "Hello";

  char test_2_str_1[4] = "";
  char test_2_str_2[] = "Hello";
  char test_2_str_3[4] = "";
  char test_2_str_4[] = "Hello";

  char test_3_str_1[10] = "";
  char test_3_str_2[] = "Hello";
  char test_3_str_3[10] = "";
  char test_3_str_4[] = "Hello";

  char test_4_str_1[10] = "";
  char test_4_str_2[] = "Hello";
  char test_4_str_3[10] = "";
  char test_4_str_4[] = "Hello";

  char test_5_str_1[] = "12345";
  char test_5_str_2[] = "Hello";
  char test_5_str_3[] = "12345";
  char test_5_str_4[] = "Hello";

  ck_assert_str_eq(s21_strncpy(test_1_str_1, test_1_str_2, 5),
                   strncpy(test_1_str_3, test_1_str_4, 5));
  ck_assert_str_eq(s21_strncpy(test_2_str_1, test_2_str_2, 3),
                   strncpy(test_2_str_3, test_2_str_4, 3));
  ck_assert_str_eq(s21_strncpy(test_3_str_1, test_3_str_2, 5),
                   strncpy(test_3_str_3, test_3_str_4, 5));
  ck_assert_str_eq(s21_strncpy(test_4_str_1, test_4_str_2, 9),
                   strncpy(test_4_str_3, test_4_str_4, 9));
  ck_assert_str_eq(s21_strncpy(test_5_str_1, test_5_str_2, 5),
                   strncpy(test_5_str_3, test_5_str_4, 5));
}
END_TEST

START_TEST(s21_strtok_test) {
  char test_1_str_1[] = "Happy_New+Year";
  char test_1_str_2[] = "+ _";
  char *test_1_result_1 = s21_strtok(test_1_str_1, test_1_str_2);

  char test_1_str_3[] = "Happy_New+Year";
  char test_1_str_4[] = "+ _";
  char *test_1_result_2 = strtok(test_1_str_3, test_1_str_4);

  while (test_1_result_1 != s21_NULL) {
    ck_assert_str_eq(test_1_result_1, test_1_result_2);
    test_1_result_1 = s21_strtok(s21_NULL, test_1_str_2);
    test_1_result_2 = strtok(s21_NULL, test_1_str_4);
  }
}
END_TEST

START_TEST(s21_to_lower_test) {
  char test_1_str_1[] = "HELLO";
  char *test_1_result = s21_to_lower(test_1_str_1);
  if (test_1_result != s21_NULL) {
    ck_assert_str_eq(test_1_result, "hello");
  }
  free(test_1_result);

  char test_4_str_1[] = "@AAAAA";
  char *test_4_result = s21_to_lower(test_4_str_1);
  if (test_4_result != s21_NULL) {
    ck_assert_str_eq(test_4_result, "@aaaaa");
  }
  free(test_4_result);

  char test_5_str_1[] = "ZZZZZ";
  char *test_5_result = s21_to_lower(test_5_str_1);
  if (test_5_result != s21_NULL) {
    ck_assert_str_eq(test_5_result, "zzzzz");
  }
  free(test_5_result);

  char test_2_str_1[] = "hElLo";
  char *test_2_result = s21_to_lower(test_2_str_1);
  if (test_2_result != s21_NULL) {
    ck_assert_str_eq(test_2_result, "hello");
  }
  free(test_2_result);

  char *test_3_str_1 = s21_NULL;
  char *test_3_result = s21_to_lower(test_3_str_1);
  ck_assert_ptr_null(test_3_result);
}
END_TEST

START_TEST(s21_to_upper_test) {
  char test_1_str_1[] = "hello";
  char *test_1_result = s21_to_upper(test_1_str_1);
  if (test_1_result != s21_NULL) {
    ck_assert_str_eq(test_1_result, "HELLO");
  }
  free(test_1_result);

  char test_2_str_1[] = "hElLo";
  char *test_2_result = s21_to_upper(test_2_str_1);
  if (test_2_result != s21_NULL) {
    ck_assert_str_eq(test_2_result, "HELLO");
  }
  free(test_2_result);

  char test_4_str_1[] = "aaaaa";
  char *test_4_result = s21_to_upper(test_4_str_1);
  if (test_4_result != s21_NULL) {
    ck_assert_str_eq(test_4_result, "AAAAA");
  }
  free(test_4_result);

  char test_5_str_1[] = "{zzzzz";
  char *test_5_result = s21_to_upper(test_5_str_1);
  if (test_5_result != s21_NULL) {
    ck_assert_str_eq(test_5_result, "{ZZZZZ");
  }
  free(test_5_result);

  char *test_3_str_1 = s21_NULL;
  char *test_3_result = s21_to_upper(test_3_str_1);
  ck_assert_ptr_null(test_3_result);
}
END_TEST

START_TEST(s21_trim_test) {
  char test_1_str_1[] = "+0qHello+0q";
  ;
  char test_1_str_2[] = "q0+";
  char *test_1_result = (char *)s21_trim(test_1_str_1, test_1_str_2);
  if (test_1_result != s21_NULL) {
    ck_assert_str_eq(test_1_result, "Hello");
  }
  free(test_1_result);

  char test_2_str_1[] = "+\t0qHello+0q";
  ;
  char test_2_str_2[] = "\tq0+";
  char *test_2_result = s21_trim(test_2_str_1, test_2_str_2);
  if (test_2_result != s21_NULL) {
    ck_assert_str_eq(test_2_result, "Hello");
  }
  free(test_2_result);

  char test_3_str_1[] = "+\t0qHello+0q";
  ;
  char test_3_str_2[] = "";
  char *test_3_result = s21_trim(test_3_str_1, test_3_str_2);
  if (test_3_result != s21_NULL) {
    ck_assert_str_eq(test_3_result, "+\t0qHello+0q");
  }
  free(test_3_result);

  char *test_4_str_1 = "";
  char test_4_str_2[] = "q0+";
  char *test_4_result = s21_trim(test_4_str_1, test_4_str_2);
  if (test_4_result != s21_NULL) {
    ck_assert_str_eq(test_4_result, "");
  }
  free(test_4_result);

  char *test_5_str_1 = s21_NULL;
  char test_5_str_2[] = "q0+";
  char *test_5_result = s21_trim(test_5_str_1, test_5_str_2);
  ck_assert_ptr_null(test_5_result);
}
END_TEST

START_TEST(s21_memcmp_test) {
  char test_1_str_1[] = "Implementation";
  char test_1_str_2[] = "Implementation";

  char test_2_str_1[] = "Implementation";
  char test_2_str_2[] = "Implenemtation";

  ck_assert_int_eq(s21_memcmp(test_1_str_1, test_1_str_2, 10),
                   memcmp(test_1_str_1, test_1_str_2, 10));
  ck_assert_int_eq(s21_memcmp(test_2_str_1, test_2_str_2, 10),
                   memcmp(test_2_str_1, test_2_str_2, 10));
}
END_TEST

START_TEST(s21_insert_test) {
  char test_1_str_1[] = "Happy  Year";
  char test_1_str_2[] = "New";

  char test_2_str_1[] = "Happy New";
  char test_2_str_2[] = " Year";

  char test_3_str_1[] = "Happy New";
  char test_3_str_2[] = " Null";

  char *res_test_1 = s21_insert(test_1_str_1, test_1_str_2, 6);
  char *res_test_2 = s21_insert(test_2_str_1, test_2_str_2, 9);
  char *res_test_3 = s21_insert(test_3_str_1, test_3_str_2, 20);

  ck_assert_str_eq(res_test_1, "Happy New Year");
  ck_assert_str_eq(res_test_2, "Happy New Year");
  ck_assert_ptr_null(res_test_3);

  free(res_test_1);
  free(res_test_2);
  free(res_test_3);
}
END_TEST

START_TEST(s21_memchr_test) {
  char test_1_str_1[] = "Implementation";
  char test_2_str_1[] = "Implementation";

  ck_assert_str_eq(s21_memchr(test_1_str_1, 'n', 10),
                   memchr(test_1_str_1, 'n', 10));
  ck_assert_pstr_eq(s21_memchr(test_2_str_1, 'q', 10),
                    memchr(test_2_str_1, 'q', 10));
}
END_TEST

START_TEST(s21_memcpy_test) {
  char test_1_str_1[6] = "";
  char test_1_str_2[] = "Hello";
  char test_1_str_3[6] = "";
  char test_1_str_4[] = "Hello";

  char test_2_str_1[4] = "";
  char test_2_str_2[] = "Hello";
  char test_2_str_3[4] = "";
  char test_2_str_4[] = "Hello";

  char test_3_str_1[10] = "";
  char test_3_str_2[] = "Hello";
  char test_3_str_3[10] = "";
  char test_3_str_4[] = "Hello";

  char test_4_str_1[10] = "";
  char test_4_str_2[] = "Hello";
  char test_4_str_3[10] = "";
  char test_4_str_4[] = "Hello";

  char test_5_str_1[] = "12345";
  char test_5_str_2[] = "Hello";
  char test_5_str_3[] = "12345";
  char test_5_str_4[] = "Hello";

  ck_assert_str_eq(s21_memcpy(test_1_str_1, test_1_str_2, 5),
                   memcpy(test_1_str_3, test_1_str_4, 5));
  ck_assert_str_eq(s21_memcpy(test_2_str_1, test_2_str_2, 3),
                   memcpy(test_2_str_3, test_2_str_4, 3));
  ck_assert_str_eq(s21_memcpy(test_3_str_1, test_3_str_2, 5),
                   memcpy(test_3_str_3, test_3_str_4, 5));
  ck_assert_str_eq(s21_memcpy(test_4_str_1, test_4_str_2, 5),
                   memcpy(test_4_str_3, test_4_str_4, 5));
  ck_assert_str_eq(s21_memcpy(test_5_str_1, test_5_str_2, 5),
                   memcpy(test_5_str_3, test_5_str_4, 5));
}
END_TEST

START_TEST(s21_memset_test) {
  char test_1_str_1[10];
  char test_2_str_1[10] = "Hello";
  char test_3_str_1[10] = "Hello";

  ck_assert_ptr_eq(s21_memset(test_1_str_1, 0, 10),
                   memset(test_1_str_1, 0, 10));
  ck_assert_ptr_eq(s21_memset(test_2_str_1, 0, 10),
                   memset(test_2_str_1, 0, 10));
  ck_assert_ptr_eq(s21_memset(test_3_str_1, 'q', 3),
                   memset(test_3_str_1, 'q', 3));
}
END_TEST

START_TEST(s21_strerror_test) {
  int test_1_err = 0;
  int test_2_err = 133;
  int test_3_err = 134;
  int test_4_err = -152;
  char *unknown_error = "Unknown error ";

  char *my_res_test_1 = s21_strerror(test_1_err);
  char *std_res_test_1 = strerror(test_1_err);
  ck_assert_str_eq(my_res_test_1, std_res_test_1);

  char *my_res_test_2 = s21_strerror(test_2_err);
  char *std_res_test_2 = strerror(test_2_err);
  ck_assert_str_eq(my_res_test_2, std_res_test_2);

  char *my_res_test_3 = s21_strerror(test_3_err);
  char *std_res_test_3 = (char *)calloc(100, sizeof(char));
  if (std_res_test_3 != s21_NULL) {
    sprintf(std_res_test_3, "%s%d", unknown_error, test_3_err);
    ck_assert_str_eq(my_res_test_3, std_res_test_3);
  }

  char *my_res_test_4 = s21_strerror(test_4_err);
  char *std_res_test_4 = (char *)calloc(100, sizeof(char));
  if (std_res_test_4 != s21_NULL) {
    sprintf(std_res_test_4, "%s%d", unknown_error, test_4_err);
    ck_assert_str_eq(my_res_test_4, std_res_test_4);
  }
  free(std_res_test_3);
  free(std_res_test_4);
}
END_TEST

// START_TEST(s21_sprintf_test) {
// 	double double_x =-2350.52346;
// 	double double_x = 55.0;
// 	double double_x[10] = {};
// 	unsigned int x = 17547823;
// 	char *x = "234adm132%%";
// 	int y = 145;
// 	char x  = 'G';
// 	char out[1000] = {0};
// 	char out2[1000] = {0};
// 	char *flags = "cdieEfgGosuxXpn%";
// 	char *specs = " -+0#";

// 	// s21_sprintf(out, "24bnxc  _ |%0 15.5f_asdjhj", x);
// 	// sprintf(out2, "24bnxc  _ |%0 15.5LF_asdjhj", x);
// 	// s21_sprintf(out, "24bnxc  _ |%% %%%- 15.5f_asdjhj",x);
// 	// sprintf(out2, "24bnxc  _ |%% %%%- 15.5LF_asdjhj",x);
// 	// s21_sprintf(out, "24bnxc  _ |%c_asdjhj", x);
// 	// sprintf(out2, "24bnxc  _ |%c_asdjhj", x);
// 	// s21_sprintf(out, "24bnxc  _ |%% %%%0 15d_asdjhj",x);
// 	// sprintf(out2, "24bnxc  _ |%% %%%0 15d_asdjhj",x);
// 	// s21_sprintf(out, "24bnxc  _ |%% %%%n_asdjhj",&y);
// 	// sprintf(out2, "24bnxc  _ |%% %%%n_asdjhj",&x);
// 	// printf("%d\n", y);
// 	// printf("%d\n", x);
// 	// s21_sprintf(out, "24bnxc  _ |%% %%%30p_asdjhj",&x);
// 	// sprintf(out2, "24bnxc  _ |%% %%%30p_asdjhj",&x);
// 	s21_sprintf(out, "24bnxc  _ |%% %%%#30x_asdjhj",x);
// 	sprintf(out2, "24bnxc  _ |%% %%%#30x_asdjhj",x);
// 	// s21_sprintf(out, "24bnxc  _ |%% %%%s_asdjhj",x);
// 	// sprintf(out2, "24bnxc  _ |%% %%%s_asdjhj",x);
// 	// s21_sprintf(out, "24bnxc  _ |%% %%%030u_asdjhj",x);
// 	// sprintf(out2, "24bnxc  _ |%% %%%030u_asdjhj",x);
// 	// s21_sprintf(out, "24bnxc  _ |%% %%%-#30o_asdjhj",x);
// 	// sprintf(out2, "24bnxc  _ |%% %%%-#30o_asdjhj",x);
// 	//s21_sprintf(out, "24bnxc  _ |%% %%%030.6e_asdjhj",x);
// 	//sprintf(out2, "24bnxc  _ |%% %%%030.6e_asdjhj",x);
// 	// s21_sprintf(out, "24bnxc  _ |%% %%%-15.1f_asdjhj",x);
// 	// sprintf(out2, "24bnxc  _ |%% %%%-15.1f_asdjhj",x);
// 	// printf("f -> s21->%s\n", out);
// 	// printf("f -> std->%s\n", out2);
// 	// s21_sprintf(out, "24bnxc  _ |%% %%%-15.1e_asdjhj",x);
// 	// sprintf(out2, "24bnxc  _ |%% %%%-15.1e_asdjhj",x);
// 	// printf("e -> s21->%s\n", out);
// 	// printf("e -> std->%s\n", out2);
// 	// s21_sprintf(out, "24bnxc  _ |%% %%%-#.2g_asdjhj",x);
// 	// sprintf(out2, "24bnxc  _ |%% %%%-#.2g_asdjhj",x);
// 	// s21_sprintf(out, "24bnxc  _ |%% %%%- 15i_asdjhj",x);
// 	// sprintf(out2, "24bnxc  _ |%% %%%- 15i_asdjhj",x);

// 	ck_assert_str_eq(s21_sprintf(test_1_err), sprintf(test_1_err));
// 	ck_assert_str_eq(s21_sprintf(test_2_err), sprintf(test_2_err));
// 	ck_assert_str_eq(s21_sprintf(test_3_err), sprintf(test_3_err));
// }
// END_TEST
START_TEST(sprintf_ints) {
  int str_size = 10000;
  char *my_str = (char *)calloc(str_size, sizeof(char));
  char *std_str = (char *)calloc(str_size, sizeof(char));

  if (my_str != s21_NULL && std_str != s21_NULL) {
    int my_res, std_res;
    wint_t wc = 0;

    my_res = s21_sprintf(my_str, "%d   aaaa %ld %hd    %hd", 60000000,
                         3000000000000, (short)1000000000, (short)2000000000);
    std_res = sprintf(std_str, "%d   aaaa %ld %hd    %hd", 60000000,
                      3000000000000, (short)1000000000, (short)2000000000);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%d   aaaa %ld %hd    %hd", 60000000,
                         3000000000000, (short)1000000000, (short)2000000000);
    std_res = sprintf(std_str, "%d   aaaa %ld %hd    %hd", 60000000,
                      3000000000000, (short)1000000000, (short)2000000000);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%d   aaaa %ld %hd    %hd", -50000,
                         -3000000000, (short)-10, (short)-2000000);
    std_res = sprintf(std_str, "%d   aaaa %ld %hd    %hd", -50000, -3000000000,
                      (short)-10, (short)-2000000);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%+d   aaaa % d", 50000, 3000000);
    std_res = sprintf(std_str, "%+d   aaaa % d", 50000, 3000000);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%d   aaaa %5ld %-4hd    %0hd", -50000,
                         -3000000000, (short)-10, (short)-2000000);
    std_res = sprintf(std_str, "%d   aaaa %5ld %-4hd    %0hd", -50000,
                      -3000000000, (short)-10, (short)-2000000);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%d   aaaa %li %hi    %hi", 700000000,
                         4000000000000, (short)10000, (short)500000000);
    std_res = sprintf(std_str, "%d   aaaa %li %hi    %hi", 700000000,
                      4000000000000, (short)10000, (short)500000000);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%-#o", -10010);
    std_res = sprintf(std_str, "%-#o", -10010);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%-#.o %-#.5o %-#10o %-#.100o", -10010, -10010,
                         -10010, -10010);
    std_res = sprintf(std_str, "%-#.o %-#.5o %-#10o %-#.100o", -10010, -10010,
                      -10010, -10010);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%lc", wc);
    std_res = sprintf(std_str, "%lc", wc);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%c %%", 'a');
    std_res = sprintf(std_str, "%c %%", 'a');
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);
  } else {
    printf("alloc error");
  }

  free(my_str);
  free(std_str);
}
END_TEST

START_TEST(sprintf_special) {
  char my_str[400] = {0};
  char std_str[400] = {0};
  char *format = "test: %Lg!\ntest: %Lg!\n";
  long double num = NAN;
  long double num1 = 1.;
  int width = 5, prec = 2;
  long double float_f = 123456.123456;
  // не может вывести nan на первом месте, ломается функция и выводит ?
  int my_res = s21_sprintf(my_str, format, num, num1);
  int std_res = sprintf(std_str, format, num, num1);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_str, std_str);

  my_res =
      s21_sprintf(my_str, "24bnxc  _ |%*.*Lf_asdjhj", width, prec, float_f);
  std_res = sprintf(std_str, "24bnxc  _ |%*.*Lf_asdjhj", width, prec, float_f);
  ck_assert_int_eq(my_res, std_res);
  ck_assert_str_eq(my_str, std_str);
}
END_TEST

START_TEST(sprintf_floats) {
  int str_size = 10000;
  char *my_str = (char *)calloc(str_size, sizeof(char));
  char *std_str = (char *)calloc(str_size, sizeof(char));
  if (my_str != s21_NULL && std_str != s21_NULL) {
    int my_res, std_res;

    my_res = s21_sprintf(my_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", 1.4, 1.5, 1.6,
                         14.7, 13.8, 12.9, 2.32424, 3.2352, 2234.4);
    std_res = sprintf(std_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", 1.4, 1.5, 1.6,
                      14.7, 13.8, 12.9, 2.32424, 3.2352, 2234.4);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%#f%#e%#g%#2f%#2e%#2g%.2f%#.2e%#.2g", 1.4,
                         1.5, 1.6, 14.7, 13.8, 12.9, 2.32424, 3.2352, 2234.4);
    std_res = sprintf(std_str, "%#f%#e%#g%#2f%#2e%#2g%.2f%#.2e%#.2g", 1.4, 1.5,
                      1.6, 14.7, 13.8, 12.9, 2.32424, 3.2352, 2234.4);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    // g с пробелами
    my_res = s21_sprintf(my_str, "%.10e|%g|%20e|%2g|%.2f|%12e|%.2g", 1.5, 1.6,
                         13.8, 12.9, 2.32424, 3.2352, 2234.4);
    std_res = sprintf(std_str, "%.10e|%g|%20e|%2g|%.2f|%12e|%.2g", 1.5, 1.6,
                      13.8, 12.9, 2.32424, 3.2352, 2234.4);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", NAN, NAN, NAN,
                         NAN, NAN, NAN, NAN, NAN, NAN);
    std_res = sprintf(std_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", NAN, NAN, NAN,
                      NAN, NAN, NAN, NAN, NAN, NAN);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", -NAN, -NAN,
                         -NAN, -NAN, -NAN, -NAN, -NAN, -NAN, -NAN);
    std_res = sprintf(std_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", -NAN, -NAN, -NAN,
                      -NAN, -NAN, -NAN, -NAN, -NAN, -NAN);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", +NAN, +NAN,
                         +NAN, +NAN, +NAN, +NAN, +NAN, +NAN, +NAN);
    std_res = sprintf(std_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", +NAN, +NAN, +NAN,
                      +NAN, +NAN, +NAN, +NAN, +NAN, +NAN);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", INFINITY,
                         INFINITY, INFINITY, INFINITY, INFINITY, INFINITY,
                         INFINITY, INFINITY, INFINITY);
    std_res = sprintf(std_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", INFINITY,
                      INFINITY, INFINITY, INFINITY, INFINITY, INFINITY,
                      INFINITY, INFINITY, INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", -INFINITY,
                         -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY,
                         -INFINITY, -INFINITY, -INFINITY);
    std_res = sprintf(std_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", -INFINITY,
                      -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY,
                      -INFINITY, -INFINITY, -INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", +INFINITY,
                         +INFINITY, +INFINITY, +INFINITY, +INFINITY, +INFINITY,
                         +INFINITY, +INFINITY, +INFINITY);
    std_res = sprintf(std_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", +INFINITY,
                      +INFINITY, +INFINITY, +INFINITY, +INFINITY, +INFINITY,
                      +INFINITY, +INFINITY, +INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res =
        s21_sprintf(my_str, "%Lf%Le%Lg%2Lf%2Le%2Lg%.2Lf%.2Le%.2Lg", 1.4L, 1.5L,
                    1.6L, 14.7L, 13.8L, 12.9L, 2.32424L, 3.2352L, 2234.4L);
    std_res =
        sprintf(std_str, "%Lf%Le%Lg%2Lf%2Le%2Lg%.2Lf%.2Le%.2Lg", 1.4L, 1.5L,
                1.6L, 14.7L, 13.8L, 12.9L, 2.32424L, 3.2352L, 2234.4L);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%lf%le%lg%2lf%2le%2lg%.2lf%.2le%.2lg", 1.4,
                         1.5, 1.6, 14.7, 13.8, 12.9, 2.32424, 3.2352, 2234.4);
    std_res = sprintf(std_str, "%lf%le%lg%2lf%2le%2lg%.2lf%.2le%.2lg", 1.4, 1.5,
                      1.6, 14.7, 13.8, 12.9, 2.32424, 3.2352, 2234.4);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", -1.4, -1.5,
                         -1.6, -14.7, -13.8, -12.9, -2.32424, -3.2352, -2234.4);
    std_res = sprintf(std_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", -1.4, -1.5, -1.6,
                      -14.7, -13.8, -12.9, -2.32424, -3.2352, -2234.4);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res =
        s21_sprintf(my_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", -1.4, -1.5, -1.6,
                    -14.7, -13.8, -12.9, -2.32424, -3.2352, -2234.4e11);
    std_res = sprintf(std_str, "%f%e%g%2f%2e%2g%.2f%.2e%.2g", -1.4, -1.5, -1.6,
                      -14.7, -13.8, -12.9, -2.32424, -3.2352, -2234.4e11);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%Lf%Le%Lg%2Lf%2Le%2Lg%.2Lf%.2Le%.2Lg", -1.4L,
                         -1.5L, -1.6L, -14.7L, -13.8L, -12.9L, -2.32424L,
                         -3.2352L, -2234.4L);
    std_res =
        sprintf(std_str, "%Lf%Le%Lg%2Lf%2Le%2Lg%.2Lf%.2Le%.2Lg", -1.4L, -1.5L,
                -1.6L, -14.7L, -13.8L, -12.9L, -2.32424L, -3.2352L, -2234.4L);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res =
        s21_sprintf(my_str, "%lf%le%lg%2lf%2le%2lg%.2lf%.2le%.2lg", -1.4, -1.5,
                    -1.6, -14.7, -13.8, -12.9, -2.32424, -3.2352, -2234.4);
    std_res =
        sprintf(std_str, "%lf%le%lg%2lf%2le%2lg%.2lf%.2le%.2lg", -1.4, -1.5,
                -1.6, -14.7, -13.8, -12.9, -2.32424, -3.2352, -2234.4);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%0 1f %0 1lf", 0.1, 12345.0);
    std_res = sprintf(std_str, "%0 1f %0 1lf", 0.1, 12345.0);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%.0e %.0e", 0.1, 12345.0);
    std_res = sprintf(std_str, "%.0e %.0e", 0.1, 12345.0);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(
        my_str, "%0+1f %0+2f %0+3f %0+4f %0+5f %0+6f %0+7f %0+8f %0+9f %0+50f",
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    std_res = sprintf(
        std_str, "%0+1f %0+2f %0+3f %0+4f %0+5f %0+6f %0+7f %0+8f %0+9f %0+50f",
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%f %lf", NAN, INFINITY);
    std_res = sprintf(std_str, "%f %lf", NAN, INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%f %lf", -NAN, -INFINITY);
    std_res = sprintf(std_str, "%f %lf", -NAN, -INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "% f % lf", NAN, INFINITY);
    std_res = sprintf(std_str, "% f % lf", NAN, INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%+f %+lf", NAN, INFINITY);
    std_res = sprintf(std_str, "%+f %+lf", NAN, INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%0 10f %0 10lf", NAN, INFINITY);
    std_res = sprintf(std_str, "%0 10f %0 10lf", NAN, INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%010f %010lf", NAN, INFINITY);
    std_res = sprintf(std_str, "%010f %010lf", NAN, INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%0+10f %0+10lf", +NAN, +INFINITY);
    std_res = sprintf(std_str, "%0+10f %0+10lf", +NAN, +INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%0 10f %0 10lf", -NAN, -INFINITY);
    std_res = sprintf(std_str, "%0 10f %0 10lf", -NAN, -INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%0 10f %0 10lf", +NAN, +INFINITY);
    std_res = sprintf(std_str, "%0 10f %0 10lf", +NAN, +INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%0f %0lf", -NAN, -INFINITY);
    std_res = sprintf(std_str, "%0f %0lf", -NAN, -INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "% 0f % 0lf", NAN, INFINITY);
    std_res = sprintf(std_str, "% f % lf", NAN, INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%+0f %+0lf", NAN, INFINITY);
    std_res = sprintf(std_str, "%+0f %+0lf", NAN, INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%#.2g %#.2lg", 1.23e5, 1.23e5);
    std_res = sprintf(std_str, "%#.2g %#.2lg", 1.23e5, 1.23e5);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%.2g %.2lg", 1.23e5, 1.23e5);
    std_res = sprintf(std_str, "%.2g %.2lg", 1.23e5, 1.23e5);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%.2G %.2lG", 11111.23e5, 11111.23e-5);
    std_res = sprintf(std_str, "%.2G %.2lG", 11111.23e5, 11111.23e-5);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%01g %05g %010g", 1.1, -1.123, +1.12345);
    std_res = sprintf(std_str, "%01g %05g %010g", 1.1, -1.123, +1.12345);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%g %g %g", NAN, -NAN, +NAN);
    std_res = sprintf(std_str, "%g %g %g", NAN, -NAN, +NAN);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "% g % g % g", NAN, -NAN, +NAN);
    std_res = sprintf(std_str, "% g % g % g", NAN, -NAN, +NAN);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%+g %+g %+g", NAN, -NAN, +NAN);
    std_res = sprintf(std_str, "%+g %+g %+g", NAN, -NAN, +NAN);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%g %g %g", INFINITY, -INFINITY, +INFINITY);
    std_res = sprintf(std_str, "%g %g %g", INFINITY, -INFINITY, +INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "% g % g % g", INFINITY, -INFINITY, +INFINITY);
    std_res = sprintf(std_str, "% g % g % g", INFINITY, -INFINITY, +INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%+g %+g %+g", INFINITY, -INFINITY, +INFINITY);
    std_res = sprintf(std_str, "%+g %+g %+g", INFINITY, -INFINITY, +INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%G %G %G", NAN, -NAN, +NAN);
    std_res = sprintf(std_str, "%G %G %G", NAN, -NAN, +NAN);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "% G % G % G", NAN, -NAN, +NAN);
    std_res = sprintf(std_str, "% G % G % G", NAN, -NAN, +NAN);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%+G %+G %+G", NAN, -NAN, +NAN);
    std_res = sprintf(std_str, "%+G %+G %+G", NAN, -NAN, +NAN);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%G %G %G", INFINITY, -INFINITY, +INFINITY);
    std_res = sprintf(std_str, "%G %G %G", INFINITY, -INFINITY, +INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "% G % G % G", INFINITY, -INFINITY, +INFINITY);
    std_res = sprintf(std_str, "% G % G % G", INFINITY, -INFINITY, +INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%+G %+G %+G", INFINITY, -INFINITY, +INFINITY);
    std_res = sprintf(std_str, "%+G %+G %+G", INFINITY, -INFINITY, +INFINITY);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%+ G % +G", INFINITY, +INFINITY);
    // std_res = sprintf(std_str, "%+ G % +G", INFINITY, +INFINITY);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%G %G %G", 1.1, -1.123, +1.1234);
    std_res = sprintf(std_str, "%G %G %G", 1.1, -1.123, +1.1234);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%G %G %G", 005, 0007, 0007);
    // std_res = sprintf(std_str, "%G %G %G", 005, 0007, 0007);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "% G % G % G", 1.1, -1.123, +1.1234);
    std_res = sprintf(std_str, "% G % G % G", 1.1, -1.123, +1.1234);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%+G %+G %+G", 1.1, -1.123, +1.1234);
    std_res = sprintf(std_str, "%+G %+G %+G", 1.1, -1.123, +1.1234);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);
    // important -0.0 теряется знак
    // my_res = s21_sprintf(my_str, "%.5f %.6f %.7f", 0, -0, +0);
    // std_res = sprintf(std_str, "%.5f %.6f %.7f", 0, -0, +0);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);
    // g 0.0 segmentation fault
    // my_res = s21_sprintf(my_str, "%.5G %.6G %.7G", 0, -0, +0);
    // std_res = sprintf(std_str, "%.5G %.6G %.7G", 0, -0, +0);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%G %g %2G %2g %3G %3g %4G %4g %0G %0g",
                         00.002, 00.002, 00.002, 00.002, 00.002, 00.002, 00.002,
                         00.002, 00.002, 00.002);
    std_res = sprintf(std_str, "%G %g %2G %2g %3G %3g %4G %4g %0G %0g", 00.002,
                      00.002, 00.002, 00.002, 00.002, 00.002, 00.002, 00.002,
                      00.002, 00.002);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(
        my_str, "%15.1e %015.1e % 015.1e %+015.e %-15.e %0.5e %0.2e", 1.1e+1,
        1.1e+1, -1.1e-1, 1.1e+1, 1.1e+1, -1.1e+5, +1.1e+5);
    std_res =
        sprintf(std_str, "%15.1e %015.1e % 015.1e %+015.e %-15.e %0.5e %0.2e",
                1.1e+1, 1.1e+1, -1.1e-1, 1.1e+1, 1.1e+1, -1.1e+5, +1.1e+5);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%e %e %e %e %e %e", 0.0e10, 0.0e15,
                         2000000000.0e-10, 2000000000.0e10, 2.0e-1, 0.1);
    std_res = sprintf(std_str, "%e %e %e %e %e %e", 0.0e10, 0.0e15,
                      2000000000.0e-10, 2000000000.0e10, 2.0e-1, 0.1);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%E %E %E %E %E %E", 0.0e10, 0.0e15,
                         2000000000.0e-10, 2000000000.0e10, 2.0e-1, 0.1);
    std_res = sprintf(std_str, "%E %E %E %E %E %E", 0.0e10, 0.0e15,
                      2000000000.0e-10, 2000000000.0e10, 2.0e-1, 0.1);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%e %e", 0.0, 0.0e+0);
    std_res = sprintf(std_str, "%e %e", 0.0, 0.0e+0);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%0 15e %0 15e", 0.0, 0.0e+0);
    std_res = sprintf(std_str, "%0 15e %0 15e", 0.0, 0.0e+0);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%e %e", 1.0, -1.0);
    std_res = sprintf(std_str, "%e %e", 1.0, -1.0);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%f %f", 0.1, -0.1);
    std_res = sprintf(std_str, "%f %f", 0.1, -0.1);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%f %f", .1, -.1);
    std_res = sprintf(std_str, "%f %f", .1, -.1);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%f %.f", 0xff.ffp0, 0xff.ffp0);
    std_res = sprintf(std_str, "%f %.f", 0xff.ffp0, 0xff.ffp0);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%3.3f", 899999.89999);
    std_res = sprintf(std_str, "%3.3f", 899999.89999);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%f", 9.9999999);
    std_res = sprintf(std_str, "%f", 9.9999999);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%0 f %0 f", 0.1, -0.1);
    std_res = sprintf(std_str, "%0 f %0 f", 0.1, -0.1);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%0 20f %0 20f", .1, -.1);
    std_res = sprintf(std_str, "%0 20f %0 20f", .1, -.1);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%0+f %0+f", 0.1, -0.1);
    std_res = sprintf(std_str, "%0+f %0+f", 0.1, -0.1);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%0+20f %0+20f", .1, -.1);
    std_res = sprintf(std_str, "%0+20f %0+20f", .1, -.1);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%0 15f %015f %0f", 1.1111111, +1.1111111,
                         -1.1111111);
    std_res =
        sprintf(std_str, "%0 15f %015f %0f", 1.1111111, +1.1111111, -1.1111111);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

  } else {
    printf("alloc error");
  }

  free(my_str);
  free(std_str);
}
END_TEST

START_TEST(sprintf_strings) {
  int str_size = 10000;
  char *my_str = (char *)calloc(str_size, sizeof(char));
  char *std_str = (char *)calloc(str_size, sizeof(char));
  if (my_str != s21_NULL && std_str != s21_NULL) {
    int my_res, std_res;

    my_res = s21_sprintf(my_str, "%10s", "Hello, world!");
    std_res = sprintf(std_str, "%10s", "Hello, world!");
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%100s", "Hello, world!");
    std_res = sprintf(std_str, "%100s", "Hello, world!");
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%j", "Hello, world!");
    // std_res = sprintf(std_str, "%j", "Hello, world!");
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

  } else {
    printf("alloc error");
  }

  free(my_str);
  free(std_str);
}
END_TEST

START_TEST(sprintf_pointers) {
  int str_size = 10000;
  char *my_str = (char *)calloc(str_size, sizeof(char));
  char *std_str = (char *)calloc(str_size, sizeof(char));
  if (my_str != s21_NULL && std_str != s21_NULL) {
    int my_res, std_res;

    my_res = s21_sprintf(my_str, "%20p", "Hello, world!");
    std_res = sprintf(std_str, "%20p", "Hello, world!");
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

  } else {
    printf("alloc error");
  }

  free(my_str);
  free(std_str);
}
END_TEST

START_TEST(sprintf_hex) {
  int str_size = 10000;
  char *my_str = (char *)calloc(str_size, sizeof(char));
  char *std_str = (char *)calloc(str_size, sizeof(char));
  if (my_str != s21_NULL && std_str != s21_NULL) {
    unsigned int u_i_x = 1000000;
    unsigned short u_s_x = 1000;
    unsigned long u_l_x = 10000000000;
    int my_res = 0, std_res = 0;

    my_res = s21_sprintf(my_str, "%#x %#X %x %X %#x %#X %x %X", 0x0, 0x0, 0x0,
                         0x0, -0x0, -0x0, -0x0, -0x0);
    std_res = sprintf(std_str, "%#x %#X %x %X %#x %#X %x %X", 0x0, 0x0, 0x0,
                      0x0, -0x0, -0x0, -0x0, -0x0);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%#x %#X %x %X %0#x %0#X %x %X", 0x123, 0x123,
                         0x123, 0X123, -0x123, -0X123, -0x123, -0X123);
    std_res = sprintf(std_str, "%#x %#X %x %X %0#x %0#X %x %X", 0x123, 0x123,
                      0x123, 0X123, -0x123, -0X123, -0x123, -0X123);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res =
        s21_sprintf(my_str, "%#20x %#20X %20x %20X %0#20x %0#20X %20x %20X",
                    0x123, 0x123, 0x123, 0X123, -0x123, -0X123, -0x123, -0X123);
    std_res =
        sprintf(std_str, "%#20x %#20X %20x %20X %0#20x %0#20X %20x %20X", 0x123,
                0x123, 0x123, 0X123, -0x123, -0X123, -0x123, -0X123);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(
        my_str, "%#-20x %#-20X %-20x %-20X %#-20x %#-20X %-20x %-20X", 0x123,
        0x123, 0x123, 0X123, -0x123, -0X123, -0x123, -0X123);
    std_res =
        sprintf(std_str, "%#-20x %#-20X %-20x %-20X %#-20x %#-20X %-20x %-20X",
                0x123, 0x123, 0x123, 0X123, -0x123, -0X123, -0x123, -0X123);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%#020x", 0.01);
    // std_res = sprintf(std_str, "%#020x", 0.01);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%#-20x", (unsigned int)NAN);
    // std_res = sprintf(std_str, "%#-20x", (unsigned int)NAN);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%#-20x", (unsigned int)-NAN);
    // std_res = sprintf(std_str, "%#-20x", (unsigned int)-NAN);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0-20x", +NAN);
    // std_res = sprintf(std_str, "%# 0-20x", +NAN);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%#-20x", (unsigned int)INFINITY);
    // std_res = sprintf(std_str, "%#-20x", (unsigned int)INFINITY);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0-20x", -INFINITY);
    // std_res = sprintf(std_str, "%# 0-20x", -INFINITY);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0-20x", +INFINITY);
    // std_res = sprintf(std_str, "%# 0-20x", +INFINITY);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0-20X", NAN);
    // std_res = sprintf(std_str, "%# 0-20X", NAN);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0-20X", -NAN);
    // std_res = sprintf(std_str, "%# 0-20X", -NAN);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0-20X", +NAN);
    // std_res = sprintf(std_str, "%# 0-20X", +NAN);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0-20X", INFINITY);
    // std_res = sprintf(std_str, "%# 0-20X", INFINITY);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0-20X", -INFINITY);
    // std_res = sprintf(std_str, "%# 0-20X", -INFINITY);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0-20X", +INFINITY);
    // std_res = sprintf(std_str, "%# 0-20X", +INFINITY);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0+20x", NAN);
    // std_res = sprintf(std_str, "%# 0+20x", NAN);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0+20x", -NAN);
    // std_res = sprintf(std_str, "%# 0+20x", -NAN);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0+20x", +NAN);
    // std_res = sprintf(std_str, "%# 0+20x", +NAN);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0+20x", INFINITY);
    // std_res = sprintf(std_str, "%# 0+20x", INFINITY);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0+20x", -INFINITY);
    // std_res = sprintf(std_str, "%# 0+20x", -INFINITY);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0+20x", +INFINITY);
    // std_res = sprintf(std_str, "%# 0+20x", +INFINITY);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0+20X", NAN);
    // std_res = sprintf(std_str, "%# 0+20X", NAN);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0+20X", -NAN);
    // std_res = sprintf(std_str, "%# 0+20X", -NAN);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0+20X", +NAN);
    // std_res = sprintf(std_str, "%# 0+20X", +NAN);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0+20X", INFINITY);
    // std_res = sprintf(std_str, "%# 0+20X", INFINITY);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0+20X", -INFINITY);
    // std_res = sprintf(std_str, "%# 0+20X", -INFINITY);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%# 0+20X", +INFINITY);
    // std_res = sprintf(std_str, "%# 0+20X", +INFINITY);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%#x %#X %x %X", "(nil)", "(nil)", "(nil)",
    //                      "(nil)");
    // std_res =
    //     sprintf(std_str, "%#x %#X %x %X", "(nil)", "(nil)", "(nil)",
    //     "(nil)");
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%x", s21_NULL);
    // std_res = sprintf(std_str, "%x", s21_NULL);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%0# 20X", s21_NULL);
    // std_res = sprintf(std_str, "%0# 20X", s21_NULL);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%x", u_i_x);
    std_res = sprintf(std_str, "%x", u_i_x);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%x", 0x0);
    std_res = sprintf(std_str, "%x", 0x0);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%x", 0);
    std_res = sprintf(std_str, "%x", 0);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%#X", u_i_x);
    std_res = sprintf(std_str, "%#X", u_i_x);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%#x", u_i_x);
    std_res = sprintf(std_str, "%#x", u_i_x);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%X", 0x0);
    std_res = sprintf(std_str, "%X", 0x0);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%X", 0);
    std_res = sprintf(std_str, "%X", 0);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%x", u_s_x);
    std_res = sprintf(std_str, "%x", u_s_x);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%lx", u_l_x);
    std_res = sprintf(std_str, "%lx", u_l_x);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%hx", u_i_x);
    // std_res = sprintf(std_str, "%hx", u_i_x);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%hx", u_s_x);
    std_res = sprintf(std_str, "%hx", u_s_x);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%lx", -u_l_x);
    std_res = sprintf(std_str, "%lx", -u_l_x);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%X", u_i_x);
    std_res = sprintf(std_str, "%X", u_i_x);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%X", u_s_x);
    std_res = sprintf(std_str, "%X", u_s_x);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%lX", u_l_x);
    std_res = sprintf(std_str, "%lX", u_l_x);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    // my_res = s21_sprintf(my_str, "%hX", u_i_x);
    // std_res = sprintf(std_str, "%hX", u_i_x);
    // ck_assert_str_eq(my_str, std_str);
    // ck_assert_int_eq(my_res, std_res);
    // memset(my_str, '\0', str_size);
    // memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%hX", u_s_x);
    std_res = sprintf(std_str, "%hX", u_s_x);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%lX", -u_l_x);
    std_res = sprintf(std_str, "%lX", -u_l_x);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

  } else {
    printf("alloc error");
  }

  free(my_str);
  free(std_str);
}
END_TEST

START_TEST(sprintf_n) {
  int str_size = 10000;
  int *n = (int *)calloc(str_size, sizeof(int));
  long int *l_n = (long int *)calloc(str_size, sizeof(long int));
  short int *s_n = (short int *)calloc(str_size, sizeof(short int));
  char *my_str = (char *)calloc(str_size, sizeof(char));
  char *std_str = (char *)calloc(str_size, sizeof(char));
  if (my_str != s21_NULL && std_str != s21_NULL && n != s21_NULL &&
      l_n != s21_NULL && s_n != s21_NULL) {
    int my_res, std_res;

    my_res = s21_sprintf(my_str, "%n", n);
    std_res = sprintf(std_str, "%n", n);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%ln", l_n);
    std_res = sprintf(std_str, "%ln", l_n);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%hn", s_n);
    std_res = sprintf(std_str, "%hn", s_n);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

  } else {
    printf("alloc error");
  }

  free(my_str);
  free(std_str);
  free(n);
  free(l_n);
  free(s_n);
}
END_TEST

START_TEST(sprintf_u) {
  int str_size = 10000;
  char *my_str = (char *)calloc(str_size, sizeof(char));
  char *std_str = (char *)calloc(str_size, sizeof(char));
  if (my_str != s21_NULL && std_str != s21_NULL) {
    unsigned int u = 1654198;
    s21_size_t l_u = 651984981968;
    unsigned short int s_u = 16541;
    int my_res, std_res;

    my_res = s21_sprintf(my_str, "%u", u);
    std_res = sprintf(std_str, "%u", u);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%lu", l_u);
    std_res = sprintf(std_str, "%lu", l_u);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%hu", s_u);
    std_res = sprintf(std_str, "%hu", s_u);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

  } else {
    printf("alloc error");
  }

  free(my_str);
  free(std_str);
}
END_TEST

START_TEST(sprintf_o) {
  int str_size = 10000;
  char *my_str = (char *)calloc(str_size, sizeof(char));
  char *std_str = (char *)calloc(str_size, sizeof(char));
  if (my_str != s21_NULL && std_str != s21_NULL) {
    unsigned int o = 4004570;
    s21_size_t l_o = 116234357600;
    unsigned short int s_o = 57540;
    int my_res, std_res;

    my_res = s21_sprintf(my_str, "%o", o);
    std_res = sprintf(std_str, "%o", o);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%o", 0);
    std_res = sprintf(std_str, "%o", 0);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%lo", l_o);
    std_res = sprintf(std_str, "%lo", l_o);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

    my_res = s21_sprintf(my_str, "%6ho", s_o);
    std_res = sprintf(std_str, "%6ho", s_o);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);

  } else {
    printf("alloc error");
  }

  free(my_str);
  free(std_str);
}
END_TEST

START_TEST(sscanf_strings_chars) {
  char *b1 = calloc(20, sizeof(char));
  char *b2 = calloc(20, sizeof(char));
  char *b3 = calloc(20, sizeof(char));
  char *b4 = calloc(20, sizeof(char));

  if (b1 && b2 && b3 && b4) {
    int std_ret = sscanf("abc cdef", "%20s %3s", b1, b2);
    int my_ret = s21_sscanf("abc cdef", "%20s %3s", b3, b4);
    ck_assert_int_eq(std_ret, my_ret);
    ck_assert_str_eq(b1, b3);
    ck_assert_str_eq(b2, b4);
    memset(b4, '\0', 20);
    memset(b3, '\0', 20);

    std_ret = sscanf("Hello", "Her %100s", b4);
    my_ret = s21_sscanf("Hello", "Her %100s", b3);
    ck_assert_int_eq(std_ret, my_ret);
    ck_assert_str_eq(b4, b3);
    memset(b4, '\0', 20);
    memset(b3, '\0', 20);

    std_ret = sscanf("Hello animal", "Hello  %100s", b4);
    my_ret = s21_sscanf("Hello animal", "Hello  %100s", b3);
    ck_assert_int_eq(std_ret, my_ret);
    ck_assert_str_eq(b4, b3);
    memset(b4, '\0', 20);
    memset(b3, '\0', 20);

    std_ret = sscanf("Hello animal", "Hello  %*c");
    my_ret = s21_sscanf("Hello animal", "Hello  %*c");
    ck_assert_int_eq(std_ret, my_ret);
    memset(b4, '\0', 20);
    memset(b3, '\0', 20);
  }

  free(b1);
  free(b2);
  free(b3);
  free(b4);

  char a1, a2, a3, a4;
  int std_ret = sscanf("ca", "%c%c", &a1, &a2);
  int my_ret = s21_sscanf("ca", "%c%c", &a3, &a4);

  ck_assert_int_eq(std_ret, my_ret);
  ck_assert(a1 == a3);
  ck_assert(a2 == a4);
}
END_TEST

START_TEST(sscanf_floats) {
  double a1 = -1, a2 = -1;
  float c1 = -1, c2 = -1;
  double d1 = -1, d2 = -1;
  long double e1 = -1, e2 = -1, e3 = -1, e4 = -1;
  // double f1 = -1, f2 = -1;

  int std_ret = sscanf("1.1e+1 1.1e+1 1e+1 -1.2e+1 1.1E-1", "%1le%f%lG%LG%1Le",
                       &a1, &c1, &d1, &e1, &e3);
  int my_ret = s21_sscanf("1.1e+1 1.1e+1 1e+1 -1.2e+1 1.1E-1",
                          "%1le%f%lG%LG%1Le", &a2, &c2, &d2, &e2, &e4);
  ck_assert_double_eq_tol(a1, a2, 0.1);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_ldouble_eq_tol(e3, e4, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("0X1 0X1 0X1", "%2f %2lf %2Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("0X1 0X1 0X1", "%2f %2lf %2Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("0Y1 0Y1 0Y1", "%2f %2lf %2Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("0Y1 0Y1 0Y1", "%2f %2lf %2Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("0x1 0x1 0x1", "%3f %3lf %3Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("0x1 0x1 0x1", "%3f %3lf %3Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("+0x1 +0x1 +0x1", "%3f %3lf %3Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("+0x1 +0x1 +0x1", "%3f %3lf %3Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-0x1 -0x1 -0x1", "%3f %3lf %3Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("-0x1 -0x1 -0x1", "%3f %3lf %3Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("+0X1 +0X1 +0X1", "%2f %2lf %2Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("+0X1 +0X1 +0X1", "%2f %2lf %2Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-0Y1 -0Y1 -0Y1", "%2f %2lf %2Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("-0Y1 -0Y1 -0Y1", "%2f %2lf %2Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("0x1 0x1 0x1", "%4f %4lf %4Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("0x1 0x1 0x1", "%4f %4lf %4Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("+0x1 +0x1 +0x1", "%4f %4lf %4Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("+0x1 +0x1 +0x1", "%4f %4lf %4Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-0x1 -0x1 -0x1", "%4f %4lf %4Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("-0x1 -0x1 -0x1", "%4f %4lf %4Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("1.1 1.1 1.1", "%2f %2lf %2Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("1.1 1.1 1.1", "%2f %2lf %2Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("1.1 1.1 1.1", "%2f %2lf %2Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("1.1 1.1 1.1", "%2f %2lf %2Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("1.1 1.1 1.1", "%3f %3lf %3Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("1.1 1.1 1.1", "%3f %3lf %3Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("+1.1 +1.1 +1.1", "%3f %3lf %3Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("+1.1 +1.1 +1.1", "%3f %3lf %3Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-1.1 -1.1 -1.1", "%3f %3lf %3Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("-1.1 -1.1 -1.1", "%3f %3lf %3Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("+1.1 +1.1 +1.1", "%2f %2lf %2Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("+1.1 +1.1 +1.1", "%2f %2lf %2Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-1.1 -1.1 -1.1", "%2f %2lf %2Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("-1.1 -1.1 -1.1", "%2f %2lf %2Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("1.1 1.1 1.1", "%4f %4lf %4Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("1.1 1.1 1.1", "%4f %4lf %4Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("+1.1 +1.1 +1.1", "%4f %4lf %4Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("+1.1 +1.1 +1.1", "%4f %4lf %4Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-1.1 -1.1 -1.1", "%4f %4lf %4Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("-1.1 -1.1 -1.1", "%4f %4lf %4Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-1.1 -1.1 -1.1", "%1f %1lf %1Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("-1.1 -1.1 -1.1", "%1f %1lf %1Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-1.1", "%*1f");
  my_ret = s21_sscanf("-1.1", "%*1f");
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("1.1", "%*1f");
  my_ret = s21_sscanf("1.1", "%*1f");
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-1.1", "%*f");
  my_ret = s21_sscanf("-1.1", "%*f");
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("1.1", "%*f");
  my_ret = s21_sscanf("1.1", "%*f");
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("0x11 0x11 0x11", "%1f %1lf %1Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("0x11 0x11 0x11", "%1f %1lf %1Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-0x0.0 -0x0.0 -0x0.0", "%1f %1lf %1Lf", &c1, &d1, &e1);
  my_ret = s21_sscanf("-0x0.0 -0x0.0 -0x0.0", "%1f %1lf %1Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("0xAF.FA 0xAF.BC 0xAF.DEaf", "%5f %5lf %5Lf", &c1, &d1, &e1);
  my_ret =
      s21_sscanf("0xAF.FA 0xAF.BC 0xAF.DEaf", "%5f %5lf %5Lf", &c2, &d2, &e2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  // std_ret = sscanf("0xAF.FA 0xAF.BC 0xAF.DEaf", "%f %lf %Lf", &c1, &d1, &e1);
  // my_ret = s21_sscanf("0xAF.FA 0xAF.BC 0xAF.DEaf", "%f %lf %Lf", &c2, &d2,
  // &e2); ck_assert_float_eq_tol(c1, c2, 0.1); ck_assert_double_eq_tol(d1, d2,
  // 0.1); ck_assert_ldouble_eq_tol(e1, e2, 0.1); ck_assert_int_eq(std_ret,
  // my_ret);

  std_ret = sscanf("0xAF.DEaf", "%5Lf", &e1);
  my_ret = s21_sscanf("0xAF.DEaf", "%5Lf", &e2);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("0xAF.DEaf", "%5lf", &d1);
  my_ret = s21_sscanf("0xAF.DEaf", "%5lf", &d2);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("0xAF.DEaf", "%5f", &c1);
  my_ret = s21_sscanf("0xAF.DEaf", "%5f", &c2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("0xAF.DEaf", "%6Lf", &e1);
  my_ret = s21_sscanf("0xAF.DEaf", "%6Lf", &e2);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("0xAF.DEaf", "%6lf", &d1);
  my_ret = s21_sscanf("0xAF.DEaf", "%6lf", &d2);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("0xAF.DEaf", "%6f", &c1);
  my_ret = s21_sscanf("0xAF.DEaf", "%6f", &c2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-0xAF.DEaf", "%5Lf", &e1);
  my_ret = s21_sscanf("-0xAF.DEaf", "%5Lf", &e2);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("-0xAF.DEaf", "%5lf", &d1);
  my_ret = s21_sscanf("-0xAF.DEaf", "%5lf", &d2);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("-0xAF.DEaf", "%5f", &c1);
  my_ret = s21_sscanf("-0xAF.DEaf", "%5f", &c2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-0xAF.DEaf", "%6Lf", &e1);
  my_ret = s21_sscanf("-0xAF.DEaf", "%6Lf", &e2);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("-0xAF.DEaf", "%6lf", &d1);
  my_ret = s21_sscanf("-0xAF.DEaf", "%6lf", &d2);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("-0xAF.DEaf", "%6f", &c1);
  my_ret = s21_sscanf("-0xAF.DEaf", "%6f", &c2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-0xAF.DEaf", "%7Lf", &e1);
  my_ret = s21_sscanf("-0xAF.DEaf", "%7Lf", &e2);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("-0xAF.DEaf", "%7lf", &d1);
  my_ret = s21_sscanf("-0xAF.DEaf", "%7lf", &d2);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("-0xAF.DEaf", "%7f", &c1);
  my_ret = s21_sscanf("-0xAF.DEaf", "%7f", &c2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("+0xAF.DEaf", "%5Lf", &e1);
  my_ret = s21_sscanf("+0xAF.DEaf", "%5Lf", &e2);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("+0xAF.DEaf", "%5lf", &d1);
  my_ret = s21_sscanf("+0xAF.DEaf", "%5lf", &d2);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("+0xAF.DEaf", "%5f", &c1);
  my_ret = s21_sscanf("+0xAF.DEaf", "%5f", &c2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("+0xAF.DEaf", "%6Lf", &e1);
  my_ret = s21_sscanf("+0xAF.DEaf", "%6Lf", &e2);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("+0xAF.DEaf", "%6lf", &d1);
  my_ret = s21_sscanf("+0xAF.DEaf", "%6lf", &d2);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("+0xAF.DEaf", "%6f", &c1);
  my_ret = s21_sscanf("+0xAF.DEaf", "%6f", &c2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  // std_ret = sscanf("+0xAF.DEaf", "%*Lf", &e1);
  // my_ret = s21_sscanf("+0xAF.DEaf", "%*Lf", &e2);
  // ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  // ck_assert_int_eq(std_ret, my_ret);
  // std_ret = sscanf("+0xAF.DEaf", "%*lf", &d1);
  // my_ret = s21_sscanf("+0xAF.DEaf", "%*lf", &d2);
  // ck_assert_double_eq_tol(d1, d2, 0.1);
  // ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("+0xAF.DEaf", "%*f");
  my_ret = s21_sscanf("+0xAF.DEaf", "%*f");
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("+0x09AFafg", "%Lf", &e1);
  my_ret = s21_sscanf("+0x09AFafg", "%Lf", &e2);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("+0x09AFafg", "%lf", &d1);
  my_ret = s21_sscanf("+0x09AFafg", "%lf", &d2);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("+0x09AFafg", "%f", &c1);
  my_ret = s21_sscanf("+0x09AFafg", "%f", &c2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-0x09AFafg", "%Lf", &e1);
  my_ret = s21_sscanf("-0x09AFafg", "%Lf", &e2);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("-0x09AFafg", "%lf", &d1);
  my_ret = s21_sscanf("-0x09AFafg", "%lf", &d2);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("-0x09AFafg", "%f", &c1);
  my_ret = s21_sscanf("-0x09AFafg", "%f", &c2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("+0x.09AFafg", "%Lf", &e1);
  my_ret = s21_sscanf("+0x.09AFafg", "%Lf", &e2);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("+0x.09AFafg", "%lf", &d1);
  my_ret = s21_sscanf("+0x.09AFafg", "%lf", &d2);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("+0x.09AFafg", "%f", &c1);
  my_ret = s21_sscanf("+0x.09AFafg", "%f", &c2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  std_ret = sscanf("-0x.09AFafg", "%Lf", &e1);
  my_ret = s21_sscanf("-0x.09AFafg", "%Lf", &e2);
  ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("-0x.09AFafg", "%lf", &d1);
  my_ret = s21_sscanf("-0x.09AFafg", "%lf", &d2);
  ck_assert_double_eq_tol(d1, d2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);
  std_ret = sscanf("-0x.09AFafg", "%f", &c1);
  my_ret = s21_sscanf("-0x.09AFafg", "%f", &c2);
  ck_assert_float_eq_tol(c1, c2, 0.1);
  ck_assert_int_eq(std_ret, my_ret);

  // std_ret = sscanf("1 -0x.09AFafg", "%f %.*Lf", &c1, &e1);
  // my_ret = s21_sscanf("1 -0x.09AFafg", "%f %.*Lf", &c2, &e2);
  // ck_assert_ldouble_eq_tol(e1, e2, 0.1);
  // ck_assert_int_eq(std_ret, my_ret);

  // std_ret = sscanf("-0x.09AFafg", "%.*lf", &d1);
  // my_ret = s21_sscanf("-0x.09AFafg", "%.*lf", &d2);
  // ck_assert_double_eq_tol(d1, d2, 0.1);
  // ck_assert_int_eq(std_ret, my_ret);

  // std_ret = sscanf("-0x.09AFafg", "%*.1f", &c1);
  // my_ret = s21_sscanf("-0x.09AFafg", "%*.1f", &c2);
  // ck_assert_float_eq_tol(c1, c2, 0.1);
  // ck_assert_int_eq(std_ret, my_ret);

  // std_ret = sscanf("-0x.09AFafg", "%.*Lf", &e1);
  // my_ret = s21_sscanf("-0x.09AFafg", "%.*Lf", &e2);
  // ck_assert_float_eq_tol(e1, e2, 0.1);
  // ck_assert_int_eq(std_ret, my_ret);
}
END_TEST

START_TEST(sscanf_signed) {
  //%hhd %lli %lx ? %lX ?
  short a1 = -1, a2 = -1;
  // signed char b1 = -1, b2 = -1;
  int c1 = -1, c2 = -1;
  long d1 = -1, d2 = -1;
  long e1 = -1, e2 = -1;
  unsigned f1 = -1, f2 = -1;
  long double g1 = -1, g2 = -1;
  long double h1 = -1, h2 = -1;
  double i1 = -1, i2 = -1;
  float j1 = -1, j2 = -1;
  long double k1 = -1, k2 = -1;
  long int l1 = -1, l2 = -1, m1 = -1, m2 = -1, n1 = -1, n2 = -1;
  long double o1 = -1, o2 = -1, p1 = -1, p2 = -1;
  long double q1 = -1, q2 = -1;
  float r1 = -1, r2 = -1;
  long double s1 = -1, s2 = -1;
  double t1 = -1, t2 = -1;

  int my_ret = s21_sscanf(
      "32000 -2000000000 +077777777777 -0xFFFFFFFFFF +0123 0x123.321 0x123.321 "
      "0x123.321 0x123.321 +0x123.321",
      "%hd%i%li%li%3o%Lf%Lf%lf%f%Lf", &a2, &c2, &d2, &e2, &f2, &g2, &h2, &i2,
      &j2, &k2);
  int std_ret = sscanf(
      "32000 -2000000000 +077777777777 -0xFFFFFFFFFF +0123 0x123.321 0x123.321 "
      "0x123.321 0x123.321 +0x123.321",
      "%hd%i%li%li%3o%Lf%Lf%lf%f%Lf", &a1, &c1, &d1, &e1, &f1, &g1, &h1, &i1,
      &j1, &k1);

  int s21_test_ret = s21_sscanf(
      "123123 -123123 +123123 0x123.123 0x123.123 0x123.123 123.123 +.555 "
      "-0Xa.ad",
      "%10ld%10ld%10ld%Lf%Lf%1Lf%3f%Lf%lf", &l2, &m2, &n2, &o2, &p2, &q2, &r2,
      &s2, &t2);
  int test_ret = sscanf(
      "123123 -123123 +123123 0x123.123 0x123.123 0x123.123 123.123 +.555 "
      "-0Xa.ad",
      "%10ld%10ld%10ld%Lf%Lf%1Lf%3f%Lf%lf", &l1, &m1, &n1, &o1, &p1, &q1, &r1,
      &s1, &t1);

  ck_assert_int_eq(std_ret, my_ret);
  ck_assert_int_eq(s21_test_ret, test_ret);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(e1, e2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(g1, g2);
  ck_assert_int_eq(h1, h2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(j1, j2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(l1, l2);
  ck_assert_int_eq(m1, m2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(p1, p2);
  ck_assert_int_eq(q1, q2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(s1, s2);
  ck_assert_int_eq(t1, t2);
}
END_TEST

START_TEST(sscanf_unsigned) {
  //%hhu %llX
  unsigned long a1, a2;
  unsigned short b1, b2;
  unsigned int c1, c2;
  unsigned long d1, d2;
  unsigned long e1, e2, e3, e4;

  int my_ret =
      s21_sscanf("033 32000 0xFFFFFF 077777777777 0xffffffffff 0xFFFFFFFFFF",
                 "%lo%hu%x%lo%lX%lx", &a2, &b2, &c2, &d2, &e2, &e4);
  int std_ret =
      sscanf("033 32000 0xFFFFFF 077777777777 0xffffffffff 0xFFFFFFFFFF",
             "%lo%hu%x%lo%lX%lx", &a1, &b1, &c1, &d1, &e1, &e3);

  ck_assert_int_eq(std_ret, my_ret);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(sscanf_skip_assignment) {
  int a1, a2;

  int my_res = s21_sscanf("123 345", "%*d%d", &a2);
  int std_res = sscanf("123 345", "%*d%d", &a1);

  ck_assert_int_eq(std_res, my_res);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_extra_values) {
  double a1, a2;
  long double b1, b2;
  float c1, c2;
  float d1, d2;

  int std_res = sscanf("NAN NAN NAN -NAN", "%lf %Lf %f %f", &a1, &b1, &c1, &d1);
  int my_res =
      s21_sscanf("NAN NAN NAN -NAN", "%lf %Lf %f %f", &a2, &b2, &c2, &d2);

  ck_assert_int_eq(std_res, my_res);

  ck_assert(isnan(a1));
  ck_assert(isnan(a2));

  ck_assert(isnan(b1));
  ck_assert(isnan(b2));

  ck_assert(isnan(c1));
  ck_assert(isnan(c2));

  ck_assert(isnan(d1));
  ck_assert(isnan(d2));

  std_res = sscanf("INF", "%lf", &a1);
  my_res = s21_sscanf("INF", "%lf", &a2);
  ck_assert_int_eq(std_res, my_res);
  ck_assert(isinf(a1));
  ck_assert(isinf(a2));

  std_res = sscanf("-INFINITY", "%lf", &a1);
  my_res = s21_sscanf("-INFINITY", "%lf", &a2);
  ck_assert_int_eq(std_res, my_res);
  ck_assert(isinf(a1));
  ck_assert(isinf(a2));

  std_res = sscanf("INFINITY", "%f", &c1);
  my_res = s21_sscanf("INFINITY", "%f", &c2);
  ck_assert_int_eq(std_res, my_res);
  ck_assert(isinf(c1));
  ck_assert(isinf(c2));

  std_res = sscanf("-INFINITY", "%f", &d1);
  my_res = s21_sscanf("-INFINITY", "%f", &d2);
  ck_assert_int_eq(std_res, my_res);
  ck_assert(isinf(d1));
  ck_assert(isinf(d2));
}
END_TEST

START_TEST(sscanf_wchar_values) {
  wchar_t b1, b2;

  int std_res = sscanf(" a", "%lc", &b1);
  int my_res = s21_sscanf(" a", "%lc", &b2);

  ck_assert_int_eq(std_res, my_res);
  ck_assert(b1 == b2);

  wchar_t *a1 = calloc(20, sizeof(wchar_t));
  wchar_t *a2 = calloc(20, sizeof(wchar_t));

  if (a1 && a2) {
    std_res = sscanf("abcdef", "%100ls", a1);
    my_res = s21_sscanf("abcdef", "%100ls", a2);

    ck_assert_int_eq(std_res, my_res);
    ck_assert(wcscmp(a1, a2) == 0);
  }

  free(a1);
  free(a2);
}
END_TEST

START_TEST(sscanf_pointer) {
  void *p1, *p2, *p3, *p4;
  int str_size = 10000;
  char *my_str = (char *)calloc(str_size, sizeof(char));
  char *std_str = (char *)calloc(str_size, sizeof(char));

#if defined(__linux__)
  int std_res = sscanf("(nil) 0xFFFFF", "%p%p", &p1, &p2);
  int my_res = s21_sscanf("(nil) 0xFFFFF", "%p%p", &p3, &p4);
#elif __APPLE__
  int std_res = sscanf("0x0 0xFFFFF", "%p%p", &p1, &p2);
  int my_res = s21_sscanf("0x0 0xFFFFF", "%p%p", &p3, &p4);
#endif
  ck_assert_int_eq(std_res, my_res);
  ck_assert_ptr_eq(p1, p3);
  ck_assert_ptr_eq(p2, p4);

  if (my_str != s21_NULL && std_str != s21_NULL) {
    my_res = s21_sprintf(my_str, "%p", s21_NULL);
    std_res = sprintf(std_str, "%p", s21_NULL);
    ck_assert_str_eq(my_str, std_str);
    ck_assert_int_eq(my_res, std_res);
    memset(my_str, '\0', str_size);
    memset(std_str, '\0', str_size);
  } else {
    printf("alloc error");
  }
  free(my_str);
  free(std_str);
}
END_TEST

START_TEST(sscanf_errors) {
  int a1 = -1, a3 = -1;
  int a2 = -1, a4 = -1;

  int std_ret = sscanf("", "%n", &a1);
  int my_ret = s21_sscanf("", "%n", &a2);

  ck_assert_int_eq(std_ret, my_ret);
  ck_assert_int_eq(a1, a2);

  int d4 = -1, d3 = -1;
  int std_ret_2 = sscanf("100 10", "%n", &d3);
  int my_ret_2 = s21_sscanf("100 10", "%n", &d4);

  ck_assert_int_eq(std_ret_2, my_ret_2);
  ck_assert_int_eq(d3, d4);

  a1 = -1;
  a2 = -1;
  a3 = -1;
  a4 = -1;
  std_ret = sscanf("", "%n%d", &a1, &a3);
  my_ret = s21_sscanf("", "%n%d", &a2, &a4);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(a3, a4);
  ck_assert_int_eq(std_ret, my_ret);
}
END_TEST

START_TEST(sscanf_leftovers) {
  // float f1 = -1.0, f2 = -1.0;
  // void *p1 = s21_NULL, *p2 = s21_NULL;
  int d1 = -1, d2 = -1;

  int std_ret = sscanf("%", "%%");
  int my_ret = s21_sscanf("%", "%%");
  ck_assert_int_eq(std_ret, my_ret);

  int std_ret_2 = sscanf("0xffff", "%*p");
  int my_ret_2 = s21_sscanf("0xffff", "%*p");
  // ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(std_ret_2, my_ret_2);

  int std_ret_3 = sscanf(" 5", "%i", &d1);
  int my_ret_3 = s21_sscanf(" 5", "%i", &d2);
  // ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(std_ret_3, my_ret_3);
}
END_TEST

Suite *s21_string_suite() {
  Suite *suite = suite_create("s21_string");
  TCase *tcase = tcase_create("s21_string");

  tcase_add_test(tcase, s21_strlen_test);
  tcase_add_test(tcase, s21_strncmp_test);
  tcase_add_test(tcase, s21_strpbrk_test);
  tcase_add_test(tcase, s21_strcspn_test);
  tcase_add_test(tcase, s21_strchr_test);
  tcase_add_test(tcase, s21_strrchr_test);
  tcase_add_test(tcase, s21_strncat_test);
  tcase_add_test(tcase, s21_strstr_test);
  tcase_add_test(tcase, s21_strncpy_test);
  tcase_add_test(tcase, s21_to_lower_test);
  tcase_add_test(tcase, s21_to_upper_test);
  tcase_add_test(tcase, s21_trim_test);
  tcase_add_test(tcase, s21_insert_test);
  tcase_add_test(tcase, s21_memchr_test);
  tcase_add_test(tcase, s21_memcmp_test);
  tcase_add_test(tcase, s21_memcpy_test);
  tcase_add_test(tcase, s21_memset_test);
  tcase_add_test(tcase, s21_strtok_test);
  tcase_add_test(tcase, s21_strerror_test);
  suite_add_tcase(suite, tcase);
  // tcase_add_test(tcase, s21_sprintf_test);
  // tcase_add_test(tcase, s21_sscanf_test);

  TCase *sprintf_cases = tcase_create("s21_string_sprintf");
  tcase_add_test(sprintf_cases, sprintf_ints);
  tcase_add_test(sprintf_cases, sprintf_floats);
  tcase_add_test(sprintf_cases, sprintf_special);
  tcase_add_test(sprintf_cases, sprintf_strings);
  tcase_add_test(sprintf_cases, sprintf_pointers);
  tcase_add_test(sprintf_cases, sprintf_hex);
  tcase_add_test(sprintf_cases, sprintf_n);
  tcase_add_test(sprintf_cases, sprintf_u);
  tcase_add_test(sprintf_cases, sprintf_o);
  suite_add_tcase(suite, sprintf_cases);

  TCase *sscanf_cases = tcase_create("s21_string_sscanf");
  tcase_add_test(sscanf_cases, sscanf_strings_chars);
  tcase_add_test(sscanf_cases, sscanf_floats);
  tcase_add_test(sscanf_cases, sscanf_errors);
  tcase_add_test(sscanf_cases, sscanf_signed);
  tcase_add_test(sscanf_cases, sscanf_unsigned);
  tcase_add_test(sscanf_cases, sscanf_extra_values);
  tcase_add_test(sscanf_cases, sscanf_pointer);
  tcase_add_test(sscanf_cases, sscanf_wchar_values);
  tcase_add_test(sscanf_cases, sscanf_skip_assignment);
  tcase_add_test(sscanf_cases, sscanf_leftovers);
  suite_add_tcase(suite, sscanf_cases);

  return suite;
}

int main() {
  SRunner *srunner = srunner_create(s21_string_suite());
  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  int error_summary = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return error_summary == SUCCESS ? SUCCESS : ERROR;
}