#include "foo.h"

int main() {
    char *str;
    if ((str = malloc(sizeof(char) * MAX)) == NULL) {
        return 0;
    }

    char *str_max = NULL;
    char *str_max_parallel = NULL;

    str = rand_str(str);

    int start_time =  clock();
    str_max = max_char(str, MAX);
    int end_time = clock();
    int time_spent = end_time - start_time;
    printf("Время работы последовательного алгоритма: %d\n", time_spent);

    int start_time_par =  clock();
    str_max = parallel_max_char(str, MAX);
    int end_time_par = clock();
    int time_spent_par = end_time_par - start_time_par;
    printf("Время работы параллельного алгоритма: %d\n", time_spent_par);
    free(str);
    free(str_max);
    free(str_max_parallel);
    return 0;
}
