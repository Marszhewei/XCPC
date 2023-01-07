/**
 * @file quick-sort.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 快速排序:通过分治实现
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
void quick_sort_solve(vector<T> &arr, T l, T r);

template <typename T>
void quick_sort(vector<T> &arr, T l, T r);

template <typename T>
void quick_sort(T arr[], const int len);

template <typename T>
T find_kth_element(T arr[], int rk, const int len);


int main(int argc, char** argv) 
{  
    vector<long long> arr {-71, 64, 5, 444, 3, 10, 2, -1};
    
    quick_sort<long long>(arr, 0, arr.size() - 1);
    auto print = [&arr]() {
        for (auto i: arr)
            cout << i << ' ';
        cout << endl;
    };
    print();

    long long a[] = {-71, 64, 5, 444, 3, 10, 2, -1};
    auto size = sizeof(a) / sizeof(long long);
    quick_sort<long long>(a, size);
    for (int i = 0; i < size; ++i)
        cout << a[i] << ' ';
    cout << endl;

    auto res = find_kth_element(a, 4, size);
    cout << "kth elem in a is: " << res << endl; 

    return 0;
}

template <typename T>
void quick_sort_solve(vector<T> &arr, T l, T r)
{
    if (l > r) return;
    T base = arr[l], left = l, right = r;
    while (left < right) {
        while (arr[right] > base && left < right)    
            right--;
        if (left < right) {
            arr[left] = arr[right];
            left++;
        }
        while (arr[left] < base && left < right)    
            left++;
        if (left < right) {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = base;
    quick_sort_solve(arr, l, left-1);
    quick_sort_solve(arr, left+1, r);
}

template <typename T>
void quick_sort(vector<T> &arr, T l, T r)
{
    std::random_shuffle(arr.begin(), arr.end());
    quick_sort_solve<long long>(arr, l, r);
}

// 三路快速排序在处理含有多个重复值的数组时，效率远高于原始快速排序。其最佳时间复杂度为O(n)
template <typename T>
void quick_sort(T arr[], const int len)
{
    if (len <= 1) return;
    const T pivot = arr[rand() % len];
    int i = 0, j = 0, k = len;
    while (i < k) {
        if (arr[i] < pivot)
            std::swap(arr[i++], arr[j++]);
        else if (pivot < arr[i])
            std::swap(arr[i], arr[--k]);
        else
            i++;
    }
    quick_sort(arr, j);
    quick_sort(arr + k, len - k);
}

// 寻找第K大的数（线性）
// 模板的 T 参数表示元素的类型，此类型需要定义小于（<）运算
template <typename T>
// arr 为查找范围数组，rk 为需要查找的排名（从 0 开始），len 为数组长度
T find_kth_element(T arr[], int rk, const int len) {
  if (len <= 1) return arr[0];
  // 随机选择基准（pivot）
  const T pivot = arr[rand() % len];
  // i：当前操作的元素
  // j：第一个等于 pivot 的元素
  // k：第一个大于 pivot 的元素
  int i = 0, j = 0, k = len;
  // 完成一趟三路快排，将序列分为：
  // 小于 pivot 的元素 ｜ 等于 pivot 的元素 ｜ 大于 pivot 的元素
  while (i < k) {
    if (arr[i] < pivot)
      std::swap(arr[i++], arr[j++]);
    else if (pivot < arr[i])
      std::swap(arr[i], arr[--k]);
    else
      i++;
  }
  // 根据要找的排名与两条分界线的位置，去不同的区间递归查找第 k 大的数
  // 如果小于 pivot 的元素个数比k多，则第 k 大的元素一定是一个小于 pivot 的元素
  if (rk < j) return find_kth_element(arr, rk, j);
  // 否则，如果小于 pivot 和等于 pivot 的元素加起来也没有 k 多，
  // 则第 k 大的元素一定是一个大于 pivot 的元素
  else if (rk >= k)
    return find_kth_element(arr + k, rk - k, len - k);
  // 否则，pivot 就是第 k 大的元素
  return pivot;
}