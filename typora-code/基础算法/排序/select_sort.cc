/**
 * @file select_sort.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 选择排序：每次找出第i小的元素并把他放在正确的位置上
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
void select_sort(vector<T> &arr);


int main(int argc, char **argv)
{
    vector<int> arr {7, 6, 5, 4, 3, 1, 2, -1};
    select_sort(arr);
    auto print = [&arr]() {
        for (auto i: arr)
            cout << i << ' ';
        cout << endl;
    };
    print();
    
    return 0;
}

template <typename T>
void select_sort(vector<T> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size - 1; ++i) {
        int ith = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[ith])
                ith = j;
        }
        std::swap(arr[ith], arr[i]);
    }
}