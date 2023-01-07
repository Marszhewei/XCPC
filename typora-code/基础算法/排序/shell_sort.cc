/**
 * @file shell_sort.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 希尔排序
 * @version 0.1
 * @date 2022-12-07
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
void shell_sort(vector<T> &arr);

int main(int argc, char **argv)
{
    vector<int> arr {-71, 64, 5, 444, 3, 10, 2, -1};
    shell_sort(arr);
    auto print = [&arr]() {
        for (auto i: arr)
            cout << i << ' ';
        cout << endl;
    };
    print(); 
     return 0;
}

// C++ Version
template <typename T>
void shell_sort(vector<T> &arr)
{
    size_t length = arr.size();
    int h = 1;
    while (h < length / 3)
        h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < length; i++)
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h)
                std::swap(arr[j], arr[j - h]);
        h = h / 3;
    }
}