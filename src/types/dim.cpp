#include<string>
#include<types/dim.h>

template <typename T>
Vector1<T>::Vector1(T x):x(x) {
}

template <typename T>
Vector2<T>::Vector2(T x, T y) :Vector1<T>(x), y(y) {
}

template <typename T>
Vector3<T>::Vector3(T x, T y, T z) : Vector2<T>(x, y),z(z) {
}

template class Vector1<float>;
template class Vector2<float>;
template class Vector3<float>;

template class Vector1<int>;
template class Vector2<int>;
template class Vector3<int>;

template class Vector1<long>;
template class Vector2<long>;
template class Vector3<long>;

template class Vector1<double>;
template class Vector2<double>;
template class Vector3<double>;
