/* local variable */
#include <omp.h> 
#include <stdio.h>
/* #include <stdlib.h> */
#include <limits.h>
#define LIMIT 1234567
int main (int argc, char *argv[]) {
    long sum = 0;
    int n = 4;
    int a[LIMIT];
    for (int t=0; t<LIMIT; a[t++]=t);

    #pragma omp parallel
    {
        int local_sum = 0;
        #pragma omp parallel for
        for (int i = 0; i < LIMIT; i++ )
        {
            local_sum += a[i];
        }
        #pragma omp critical
        sum += local_sum;
    }
    printf("sum = %ld\n", sum);
    return 0;
}
