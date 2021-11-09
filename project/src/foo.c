#include "foo.h"

typedef struct new_int {
    int value;
    int index;
} new_int;

char *rand_str(char *str) {
    int rand_ascii;
    char rand_char;

    unsigned int seed = time(NULL);

    for (int i = 0; i < MAX; ++i) {
        rand_ascii = rand_r(&seed) % 95 + 32;
        rand_char = (char)rand_ascii;
        str[i] = rand_char;
    }
    return str;
}

char *max_char(const char *str, int test_max) {
    if (str == NULL) {
        return 0;
    }
    char *max_str = NULL;
    int count = 0;
    int max = 0;
    int ind = 0;

    for (int i = 0; i < test_max; ++i) {
        if (str[i] != str[i-1]) {
            ++count;
        } else if (str[i] == str[i-1]) {
            count = 0;
        }
        if (max < count) {
            max = count;
            ind = i - count;
        }
    }
    ++max;


    if ((max_str = malloc(sizeof(char) * max)) == NULL) {
        return 0;
    }

    for (int i = 0; i < max; ++i) {
        max_str[i] = str[i+ind];
    }

    if (ind < 0) {
        for (int i = 0; i < max; ++i) {
            max_str[i] = str[i];
        }
    }

    return max_str;
}

char *parallel_max_char(const char *str, int test_max) {
    if (str == NULL) {
        return 0;
    }
    int ind_part = 0;
    int len_half = test_max/2;

    int max = 0;
    int ind = 0;

    int count_neg = 0;
    int max_neg = 0;

    int ind_neg = 0;

    int count_pos = 0;
    int max_pos = 0;
    int ind_pos = 0;

    for (int i = len_half; i < test_max; ++i) {
        if (str[i] == str[i+1]) {
            ind_part = i+1;
            i = test_max;
        }
    }

    long page_size = getpagesize();

    new_int *ptr = mmap(NULL, page_size, PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    int numberOfChildren = 1;
    pid_t *childPids = NULL;
    pid_t p;

    childPids = malloc(numberOfChildren * sizeof(pid_t));

    for (int ii = 0; ii < numberOfChildren; ++ii) {
       if ((p = fork()) == 0) {
           for (int i = 0; i < ind_part; ++i) {
               if (str[i] != str[i-1]) {
                   ++count_neg;
               } else {
                   count_neg = 0;
               }
               if (max_neg < count_neg) {
                   max_neg = count_neg;
                   ind_neg = i - count_neg;
               }
           }
           ++max_neg;

           ptr->value = max_neg;
           ptr->index = ind_neg;

           exit(0);

       } else {
          childPids[ii] = p;
       }
    }

    int stillWaiting;
    do {
       stillWaiting = 0;
        for (int ii = 0; ii < numberOfChildren; ++ii) {
           if (childPids[ii] > 0) {
              if (waitpid(childPids[ii], NULL, WNOHANG) != 0) {
                 childPids[ii] = 0;
              } else {
                 stillWaiting = 1;
              }
           }
           sleep(0);
        }
    } while (stillWaiting);

    free(childPids);


    if (p != 0) {
        for (int i = ind_part; i < test_max; ++i) {
            if (str[i] != str[i-1]) {
                ++count_pos;
            } else {
                count_pos = 0;
            }
            if (max_pos < count_pos) {
                max_pos = count_pos;
                ind_pos = i - count_pos;
            }
        }
        ++max_pos;
    }

    max_neg = ptr->value;
    ind_neg = ptr->index;

    if (max_neg < max_pos) {
        max = max_pos;
        ind = ind_pos;
    } else if (max_neg > max_pos) {
        max = max_neg;
        ind = ind_neg;
    }

    char *max_str;
    if ((max_str = malloc(sizeof(char) * max)) == NULL) {
        return 0;
    }

    for (int i = 0; i < max; ++i) {
        max_str[i] = str[i+ind];
    }

    if (ind < 0) {
        for (int i = 0; i < max; ++i) {
            max_str[i] = str[i];
        }
    }

    return max_str;
}
