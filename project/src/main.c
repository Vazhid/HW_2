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
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Время работы последовательного алгоритма: %f\n", time_spent);

    int start_time_par =  clock();
    str_max = parallel_max_char(str, MAX);
    int end_time_par = clock();
    double time_spent_par = (double)(end_time_par - start_time_par) / CLOCKS_PER_SEC;
    printf("Время работы параллельного алгоритма: %f\n", time_spent_par);
    free(str);
    free(str_max);
    free(str_max_parallel);
    return 0;
}
