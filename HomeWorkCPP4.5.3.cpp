#include <iostream>
#include <algorithm>

template <class T> class NumberCounter {
public:
    NumberCounter(unsigned int num_const) :_num_const(static_cast<T>(num_const)){}

    T get_sum() {
        return _sum;
    }

    T get_count() {
        return _count;
    }

    void operator () (T number) {
        if (number % _num_const == 0) {
            _sum += number;
            _count++;
        }
    }

private:
    T _sum = 0;
    T _count = 0;
    T _num_const = 1;
};

int main()
{
    const int size = 6;
    int arr[size]{ 4, 1, 3, 6, 25, 54 };

    NumberCounter<int> calc(3);
    calc = std::for_each(arr, arr + size, calc);

    std::cout << "[IN]: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "[OUT]: get_sum() = " << calc.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << calc.get_count() << std::endl;
} 