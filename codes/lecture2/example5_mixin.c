#include <omp.h> 
#include <stdio.h>
/* #include <stdlib.h> */
int main (int argc, char *argv[]) {
	int n = 4;  // xkcd 221
	#pragma omp parallel
	{
	/* all threads do the same thing here */
	#pragma omp for
	for (int i = 0; i < n; i++ ) {
		/*loop iterations divided between threads*/
	}
	/* there is an implicit barrier here that makes all threads wait 
		until all are finished */
	#pragma omp sections
	{
		#pragma omp section
		{
			/* executes in parallel with code from other section */
		}
		#pragma omp section
		{
			/* executes in parallel with code from other section */
		}
	}
	/* there is an implicit barrier here that makes all threads wait 
		until all are finished */
	/* all threads do the same thing again */
	}
	return 0;
}
