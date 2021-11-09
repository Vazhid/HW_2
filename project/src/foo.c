#include "foo.h"

char *rand_str(char *str) {
    int rand_ascii;
    char rand_char;

    srand(time(NULL));

    for (int i = 0; i < MAX; ++i) {
        rand_ascii = rand() % 95 + 32;
        rand_char = (char)(rand_ascii);
        str[i] = rand_char;
    }
    return str;
}

char *max_char(const char *str) {
    if (str == NULL) {
        return 0;
    }
    int count = 0;
    int max = 0;
    int ind = 0;

    for (int i = 0; i < MAX; ++i) {
        if (str[i] != str[i-1]) {
            ++count;
        } else {
            count = 0;
        }
        if (max < count) {
            max = count;
            ind = i - count;
        }
    }
    ++max;

    char *max_str;
    if ((max_str = malloc(sizeof(char) * max)) == NULL) {
        return 0;
    }

    for (int i = 0; i < max; ++i) {
        max_str[i] = str[i+ind];
    }

    return max_str;
}

char *parallel_max_char(const char *str) {
    if (str == NULL) {
        return 0;
    }
    int ind_part = 0;
    int ind_pos_part = 0;
    int ind_neg_part = 0;
    int len_half = strlen(str)/2;

    int max = 0;
    int ind = 0;

    int count_neg = 0;
    int max_neg = 0;
    int ind_neg = 0;

    int count_pos = 0;
    int max_pos = 0;
    int ind_pos = 0;

    for (unsigned long i = len_half; i < strlen(str); ++i) {
        if (str[i] == str[i+1]) {
            ind_pos_part = i+1;
            i = strlen(str);
        }
    }
    for (int i = len_half; i > 0; --i) {
        if (str[i] == str[i-1]) {
            ind_neg_part = i-1;
            i = 0;
        }
    }

    ind_part = (len_half - ind_neg_part) < (ind_pos_part - len_half) ? ind_neg_part : ind_pos_part;

    pid_t pid;
    pid = fork();

    if (pid != 0) {
        for (unsigned long i = ind_part; i < strlen(str); ++i) {
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

    if (pid == 0) {
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
        exit(0);
    }

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

    return max_str;
}
