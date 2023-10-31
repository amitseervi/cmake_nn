#ifndef __HEADER_TENSORS__
#define __HEADER_TENSORS__
#define NULL 0

template <typename T>
class Tensor;

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
	T* grad;
public:
	T value;
	Tensor(T v);
	Tensor(T v, TensorBaseOperation<T>* backward_operation);
	Tensor<T> operator +(Tensor<T> a);
	Tensor<T> operator *(Tensor<T> a);
	void backward(T grad);
	T get_grad();
};

template <typename T>
class TensorBinaryOperation : public TensorBaseOperation<T> {
protected:
	Tensor<T>* a;
	Tensor<T>* b;
public:
	TensorBinaryOperation(Tensor<T>* a, Tensor<T>* b);
	void backward(T grad);
	virtual Tensor<T> compute();
};


template <typename T>
class TensorOperationAdd : public TensorBinaryOperation<T> {
public:
	TensorOperationAdd(Tensor<T>* a, Tensor<T>* b);
	Tensor<T> compute();
};

template <typename T>
class TensorOperationMul : public TensorBinaryOperation<T> {
public:
	TensorOperationMul(Tensor<T>* a, Tensor<T>* b);
	Tensor<T> compute();
};

#endif
