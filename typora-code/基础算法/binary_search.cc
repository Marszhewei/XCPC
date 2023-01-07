/**
 * @file binary_search.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 二分查找
 * @version 0.1
 * @date 2022-12-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <iomanip>

using std::cin, std::cout, std::endl;
using std::vector, std::pair;
using std::make_pair;
using std::lower_bound, std::upper_bound;

pair<bool, vector<int32_t>::iterator> binary_search(vector<int32_t>&, int32_t);
pair<bool, vector<int32_t>::iterator> bs_stl(vector<int32_t>& arr, int32_t x);

void solve();
void solve_();


int main(int argc, char **argv)
{
    // vector<int32_t> arr {1, 3, 7, 10, 11, 12, 12, 90, 117, 231};
    // for (auto x: arr) {
    //     auto res = binary_search(arr, x + 1);
    //     if (res.first) cout << "find it : " << *res.second << endl;
    //     else cout << "not found.\n";
    //     auto res_stl = binary_search(arr, x + 1);
    //     if (res_stl.first) cout << "find it : " << *res_stl.second << endl;
    //     else cout << "not found.\n";
    // }
    solve_();

    return 0;
}

pair<bool, vector<int32_t>::iterator> binary_search(vector<int32_t>& arr, int32_t x)
{
    auto left = arr.begin(), right = arr.end();
    auto mid = arr.begin() + (arr.size() / 2);
    while (left < right) {
        if (*mid < x) left = mid + 1;
        else if (*mid > x) right = mid;
        else return make_pair(true, mid);
        mid = left + (right - left) / 2;
    }
    return make_pair(false, arr.end());
}

// std::lower_bound and std::upper_bound
pair<bool, vector<int32_t>::iterator> bs_stl(vector<int32_t>& arr, int32_t x)
{
    auto second = lower_bound(arr.begin(), arr.end(), x);
    if (second != arr.end()) return make_pair(true, second);
    else return make_pair(false, second);
}

// luogu P1873
bool check(int64_t m, int h, const vector<int> &arr)
{
    int64_t sum = 0;
    for (auto x: arr)
        sum += std::max((x - h), 0);
    return sum >= m;
}

void solve()
{
    int n; int64_t m; cin >> n >> m;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    int l = 0, r = 1e9+1, mid = 0;
    while (l < r) {
        mid = l + ((r - l) >> 1);
        if (check(m, mid, arr))
            l = mid + 1;
        else
            r = mid;
    }
    cout << l - 1 << endl;
}

// luogu P3382
double f(vector<double> &a, double x)
{
    double fx = 0.0;
    int n = a.size();
    for (int i = n; i >= 0; --i)
        fx += std::pow(x, i) * a[i];
    return fx;
}

void solve_()
{
    const double eps = 1e-6;
    int n; double l, r; cin >> n >> l >> r;
    vector<double> a(n+1, 0.0);
    for (int i = n; i >= 0; --i)
        cin >> a[i];
    double mid, lmid, rmid;
    while (r - l > eps) {
        mid = (l + r) / 2;
        lmid = mid - eps;
        rmid = mid + eps;
        if (f(a, lmid) > f(a, rmid))
            r = mid;
        else
            l = mid;
    }
    cout << std::setprecision(6) << l << endl;
}
