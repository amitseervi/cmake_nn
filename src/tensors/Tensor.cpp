#include<tensors.h>
#include<stdexcept>
#include<iostream>

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



template <typename T>
Tensor<T>::Tensor(T v, TensorBaseOperation<T>* backward_operation) {
	this->value = v;
	this->grad_holder = NULL;
	this->backward_operation = backward_operation;
	this->forward_operation = NULL;
}

template <typename T>
Tensor<T> Tensor<T>::operator +(Tensor<T> &a) {
	forward_operation = new TensorOperationAdd<T>(this, &a);
	return forward_operation->compute();
}

template <typename T>
Tensor<T> Tensor<T>::operator *(Tensor<T> &a) {
	forward_operation = new TensorOperationMul<T>(this, &a);
	return forward_operation->compute();
}

template <typename T>
void Tensor<T>::backward(T grad) {
	if (this->grad_holder != NULL) {
		free(this->grad_holder);
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

template class Tensor<float>;
template class Tensor<double>;