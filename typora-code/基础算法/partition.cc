/**
 * @file partition.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 递归和分治
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
using std::inplace_merge;


template <typename Iter>
void merge_sort_recursion(Iter begin, Iter end);

int main(int argc, char **argv)
{
    vector<int32_t> arr {7, 6, 5, 4, 3, 2, 1};
    merge_sort_recursion<vector<int32_t>::iterator>(arr.begin(), arr.end());
    auto print = [&arr]() {
        for (auto x: arr)
            cout << x << ' ';
        cout << endl;
    };
    print();
    return 0;
}

template <typename Iter>
void merge_sort_recursion(Iter begin, Iter end)
{
    if (end - begin <= 1) return;
    Iter mid = begin + ((end - begin) >> 1);
    merge_sort_recursion(begin, mid);
    merge_sort_recursion(mid, end);
    inplace_merge(begin, mid, end);
}
