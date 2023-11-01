#include<tensors.h>
#include<stdexcept>
#include<iostream>
#include<assert.h>

template <typename T>
Gradient<T>::Gradient(T v) :data(v) {
};


template <typename T>
Tensor<T>::Tensor(T v) {
	this->value = v;
	this->grad_holder = NULL;
	this->backward_operation = NULL;
	this->forward_operation = NULL;
}

//template <typename T>
//Tensor<T>::~Tensor() {
//	if (this->grad_holder != NULL) {
//		free(this->grad_holder);
//		this->grad_holder = NULL;
//	}
//	if (this->backward_operation != NULL) {
//		free(this->backward_operation);
//		this->backward_operation = NULL;
//	}
//	if (this->forward_operation != NULL) {
//		free(this->forward_operation);
//		this->forward_operation = NULL;
//	}
//}


template <typename T>
Tensor<T>::Tensor(T v, TensorBaseOperation<T>* backward_operation) {
	if (backward_operation != NULL) {
		std::cout << "Initializing Tensor " << v << " with Backward operation\n";
	}
	this->value = v;
	this->grad_holder = NULL;
	this->backward_operation = backward_operation;
	this->forward_operation = NULL;
}

template <typename T>
Tensor<T> Tensor<T>::operator +(Tensor<T>& a) {
	forward_operation = new TensorOperationAdd<T>(this, &a);
	return forward_operation->compute();
}

template <typename T>
Tensor<T> Tensor<T>::operator *(Tensor<T>& a) {
	forward_operation = new TensorOperationMul<T>(this, &a);
	return forward_operation->compute();
}

template <typename T>
void Tensor<T>::backward(T grad) {
	if (this->grad_holder != NULL) {
		free(this->grad_holder);
		this->grad_holder = NULL;
	}
	this->grad_holder = new Gradient<T>(grad);
	std::cout << "Tensor backward(" << this->value << ") -- " << grad << " this gradient " << this->grad_holder->data << "\n";
	if (this->backward_operation != NULL) {
		this->backward_operation->backward(grad);
	}
}

template <typename T>
T Tensor<T>::get_grad() {
	if (this->grad_holder == NULL) {
		throw std::logic_error("Grad not present");
	}
	return this->grad_holder->data;
}

template <typename T>
std::vector<T> operator * (const std::vector<T>& a, const std::vector<T>& b) {
	assert("Tensor of not same size" && a.size() == b.size());
	int n = a.size();
	std::vector<T> result(n);
	for (int i = 0; i < n; i++) {
		result[i] = a[i] * b[i];
	}
	return result;
}

template <typename T>
std::vector<T> operator + (const std::vector<T>& a, const std::vector<T>& b) {
	assert("Tensor of not same size" && a.size() == b.size());
	int n = a.size();
	std::vector<T> result(n);
	for (int i = 0; i < n; i++) {
		result[i] = a[i] + b[i];
	}
	return result;
}

template class Tensor<float>;
template class Tensor<double>;

template std::vector<float> operator * (const std::vector<float>& a, const std::vector<float>& b);
template std::vector<int> operator * (const std::vector<int>& a, const std::vector<int>& b);

template std::vector<float> operator + (const std::vector<float>& a, const std::vector<float>& b);
template std::vector<int> operator + (const std::vector<int>& a, const std::vector<int>& b);