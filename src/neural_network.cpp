#include<iostream>
#include<assert.h>
#include<utility>
#include<tensors.h>

int main() {
	Tensor<float> t1(4.3f);
	Tensor<float> t2(5.3f);
	Tensor<float> t3 = t1 * t2;
	t3.backward(1.0f);
	std::cout << "T1 grad " << t1.get_grad() << " T2 grad " << t2.get_grad() << "\n";
}