/**
 * @file heap_sort.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 堆排序：通过构建并维护大根堆小根堆来实现升序降序
 * @version 0.1
 * @date 2022-12-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

using std::cin, std::cout, std::endl;
using std::vector;

template <typename T>
void heap_sort(vector<T> &arr, int size);

template <typename T>
void sift_down(vector<T> &arr, int start, int end);

int main(int argc, char **argv)
{
    vector<int> arr {-71, 64, 5, 444, 3, 10, 2, -1};
    heap_sort(arr, arr.size());
    auto print = [&arr]() {
        for (auto i: arr)
            cout << i << ' ';
        cout << endl;
    };
    print();
    return 0;
}

template <typename T>
void heap_sort(vector<T> &arr, int size)
{
    for (int i = (size - 2) / 2; i >= 0; --i) sift_down(arr, i, size - 1);
    for (int i = size - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        sift_down(arr, 0, i - 1);
    }
}

template <typename T>
void sift_down(vector<T> &arr, int start, int end)
{
    int parent = start;
    int child = parent * 2 + 1;
    while (child <= end) {
        // 先比较两个子结点大小，选择最大的
        if (child + 1 <= end && arr[child] < arr[child + 1]) child++;
        // 如果父结点比子结点大，代表调整完毕，直接跳出函数
        if (arr[parent] >= arr[child])
            return;
        else {  // 否则交换父子内容，子结点再和孙结点比较
            std::swap(arr[parent], arr[child]);
            parent = child;
            child = parent * 2 + 1;
        }
    }
}