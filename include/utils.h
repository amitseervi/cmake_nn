#include<vector>
#include<functional>

#ifndef __HEADER_UTILS__
#define __HEADER_UTILS__
template <typename T>
void vector_for_each(std::vector<T> v, std::function<void(T)> callback);
#endif