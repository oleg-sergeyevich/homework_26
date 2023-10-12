#pragma once
#include <vector>

class Array
{
public:
	Array() = default;

	~Array() = default;

	Array(const int size);

	int sumArray(const short number_threads);

private:
	int size_ = 0;
	std::vector<int> array_;

	void sumThread(size_t l_index, size_t r_index, int* array_sum, size_t i);
};