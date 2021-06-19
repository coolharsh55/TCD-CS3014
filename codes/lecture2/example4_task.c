#include <omp.h> 
#include <stdio.h>
/* #include <stdlib.h> */
int main (int argc, char *argv[]) {
	#pragma omp parallel
	{
		#pragma omp single  // just one thread does this bit
		{
			#pragma omp task 
			{ 
				printf("Hello\n");
			}
			#pragma omp task
			{
			    printf("world\n");
			}
		}
	}
	return 0;
}
