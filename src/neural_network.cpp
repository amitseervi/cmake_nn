#include<iostream>
#include<assert.h>
#include<utility>
#include<tensors.h>
#include<exception>
#include<utils.h>
template<typename T>
void print_float(T f) {
	std::cout << f << " ";
}
int main() {
	try {
		Tensor<float> t1(4.3f);
		Tensor<float> t2(5.3f);
		Tensor<float> t4(2.3f);
		Tensor<float> t3 = t1 * t2 * t4;
		std::cout << "T3 = " << t3.value << "\n";
		t3.backward(1.0f);
		std::cout << "T1 Grad " << t1.get_grad() << "\nT2 grad " << t2.get_grad() << "\nT4 grad " << t4.get_grad() << "\n";
		std::vector<float> v1{ 1.7f,2.6f,3.2f };
		std::vector<float> v2{ 3.4f,2.1f,3.7f };
		std::vector<float> v3 = v1 * v2;
		vector_for_each<float>(v3, &print_float<float>);
		std::cout << "\n";
	}
	catch (std::logic_error err) {
		std::cerr << "\nError occured : " << err.what() << "\n";
	}
}