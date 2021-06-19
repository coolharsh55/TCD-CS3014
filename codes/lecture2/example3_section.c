#include <omp.h> 
#include <stdio.h>
/* #include <stdlib.h> */
int main (int argc, char *argv[]) {
	#pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("where am I?\n");
        }
        #pragma omp section
        {
            printf("Could I be lost?\n");
        }
        #pragma omp section
        {
            printf("I think I'm in Dublin...?\n");
        }
        #pragma omp section
        {
            printf("Am I underground?\n");
        }
    }
	return 0;
}
