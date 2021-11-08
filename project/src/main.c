#include "foo.h"

int main() {
    char *str = (char*) malloc(sizeof(char) * MAX);

    int rand_ascii;
    char rand_char;
    char *str_max = NULL;
    char *str_max_parallel = NULL;
    
    srand(time(NULL));

    for (int i = 0; i < MAX; ++i) {
        rand_ascii = rand() % 95 + 32;
        rand_char = (char)(rand_ascii);
        str[i] = rand_char;
    }
    
    
    
    
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
