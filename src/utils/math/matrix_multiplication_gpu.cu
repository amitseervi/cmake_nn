#include<types/dim.h>
#include<assert.h>
#include<iostream>
#include<cuda_runtime.h>
#include<device_launch_parameters.h>

__global__ void _multiply_matrix_gpu_util(Vector2<int>* dim_a, Vector2<int>* dim_b, int* a, int* b, int* c) {
	int i = blockDim.y * blockIdx.x + threadIdx.x;
	int j = blockDim.y * blockIdx.y + threadIdx.y;
	if (j >= dim_b->y) {
		return;
	}
	if (i >= dim_a->x) {
		return;
	}
	int sum = 0;
	for (int k = 0; k < dim_a->y; k++) {
		sum += a[(i * dim_a->x) + k] * b[(k * dim_b->x) + j];
	}
	c[((i * dim_a->x) + j)] = sum;
}

void matrix_multiplication_gpu_kernel(Vector2<int> dim_a, Vector2<int> dim_b, int* a, int* b, int* c) {
	assert(dim_a.y == dim_b.x);
	Vector2<int>* device_dim_a;
	Vector2<int>* device_dim_b;
	int* device_a;
	int* device_b;
	int* device_c;
	cudaMalloc(&device_dim_a, sizeof(Vector2<int>));
	cudaMalloc(&device_dim_b, sizeof(Vector2<int>));
	cudaMalloc(&device_a, sizeof(int) * dim_a.x * dim_a.y);
	cudaMalloc(&device_b, sizeof(int) * dim_b.x * dim_b.y);
	cudaMalloc(&device_c, sizeof(int) * dim_a.x * dim_b.y);
	cudaMemcpy(device_dim_a, &dim_a, sizeof(Vector2<int>), cudaMemcpyHostToDevice);
	cudaMemcpy(device_dim_b, &dim_b, sizeof(Vector2<int>), cudaMemcpyHostToDevice);
	cudaMemcpy(device_a, a, sizeof(int) * dim_a.x * dim_a.y, cudaMemcpyHostToDevice);
	cudaMemcpy(device_b, b, sizeof(int) * dim_b.x * dim_b.y, cudaMemcpyHostToDevice);
	dim3 threads_per_block(16, 16);
	dim3 num_of_blocks((dim_a.x + 15) / 16, (dim_b.y + 15) / 16);
	_multiply_matrix_gpu_util <<< num_of_blocks, threads_per_block >>> (device_dim_a, device_dim_b, device_a, device_b, device_c);
	cudaFree(device_dim_a);
	cudaFree(device_dim_b);
	cudaFree(device_a);
	cudaFree(device_b);
	cudaMemcpy(c, device_c, sizeof(int) * dim_a.x * dim_b.y, cudaMemcpyDeviceToHost);
	cudaFree(device_c);
}
