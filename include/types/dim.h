#include<string>
#ifndef __HEADER_DIM__
#define __HEADER_DIM__

template <class T>
class Vector1 {
public:
	const T x;
	Vector1(T x);
};

template <class T>
class Vector2 : public Vector1<T> {
public:
	const T y;
	Vector2(T x, T y);
};

template <class T>
class Vector3 :public Vector2<T> {
public:
	const T z;
	Vector3(T x, T y, T z);
};
#endif