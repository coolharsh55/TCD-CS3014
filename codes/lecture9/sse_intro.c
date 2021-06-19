/**
 * SSE Intro
 * CS3014 Lecture 9
 * 08-FEB 2018
 * author: Harshvardhan Pandit
 */

#include <stdio.h>
#include <stdlib.h>

// Just include this header!
// No special compiler options are needed
#include <xmmintrin.h>

void print_m128(__m128 vector) {
    float* values = (float*) &vector;
    printf("values: %.2f %.2f %.2f %.2f \n",
        values[0], values[1], values[2], values[3]); 
}

int main(int argc, char** args) {

    __m128  float_single_precision;  // 4 x 32bit
    __m128i integer;                 // 4 x 32bit
    __m128d float_double_precision;  // 2 x 64bit

    /* __m128 float
     * all methods have prefix _mm_ and suffix _ps
     *
     * loading floats
     * load     --> load 4 floats from 16-byte aligned address
     * loadu    --> load from unaligned address (needs to align, 4x slower)
     * load1    --> load 1 float into all 4 floats from address
     * setr     --> set given 4 floats into 5 floats of vector
     * set1     --> set given 1 float into all 4 floats of vector
     *
     * storing floats
     * store    --> store 4 floats to aligned address
     * storeu   --> store 4 floats to unaligned address
     *
     * operations
     * add/sub  --> add corresponding floats
     * mul/div  --> multiply floats
     * min/max  --> find minimum of two floats(vectors)
     * sqrt     --> take square root of 4 floats
     * rcp      --> calculate reciprocal
     * rsqrt    --> reciprocal square root
     */

    // load same float (32bit) into __m128 vector
    __m128 float_vector = _mm_set1_ps(1.0);
    print_m128(float_vector);

    // let's add two vectors
    __m128 vectorA = _mm_setr_ps(1, 2, 3, 4);
    __m128 vectorB = _mm_setr_ps(4, 3, 2, 1);

    __m128 result = _mm_add_ps(vectorA, vectorB);
    /* print_m128(result); */

    __m128 vector1 = _mm_set1_ps(0);

    float values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    for (int i=0; i<16; i+=4) {  // <---- byte aligned to 16!!!
        __m128 vectorC = _mm_load_ps(&values[i]);
        vector1 = _mm_add_ps(vector1, vectorC);
        /* print_m128(vector1); */
    }

    // fine
    return 1;
}

