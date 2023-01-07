/**
 * @file bucket_sort.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 桶排序：分块并对每个非空桶进行稳定排序
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
void bucket_sort(vector<T> &arr);

template <typename T>
void insert_sort(vector<T> &arr);

// 过快排模板题
void solve()
{
    // vector<int> arr {-71, 64, 5, 444, 3, 10, 2, -1};
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    bucket_sort(arr);
    auto print = [&arr]() {
        for (auto i: arr)
            cout << i << ' ';
        cout << endl;
    };
    print();
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}

template <typename T>
void bucket_sort(vector<T> &arr)
{
    T max_val = *std::max_element(arr.begin(), arr.end());
    T min_val = *std::min_element(arr.begin(), arr.end());
    const int block_nums = (1 << 10);
    auto bucket_size = (max_val - min_val) / block_nums + 1;
    vector<vector<T>> bucket(bucket_size);
    for (auto elem: arr)
        bucket[(elem - min_val) / block_nums].push_back(elem);
    int t = 0;
    for (auto &block: bucket) {
        insert_sort(block);
        for (auto elem: block)
            arr[t++] = elem;
    }
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