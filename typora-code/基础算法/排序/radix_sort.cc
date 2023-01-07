/**
 * @file radix_sort.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 基数排序:按位排序
 * @version 0.1
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin, std::cout, std::endl;
using std::vector;

template <typename T>
void radix_sort(vector<T> &arr);

int main(int argc, char **argv)
{
    vector<int> arr {-71, 64, 5, 444, 3, 10, 2, -1};
    radix_sort(arr);
    auto print = [&arr]() {
        for (auto i: arr)
            cout << i << ' ';
        cout << endl;
    };
    print();

    return 0;
}

template <typename T>
void radix_sort(vector<T> &arr)
{
    size_t size = arr.size();
    vector<T> cnt(10, 0);
    vector<T> tmp(size, 0);
    T max_val = *(std::max_element(arr.begin(), arr.end()));
    T min_val = *(std::min_element(arr.begin(), arr.end()));
    int max_digits = 0;
    while (max_val) {
        ++max_digits;
        max_val /= 10;
    }
    int base = 1;

    for (int k = 0; k < max_digits; ++k) {
        std::fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < size; ++i)
            ++cnt[((arr[i] - min_val) / base) % 10];
        
        for (int i = 0, t = 0; i < 10; ++i)
            for (int j = 0; j < size; ++j)
                if (((arr[j] - min_val) / base) % 10 == i)
                    tmp[t++] = arr[j];
        for (int i = 0; i < size; ++i)
            arr[i] = tmp[i];
        base *= 10;
    }
}
