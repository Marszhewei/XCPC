/**
 * @file counting_sort.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 计数排序：记录每个元素出现的次数，求前缀和，根据前缀和由右到左给出排名
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
void counting_sort(vector<T> &arr);

int main(int argc, char **argv)
{
    vector<int> arr {7, 6, 5, 4, 3, 1, 2, -1};
    counting_sort(arr);
    auto print = [&arr]() {
        for (auto i: arr)
            cout << i << ' ';
        cout << endl;
    };
    print();
    return 0;
}

template <typename T>
void counting_sort(vector<T> &arr)
{
    T max_val = *(std::max_element(arr.begin(), arr.end()));
    T min_val = *(std::min_element(arr.begin(), arr.end()));
    int size = arr.size();
    vector<T> cnt(max_val - min_val + 1, 0);
    vector<T> tmp(arr);
    for (int i = 0; i < size; ++i) ++cnt[arr[i] - min_val];
    for (int i = 1; i <= max_val - min_val; ++i) cnt[i] += cnt[i-1];
    for (int i = size - 1; i >= 0; --i) arr[--cnt[tmp[i] - min_val]] = tmp[i];
}