#include<iostream>
#include<assert.h>
#include<utility>
#include<tensors.h>

int main() {
	try {
		Tensor<float> t1(4.3f);
		Tensor<float> t2(5.3f);
		Tensor<float> t4(2.3f);
		Tensor<float> t3 = t1 * t2 * t4;
		std::cout << "T3 = " << t3.value << "\n";
		t3.backward(1.0f);
		std::cout << "T1 Gradient " << t1.get_grad() << " T4 Gradient " << t4.get_grad() << " T4 Gradient " << t4.get_grad() << "\n";
	}
	catch (std::logic_error) {
		std::cout << "Error occured\n";
	}
}