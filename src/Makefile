.PHONY: all clean test gcov_report clang cpp valgrind

CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic -std=c11
TEST_CFLAGS := -g -fprofile-arcs -ftest-coverage -fPIC --coverage
GCOV_FLAGS := -fprofile-arcs -ftest-coverage --coverage
GCOVR_FLAGS := --html --html-details --html-medium-threshold 79.9 --html-high-threshold 80.0
FORMAT := clang-format
FFLAGS := --style=Google -i
CPPFLAGS := --enable=all --suppress=missingIncludeSystem --std=c11
VALGRIND_FLAGS := --tool=memcheck --leak-check=full --show-leak-kinds=all
RM := rm -rf

SRC := $(wildcard s21_*.c)
HEADER := $(wildcard s21_*.h)
OBJ := $(patsubst %.c, %.o, $(SRC))
KERNEL := $(shell uname -s)
TEST_DIR := tests
TEST_SRC := $(wildcard $(TEST_DIR)/s21_*.c)
TEST_HEADER := $(wildcard $(TEST_DIR)/s21_*.h)
TEST_FILES := $(wildcard $(TEST_DIR)/*test.c)
TEST_FILES_OBJ := $(patsubst %.c, %.o, $(TEST_FILES))
TEST_TARGET := s21_string_test

ifeq ($(KERNEL), Linux)
	LIBS := -lcheck -lpthread -lrt -lsubunit -lm -lcheck_pic -pthread
endif

ifeq ($(KERNEL), Darwin)
	LIBS := -lcheck
endif

all: clean s21_string.a test gcov_report

s21_string.a: $(SRC)
	$(CC) $(CFLAGS) -c $^ $(LIBS)
	ar rc $@ $(OBJ)
	ranlib $@

test: $(SRC) $(TEST_SRC) s21_string.a
	$(CC) $(TEST_CFLAGS) $(CFLAGS) $^ -o $(TEST_DIR)/$(TEST_TARGET) $(LIBS)
	$(RM) *.o
	./$(TEST_DIR)/$(TEST_TARGET)

gcov_report: clean test
	mkdir $@
	gcovr -r . -d $(TEST_DIR) $(GCOVR_FLAGS) -o $@/report.html
	$(RM) $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno $(TEST_DIR)/*.info

clang: $(SRC) $(HEADER) $(TEST_SRC) $(TEST_HEADER)
	$(FORMAT) $(FFLAGS) $^

cpp:
	cppcheck $(CPPFLAGS) .

valgrind: test
	valgrind $(VALGRIND_FLAGS) ./$^
	make clean

clean:
	$(RM) *.o $(TEST_DIR)*.o *.a $(TEST_DIR)/$(TEST_TARGET) *.gcno $(TEST_DIR)/*.gcno *.gcda $(TEST_DIR)/*.gcda gcov_report