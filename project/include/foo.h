#ifndef CPP_HW_2_PROJECT_INCLUDE_FOO_H_
#define CPP_HW_2_PROJECT_INCLUDE_FOO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX 100000

char *rand_str(char *str);

char *max_char(const char *str);

char *parallel_max_char(const char *str);

#endif  // CPP_HW_2_PROJECT_INCLUDE_FOO_H_
