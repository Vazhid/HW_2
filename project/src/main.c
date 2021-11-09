#include "foo.h"

int main() {
    char *str = (char*) malloc(sizeof(char) * MAX);
    char *str_max = NULL;
    char *str_max_parallel = NULL;
    
    str = rand_str(str);
    
    int start_time =  clock();
    str_max = max_char(str);
    int end_time = clock();
    int search_time = end_time - start_time;
    printf("Время работы последовательного алгоритма: %dмс\n", search_time);
    
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
