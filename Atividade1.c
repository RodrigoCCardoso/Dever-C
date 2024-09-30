#include <limits.h>

int main() {

    printf("Tipo                | Limite Mínimo       | Limite Máximo\n");
    printf("--------------------|---------------------|---------------------\n");
    printf("char                | %d                   | %d\n", CHAR_MIN, CHAR_MAX);
    printf("int                 | %d                   | %d\n", INT_MIN, INT_MAX);
    printf("short int           | %d                   | %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned int        | %u                  | %u\n", 0, UINT_MAX);
    printf("long int            | %ld                  | %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long int   | %lu                 | %lu\n", 0UL, ULONG_MAX);
    printf("long long int       | %lld                 | %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long int| %llu              | %llu\n", 0ULL, ULLONG_MAX);
    
    int overflow_int = INT_MAX + 1;
    printf("\nDemonstração de overflow:\n");
    printf("Valor de overflow_int (int): %d\n", overflow_int);

    return 0;
}
