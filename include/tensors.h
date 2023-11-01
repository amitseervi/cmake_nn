#include<vector>
#ifndef __HEADER_TENSORS__
#define __HEADER_TENSORS__
#define NULL 0

template <typename T>
class Tensor;

template <typename T>
class Gradient {
public:
	T data;
	Gradient(T v);
};

template <typename T>
class TensorBaseOperation {
public:
	virtual void backward(T grad);
	virtual Tensor<T> compute();
};

template <typename T>
class Tensor {
private:
	TensorBaseOperation<T>* backward_operation;
	TensorBaseOperation<T>* forward_operation;
	Gradient<T>* grad_holder;
public:
	T value;
	Tensor(T v);
	Tensor(T v, TensorBaseOperation<T>* backward_operation);
	Tensor<T> operator +(Tensor<T> &a);
	Tensor<T> operator *(Tensor<T> &a);
	void backward(T grad);
	T get_grad();
};

template <typename T>
class TensorBinaryOperation : public TensorBaseOperation<T> {
public:
	Tensor<T>* a;
	Tensor<T>* b;
	TensorBinaryOperation(Tensor<T>* a, Tensor<T>* b);
	virtual void backward(T grad);
	virtual Tensor<T> compute();
};


template <typename T>
class TensorOperationAdd : public TensorBinaryOperation<T> {
public:
	TensorOperationAdd(Tensor<T>* a, Tensor<T>* b);
	Tensor<T> compute();
	void backward(T grad);
};

template <typename T>
class TensorOperationMul : public TensorBinaryOperation<T> {
public:
	TensorOperationMul(Tensor<T>* a, Tensor<T>* b);
	Tensor<T> compute();
	void backward(T grad);
};

template <typename T>
std::vector<T> operator * (const std::vector<T>& a, const std::vector<T>& b);

template <typename T>
std::vector<T> operator + (const std::vector<T>& a, const std::vector<T>& b);

#endif
