#ifndef __HEADER_NN_MATH__
#define __HEADER_NN_MATH__
#include<types/dim.h>

void matrix_multiplication_cpu_kernel(Vector2<int> dim_a, Vector2<int> dim_b, int* a, int* b, int* c);
void matrix_multiplication_gpu_kernel(Vector2<int> dim_a, Vector2<int> dim_b, int* a, int* b, int* c);
#endif