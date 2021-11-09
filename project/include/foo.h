#ifndef PROJECT_INCLUDE_FOO_H_
#define PROJECT_INCLUDE_FOO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define MAX 100000000

typedef struct new_int new_int;

char *rand_str(char *str);

char *max_char(const char *str, int test_max);

char *parallel_max_char(const char *str, int test_max);

#endif  // PROJECT_INCLUDE_FOO_H_
