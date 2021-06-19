/* scheduling */
#include <omp.h> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (int argc, char *argv[]) {
    srand(time(NULL));

    #pragma omp parallel for schedule(dynamic, 2)
    for (int i = 0; i < 8; i++ )
    {
        int sleeptime = rand() % 4;
        int thread_id = omp_get_thread_num();
        nanosleep((const struct timespec[]){{
            0, 500000000L * sleeptime}}, NULL);
        printf("thread %d sleept %d halfsec\n", thread_id, sleeptime);
    }

    return 0;
}
