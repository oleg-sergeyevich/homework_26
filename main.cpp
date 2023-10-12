#include <iostream>

#include "Array.h"

int main()
{
    int size = 1000000;
    const int size_max = 1000000000;
    const short threads[]{ 12, 10, 8, 6, 4, 1 };
    
    while (size <= size_max)
    {
        {
            Array array(size);
            for (const auto t : threads)
            {
                auto start = clock();
                long long sum = array.sumArray(t);
                auto end = clock();
                auto time = difftime(end, start);
                std::cout << "array size: " << size << ", sum in " << t
                    << " threads: " << sum << ", time: " << time << std::endl;
            }
        }
        std::cout << std::endl;
        size *= 10; 
    }
    return 0;
}