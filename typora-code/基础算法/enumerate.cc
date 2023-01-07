/**
 * @file enumerate.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 基础算法枚举
 * @version 0.1
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>

using std::cin, std::cout, std::endl;
using std::pair, std::vector, std::bitset;
using std::make_pair;
using std::shuffle, std::random_device;

vector<pair<int32_t, int32_t>> target_sum_pairs(const vector<int32_t>& arr, int32_t target);

int main(int argc, char **argv)
{
    vector<int32_t> arr {1, -1, 2, 3, -3, 7, -8, 10, -10, 11, -12, 13, 14};
    shuffle(arr.begin(), arr.end(), random_device());
    auto print = [](const vector<int32_t>& arr) {
        for (auto &x: arr)
            cout << x << ' ';
        cout << endl;
    };
    print(arr);
    auto res = target_sum_pairs(arr, 0);
    auto print_res = [&res]() {
        for (auto &pr: res)
            cout << '{' << pr.first << ", " << pr.second << "}\n";
    };
    print_res();
    return 0;
}

vector<pair<int32_t, int32_t>> target_sum_pairs(const vector<int32_t>& arr, int32_t target)
{
    vector<pair<int32_t, int32_t>> res;
    int len = arr.size();
    // 如果数据很大
    /* for (int i = 0; i < len - 1; ++i)
        for (int j = i + 1; j < len; ++j)
            if (arr[i] + arr[j] == target)
                res.push_back(make_pair(arr[i], arr[j]));
    return res; */
    // 如果数据不是特别大，用空间换时间，使用桶来记录遍历过的数
    bitset<UINT16_MAX> met(0);
    for (int i = 0; i < len; ++i) {
        if (met[INT16_MAX - arr[i]] == 1)
            res.push_back(make_pair(arr[i], -arr[i]));
        met.set(INT16_MAX + arr[i]);
    }
    return res;
}
