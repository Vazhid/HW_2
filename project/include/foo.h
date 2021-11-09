#ifndef foo_h
#define foo_h

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

#endif /* foo_h */
