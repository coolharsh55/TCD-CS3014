#include <omp.h> 
#include <stdio.h>
/* #include <stdlib.h> */
int main (int argc, char *argv[]) {
	printf("There are %d number of threads here\n",
        omp_get_num_threads());
	#pragma omp parallel 
	{
		int thread_id = omp_get_thread_num();
		printf("hello thread#%d\n", thread_id);
	}
	return 0;
}
