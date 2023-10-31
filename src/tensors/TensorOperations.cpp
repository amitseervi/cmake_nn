#include<tensors.h>
#include<stdexcept>

template <typename T>
Tensor<T> TensorOperationMul<T>::compute() {
	return Tensor<T>(this->a->value * this->b->value, this);
}

template <typename T>
Tensor<T> TensorOperationAdd<T>::compute() {
	return Tensor<T>(this->a->value + this->b->value, this);
}

template <typename T>
TensorBinaryOperation<T>::TensorBinaryOperation(Tensor<T>* a, Tensor<T>* b) : TensorBaseOperation<T>() {
	this->a = a;
	this->b = b;
}

template <typename T>
TensorOperationMul<T>::TensorOperationMul(Tensor<T>* a, Tensor<T>* b) : TensorBinaryOperation<T>(a, b) {

}

template <typename T>
TensorOperationAdd<T>::TensorOperationAdd(Tensor<T>* a, Tensor<T>* b) : TensorBinaryOperation<T>(a, b) {

}

template <typename T>
void TensorBinaryOperation<T>::backward(T grad) {
	if (this->a != NULL) {
		this->a->backward(grad);
	}
	if (this->a != NULL) {
		this->b->backward(grad);
	}
}

template <typename T>
Tensor<T> TensorBinaryOperation<T>::compute() {
	throw std::logic_error("Function Not implemented");
}

template <typename T>
void TensorBaseOperation<T>::backward(T grad) {
	throw std::logic_error("Function Not implemented");
}

template <typename T>
Tensor<T> TensorBaseOperation<T>::compute() {
	throw std::logic_error("Function Not implemented");
}

template class TensorBaseOperation<float>;
template class TensorBaseOperation<double>;

template class TensorBinaryOperation<float>;
template class TensorBinaryOperation<double>;

template class TensorOperationAdd<float>;
template class TensorOperationAdd<double>;

template class TensorOperationMul<float>;
template class TensorOperationMul<double>;