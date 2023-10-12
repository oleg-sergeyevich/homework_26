#include <cstdlib>
#include <ctime>
#include <thread>

#include "Array.h"

Array::Array(const int size) : size_(size)
{
    array_.reserve(size_);
    srand(std::time(0));
    for (int i = 0; i < size_; i++)
    {
        array_.push_back(rand() % 100);
    }
}

void Array::sumThread(size_t l_index, size_t r_index, long long* array_sum, size_t i)
{
    long long sum = 0;
    while (l_index <= r_index)
    {
        sum += array_.at(l_index);
        l_index++;
    }
    array_sum[i] = sum;
}

long long Array::sumArray(const short number_threads)
{
    std::vector<std::thread> threads;
    long long array_sum[12]{};
    size_t l_index = 0;
    size_t r_index = 0;
    size_t interval = size_ / number_threads;

    for (size_t i = 0; i < number_threads; i++)
    {
        if (number_threads == i + 1)
        {
            r_index = array_.size();
        }
        else
        {
            r_index += interval;
        }
        std::thread t(&Array::sumThread, this, l_index, r_index - 1, array_sum, i);
        threads.push_back(std::move(t));
        l_index += interval;
    }

    for (auto& t : threads)
    {
        if (t.joinable())
            t.join();
    }

    long long sum = 0;
    for (const auto& i : array_sum)
    {
        sum += i;
    }
    return sum;
}