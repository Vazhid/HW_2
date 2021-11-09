#include "foo.h"

int main() {

    char *str;
    if ((str = (char*) malloc(sizeof(char) * MAX)) == NULL) {
        return 0;
    }

    char *str_max = NULL;
    char *str_max_parallel = NULL;

    str = rand_str(str);

    int start_time =  clock();
    str_max = max_char(str);
    int end_time = clock();
    int search_time = end_time - start_time;
    printf("Время работы последовательного алгоритма: %d\n", search_time);

    int start_time1 =  clock();
    str_max = parallel_max_char(str);
    int end_time1 = clock();
    int search_time1 = end_time1 - start_time1;
    printf("Время работы параллельного алгоритма: %d\n", search_time1);
//    printf("%s\n", str_max);
//    printf("------------------------------------------------------------\n");
//    str_max_parallel = parallel_max_char(str);
//    printf("%s\n", str_max_parallel);
//    printf("------------------------------------------------------------\n");
    free(str);
    free(str_max);
    free(str_max_parallel);
    return 0;
}
