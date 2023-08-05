ifeq ($(OS),Windows_NT)
		LFLAGS=-lcheck -lm
		LEAK=leaks -quiet -atExit --
		SYSFLAG=-D Win32
		COMMANDS=
	WINDOWS=true
else
	WINDOWS=false
	UNAME:=$(shell uname -s)
	ifeq ($(UNAME),Linux)
		LFLAGS=-lcheck -lsubunit -lrt -lm -lpthread
		LEAK=valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file="leak.log"
		COMMANDS=dos2unix test_log.sh test_leak.sh
		SYSFLAG=-D LINUX
	endif
	ifeq ($(UNAME),Darwin)
		LFLAGS=-lcheck -lm
		LEAK=leaks -quiet -atExit --
		SYSFLAG=-D APPLE
		COMMANDS=
	endif
endif

CC=gcc -Wall -Wextra -Werror
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

LIB_SOURCES=$(wildcard ./string/*.h) $(wildcard ./string/*.c) s21_string.h
TEST_SOURCES=test.c test.h

STYLABLE=$(wildcard ./*.c) $(wildcard ./*.h) $(wildcard ./*/*.c) $(wildcard ./*/*.h)

all: s21_string.a style test 



# ---- Recipe for any object file ----
%.o: %.c
	${CC} ${SYSFLAG} -c $^  -o $@



# ---- Compilation of static library itself ----
LIB_C_SOURCES=$(filter %.c,$(LIB_SOURCES))
LIB_H_SOURCES=$(filter %.h,$(LIB_SOURCES))
LIB_OBJ_FILES=$(LIB_C_SOURCES:.c=.o)

s21_string.a: ${LIB_H_SOURCES} ${LIB_OBJ_FILES}
	ar rc s21_string.a ${LIB_OBJ_FILES}
	ranlib s21_string.a



# ---- Tests ----
test: test.out
	./test.out > test.log
	bash test_log.sh

TEST_C_SOURCES=$(filter %.c,$(TEST_SOURCES))

test.out: s21_string.a ${TEST_SOURCES}
	${CC} ${SYSFLAG} ${TEST_C_SOURCES} s21_string.a -L. ${LFLAGS} -o test.out

gcov_report: gcov_report.out
	./gcov_report.out > test.log
	bash test_log.sh
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

gcov_report.out: ${TEST_SOURCES} ${LIB_SOURCES}
	${CC} ${GCOV_FLAGS} ${SYSFLAG} ${TEST_C_SOURCES} ${LIB_C_SOURCES} ${LFLAGS} -o gcov_report.out



# ---- Helper checks ----

style: .clang-format
	clang-format -n ${STYLABLE}

style_force: .clang-format
	clang-format -i ${STYLABLE}

cppcheck:
	cppcheck ${STYLABLE}

leaks: test.out
	${LEAK} ./test.out

.clang-format:
	clang-format -style=Google -dump-config > .clang-format



# ---- Clean ----
clean:
	rm -f *.o */*.o
	rm -f *.out
	rm -f .clang-format
	rm -f test s21_string.a *.gc* test.info log.xml test.log leak.log
	rm -f -rf report
	rm -f -rf playground
	rm -f playground $(C_TRIM) $(CS_TRIM) $(C_INSERT) $(CS_INSERT) insert_test trim_test insert_test.c trim_test.c
	rm -rf Cs_test/obj
	rm -rf Cs_test/bin


