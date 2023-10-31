#include<tensors.h>
#include<stdexcept>

template <typename T>
Tensor<T>::Tensor(T v) {
	this->value = v;
	this->grad = NULL;
	this->backward_operation = NULL;
	this->forward_operation = NULL;
}

template <typename T>
Tensor<T>::Tensor(T v, TensorBaseOperation<T>* backward_operation) {
	this->value = v;
	this->grad = NULL;
	this->backward_operation = backward_operation;
	this->forward_operation = NULL;
}

template <typename T>
Tensor<T> Tensor<T>::operator +(Tensor<T> a) {
	forward_operation = new TensorOperationAdd<T>(this, &a);
	return forward_operation->compute();
}

template <typename T>
Tensor<T> Tensor<T>::operator *(Tensor<T> a) {
	forward_operation = new TensorOperationMul<T>(this, &a);
	return forward_operation->compute();
}

template <typename T>
void Tensor<T>::backward(T grad) {
	this->grad = &grad;
	if (this->backward_operation != NULL) {
		this->backward_operation->backward(grad);
	}
}

template <typename T>
T Tensor<T>::get_grad(){
	if (this->grad == NULL) {
		throw std::logic_error("Grad not present");
	}
	return *(this->grad);
}

template class Tensor<float>;
template class Tensor<double>;