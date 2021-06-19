#include <omp.h> 
#include <stdio.h>
/* #include <stdlib.h> */
int main (int argc, char *argv[]) {
    int i, j;
	#pragma omp parallel for private(j) collapse(2)  // <--------------!
    for (i=0; i<2; i++) {
        for (j=0; j<9; j++) {
            printf("%d,%d :: %d \n", i, j, omp_get_thread_num());
        }
    }
	return 0;
}
