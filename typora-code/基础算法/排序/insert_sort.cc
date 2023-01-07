/**
 * @file insert_sort.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 插入排序：分为有序区和无序区，每次将一个无序区的数拿出来放到有序区并保持有序区有序
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
void insert_sort(vector<T> &arr);

int main(int argc, char **argv)
{
    vector<int> arr {7, 6, 5, 4, 3, 1, 2, -1};
    insert_sort(arr);
    auto print = [&arr]() {
        for (auto i: arr)
            cout << i << ' ';
        cout << endl;
    };
    print();
}

template <typename T>
void insert_sort(vector<T> &arr)
{
    int size = arr.size();
    for (int i = 1; i < size; ++i) {
        T tmp = arr[i];
        int j = i - 1;
        for ( ; j >= 0 && tmp < arr[j]; --j)
            arr[j + 1] = arr[j];
        arr[j + 1] = tmp;
    }
}