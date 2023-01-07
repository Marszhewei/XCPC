/**
 * @file stl_sort.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 排序相关的STL
 * @version 0.1
 * @date 2022-12-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // qsort

using std::cin, std::cout, std::endl;
using std::vector;

void test_qsort();
void test_sort();
void test_nth_element();
void test_partial_sort();

int main(int argc, char **argv)
{
    test_qsort();
    test_sort();
    test_nth_element();
    test_partial_sort();

    return 0;
}

// for qsort cmp
int compare(const void *p1, const void *p2)
{
    int *a = (int *)p1;
    int *b = (int *)p2;
    if (*a > *b)
        return 1;
    else if (*a < *b)
        return -1;
    else
        return 0;
}

struct eg
{
    int e, g;
    bool operator<(const struct eg &x) const
    {
        return this->e < x.e;
    }
};

int compare_eg(const void *p1, const void *p2)
{
    struct eg *a = (struct eg*)p1;
    struct eg *b = (struct eg*)p2;
    if (a->e > b->e)
        return 1;
    else if (a->e < b->e)
        return -1;
    else
        return 0;
}

void test_qsort()
{
    int a[] = {3, -10, 7, 7, 10, -1, 0, 2, -2};
    int length = sizeof(a) / sizeof(a[0]);
    std::qsort(a, length, sizeof(a[0]), compare);
    for (int i = 0; i < length; ++i)
        cout << a[i] << ' ';
    cout << endl;

    struct eg a_eg[] = {
        {-1, 100},
        {-10, -1000},
        {10, 0},
        {8, 90},
        {100, -10},
        {6, 7}
    };
    length = sizeof(a_eg) / sizeof(a_eg[0]);
    std::qsort(a_eg, length, sizeof(a_eg[0]), compare_eg);
    for (int i = 0; i < length; ++i)
        cout << '{' << a_eg[i].e << ", " << a_eg[i].g << "} ";
    cout << endl; 
}

void test_sort()
{
    vector<int> arr {3, -10, 7, 7, 10, -1, 0, 2, -2};
    std::sort(arr.begin(), arr.end(), std::less<int>()); // 升序
    // std::sort(arr.begin(), arr.end(), std::greater<int>()); // 降序
    for (auto x: arr)
        cout << x << ' ';
    cout << endl;
    vector<struct eg> a_eg {
        {-1, 100},
        {-10, -1000},
        {10, 0},
        {8, 90},
        {100, -10},
        {6, 7}
    };
    auto cmp = [](const struct eg &a, const struct eg &b) {
        return a.e < b.e;
    };
    // std::sort(a_eg.begin(), a_eg.end(), cmp); // use cmp
    std::sort(a_eg.begin(), a_eg.end()); // overload operator<
    for (auto &x: a_eg)
        cout << '{' << x.e << ", " << x.g << "} ";
    cout << endl;
    // std::stable_sort(first, last);
    // std::stable_sort(first, last, cmp);
}

void test_nth_element()
{
    vector<int> arr {3, -10, 7, 7, 10, -1, 0, 2, -2};
    std::nth_element(arr.begin(), arr.begin(), arr.end());
    for (auto x: arr)
        cout << x << ' ';
    cout << endl;
    vector<struct eg> a_eg {
        {-1, 100},
        {-10, -1000},
        {10, 0},
        {8, 90},
        {100, -10},
        {6, 7}
    };
    auto cmp = [](const struct eg &a, const struct eg &b) {
        return a.e < b.e;
    };
    // std::nth_element(a_eg.begin(), a_eg.begin(), a_eg.end(), cmp); // use cmp
    std::nth_element(a_eg.begin(), a_eg.begin(), a_eg.end()); // overload operator<
    for (auto &x: a_eg)
        cout << '{' << x.e << ", " << x.g << "} ";
    cout << endl;
}

void test_partial_sort()
{
    vector<int> arr {3, -10, 7, 7, 10, -1, 0, 2, -2};
    std::partial_sort(arr.begin(), arr.begin() + 2, arr.end());
    for (auto x: arr)
        cout << x << ' ';
    cout << endl;
    vector<struct eg> a_eg {
        {-1, 100},
        {-10, -1000},
        {10, 0},
        {8, 90},
        {100, -10},
        {6, 7}
    };
    auto cmp = [](const struct eg &a, const struct eg &b) {
        return a.e < b.e;
    };
    // std::nth_element(a_eg.begin(), a_eg.begin() + 2, a_eg.end(), cmp); // use cmp
    std::partial_sort(a_eg.begin(), a_eg.begin() + 2, a_eg.end()); // overload operator<
    for (auto &x: a_eg)
        cout << '{' << x.e << ", " << x.g << "} ";
    cout << endl;
}