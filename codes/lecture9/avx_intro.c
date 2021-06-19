/**
 * AVX Intro
 * CS3014 Lecture 9
 * 08-FEB 2018
 * author: Harshvardhan Pandit
 */

#include <stdio.h>
#include <stdlib.h>

// Just include this header!
// No special compiler options are needed
#include <immintrin.h>

void print_m256(__m256 vector) {
    float* values = (float*) &vector;
    for (int i=0; i<8; i++ ) {
        printf("%.2f ", values[i]);
    }   
    printf("\n");
}

int main(int argc, char** args) {

    __m256  float_single_precision;  // 4 x 32bit
    __m256i integer;                 // 4 x 32bit
    __m256d float_double_precision;  // 2 x 64bit

    /* __m256 float
     * all methods have prefix _mm256_ and suffix _ps
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

    // load same float (32bit) into __m256 vector
    __m256 float_vector = _mm256_set1_ps(1.0);
    /* print_m256(float_vector); */

    // let's add two vectors
    __m256 vectorA = _mm256_setr_ps(1, 2, 3, 4, 5, 6, 7, 8);
    __m256 vectorB = _mm256_setr_ps(8, 7, 6, 5, 4, 3, 2, 1);

    __m256 result = _mm256_add_ps(vectorA, vectorB);
    /* print_m256(result); */

    __m256 vector1 = _mm256_set1_ps(0);

    for (int i=0; i<32; i+=8) {  // <---- byte aligned to 32!!!
        vector1 = _mm256_add_ps(vector1, vectorA);
        print_m256(vector1);
    }

    // fine
    return 1;
}

