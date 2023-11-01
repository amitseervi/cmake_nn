#include<utils.h>

template <typename T>
void vector_for_each(std::vector<T> v, std::function<void(T)> callback) {
	int n = v.size();
	for (int i = 0; i < n; i++) {
		callback(v[i]);
	}
}

template void vector_for_each(std::vector<float> v, std::function<void(float)> callback);
template void vector_for_each(std::vector<int> v, std::function<void(int)> callback);