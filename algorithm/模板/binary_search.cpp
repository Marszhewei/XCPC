#include <bits/stdc++.h>


// bool BS(int* arr, int n)    {
//     int left = 0, right = 6, mid = 3;
//     while (left <= right)    {
//         mid = (left + right) / 2;
//         std::cout << arr[mid] << " ";
//         if (n == arr[mid])    return true;
//         else if (n < arr[mid])    right = mid-1;
//         else    left = mid + 1;
//     }
//     return false;
// }

// int ar[] {7, 9, 13, 17, 26, 29, 31};
// bool is = false;
// void BS_D(int left, int right, int n)     {
//     if (left > right)    return;
//     int mid = (left + right) / 2;
//     if (n == ar[mid])    {is = true;return;}
//     else if (n < ar[mid])    BS_D(left, mid-1, n);
//     else BS_D(mid+1, right, n);
//     return;
// }



// [left, right)    左闭右开
bool BS(std::vector<int> v, int n)    {
    int left = 0, right = v.size(), mid = (left + right) / 2;
    while (left < right)    {
        mid = (left + right) / 2;
        if (n == v[mid])    return true;
        else if (n < v[mid])    right = mid;
        else    left = mid + 1;
    }
    return false;
}

// [left, right]    左闭右闭
bool BS_1(std::vector<int> v, int n)    {
    int left = 0, right = v.size() - 1, mid = (left + right) / 2;
    while (left <= right)    {
        mid = (left + right) / 2;
        if (v[mid] == n)    return true;
        else if (v[mid] < n)    left = mid + 1;
        else    right = mid - 1;
    }
    return false;
}


using namespace std;
int main(void)    {
    int arr[] {7, 9, 13, 17, 26, 29, 31};

    // test bs
    vector<int> v {7, 9, 13, 17, 26, 29, 31};
    int j = 1;
    // iota(v.begin(), v.end(), 1);
    for (auto i: v)    cout << j++ << ":" << (BS(v, i) ? "YES" : "NO") << "\n";
    cout << "-----------------------\n";
    for (auto i: v)    cout << j++ << ":" << (BS(v, i+1) ? "YES" : "NO") << "\n";
    cout << "-----------------------\n";
    for (auto i: v)    cout << j++ << ":" << (BS(v, i-1) ? "YES" : "NO") << "\n";

    cout << "\n***********************\n\n";
    for (auto i: v)    cout << j++ << ":" << (BS_1(v, i) ? "YES" : "NO") << "\n";
    cout << "-----------------------\n";
    for (auto i: v)    cout << j++ << ":" << (BS_1(v, i+1) ? "YES" : "NO") << "\n";
    cout << "-----------------------\n";
    for (auto i: v)    cout << j++ << ":" << (BS_1(v, i-1) ? "YES" : "NO") << "\n";

    // bool ok = BS(arr, 26);
    // cout << (ok ? "YES" : "NO") << "\n";
    // BS_D(0, 6, 0);
    // cout << (is ? "YES" : "NO") << "\n";

    return 0;
}