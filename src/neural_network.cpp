#include<iostream>
#include<types/dim.h>
#include<utils/nn_maths.h>

int main() {
	int* a = new int[4];
	int* b = new int[4];
	int* c = new int[4];
	a[0] = 1;
	a[1] = 2;
	a[2] = 4;
	a[3] = 6;

	b[0] = 8;
	b[1] = 7;
	b[2] = 3;
	b[3] = 2;
	Vector2<int> dim_a(2, 2);
	Vector2<int> dim_b(2, 2);
	matrix_multiplication_gpu_kernel(dim_a, dim_b, a, b, c);

	std::cout << c[0] << "," << c[1] << "\n";
	std::cout << c[2] << "," << c[3] << "\n";
}