#include <omp.h> 
#include <stdio.h>
/* #include <stdlib.h> */
int main (int argc, char *argv[]) {
	#pragma omp parallel for
    for (int i=0; i<4; i++) {
        printf("for iteration %d\n", i);
    }
	return 0;
}
