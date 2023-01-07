/**
 * @file merge_sort.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 归并排序：分治
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
using std::inplace_merge;


template <typename Iter>
void merge_sort(Iter begin, Iter end);

int main(int argc, char **argv)
{
    vector<int32_t> arr {7, -6, 5, 4, -3, 2, 1};
    merge_sort<vector<int32_t>::iterator>(arr.begin(), arr.end());
    auto print = [&arr]() {
        for (auto x: arr)
            cout << x << ' ';
        cout << endl;
    };
    print();
    return 0;
}

template <typename Iter>
void merge_sort(Iter begin, Iter end)
{
    if (end - begin <= 1) return;
    Iter mid = begin + ((end - begin) >> 1);
    merge_sort(begin, mid);
    merge_sort(mid, end);
    inplace_merge(begin, mid, end);
}

// array version
int tmp[100], a[100];
void merge(int l, int r) {
    if (r - l <= 1) return;
    int mid = l + ((r - l) >> 1);
    merge(l, mid), merge(mid, r);
    for (int i = l, j = mid, k = l; k < r; ++k) {
        if (j == r || (i < mid && a[i] <= a[j]))
            tmp[k] = a[i++];
        else
            tmp[k] = a[j++];
    }
    for (int i = l; i < r; ++i) a[i] = tmp[i];
}