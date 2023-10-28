#include<types/dim.h>
#include<assert.h>
#include<iostream>

void matrix_multiplication_cpu_kernel(Vector2<int> dim_a, Vector2<int> dim_b, int* a, int* b, int* c) {
	assert(dim_a.y == dim_b.x);
	for (int i = 0; i < dim_a.x; i++) {
		for (int j = 0; j < dim_b.y; j++) {
			int cell_result = 0;
			for (int k = 0; k < dim_a.y; k++) {
				cell_result += a[(i * dim_a.x) + k] * b[(k * dim_b.y) + j];
			}
			c[(i * dim_b.y) + j] = cell_result;
		}
	}
}
