#include<tensors.h>
#include<stdexcept>
#include<iostream>

// --------------------
// TensorBaseOperation<T>
// --------------------

template <typename T>
void TensorBaseOperation<T>::backward(T grad) {
	throw std::logic_error("Function Not implemented");
}

//template <typename T>
//TensorBaseOperation<T>::~TensorBaseOperation() {
//	std::cout << "Tensor base operation nothing to do here\n";
//}

template <typename T>
Tensor<T> TensorBaseOperation<T>::compute() {
	throw std::logic_error("Function Not implemented");
}

// --------------------
// TensorBinaryOperation<T>
// --------------------

template <typename T>
TensorBinaryOperation<T>::TensorBinaryOperation(Tensor<T>* a, Tensor<T>* b) : TensorBaseOperation<T>() {
	this->a = a;
	this->b = b;
}

template <typename T>
Tensor<T> TensorBinaryOperation<T>::compute() {
	throw std::logic_error("Function Not implemented");
}

template <typename T>
void TensorBinaryOperation<T>::backward(T grad) {

}

//template <typename T>
//TensorBinaryOperation<T>::~TensorBinaryOperation() {
//	if (this->a != NULL) {
//		free(this->a);
//	}
//	if (this->b != NULL) {
//		free(this->b);
//	}
//}

// --------------------
// TensorOperationMul<T>
// --------------------

template <typename T>
TensorOperationMul<T>::TensorOperationMul(Tensor<T>* a, Tensor<T>* b) : TensorBinaryOperation<T>(a, b) {

}

template <typename T>
Tensor<T> TensorOperationMul<T>::compute() {
	return Tensor<T>(this->a->value * this->b->value, this);
}

template <typename T>
void TensorOperationMul<T>::backward(T grad) {
	this->a->backward(grad * this->b->value);
	this->b->backward(grad * this->a->value);
}

//template <typename T>
//TensorOperationMul<T>::~TensorOperationMul() {
//
//}

// --------------------
// TensorOperationAdd<T>
// --------------------

template <typename T>
TensorOperationAdd<T>::TensorOperationAdd(Tensor<T>* a, Tensor<T>* b) : TensorBinaryOperation<T>(a, b) {

}

template <typename T>
Tensor<T> TensorOperationAdd<T>::compute() {
	return Tensor<T>(this->a->value + this->b->value, this);
}


template <typename T>
void TensorOperationAdd<T>::backward(T grad) {
	this->a->backward(grad);
	this->b->backward(grad);

}

//template <typename T>
//TensorOperationAdd<T>::~TensorOperationAdd() {
//
//}


// --------------------
// Possible Templates
// --------------------


template class TensorBaseOperation<float>;
template class TensorBaseOperation<double>;

template class TensorBinaryOperation<float>;
template class TensorBinaryOperation<double>;

template class TensorOperationAdd<float>;
template class TensorOperationAdd<double>;

template class TensorOperationMul<float>;
template class TensorOperationMul<double>;