/**
 * @file bubble_sort.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 冒泡排序：小的数上浮，像冒泡一样
 * @version 0.1
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

using std::cin, std::cout, std::endl;
using std::vector;

template <typename T>
void bubble_sort(vector<T> &arr);

int main(int argc, char **argv)
{
    vector<int> arr {7, 6, 5, 4, 3, 1, 2, -1};
    bubble_sort(arr);
    auto print = [&arr]() {
        for (auto i: arr)
            cout << i << ' ';
        cout << endl;
    };
    print();

    return 0;
}

template <typename T>
void bubble_sort(vector<T> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (arr[j+1] < arr[j])
                std::swap(arr[j+1], arr[j]);
        }
    }
}