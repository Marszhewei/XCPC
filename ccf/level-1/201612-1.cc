#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)    {
        int t; cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    int len = a.size(), mid = len/2, mid1 = len/2-1;
    bool flag = false;
    if (len >> 1) flag = true;
    if (flag)    {
        for (int i = 1; i < len/2; ++i)
            if (a[mid] != a[mid-i] && a[mid] == a[mid+i] || 
                a[mid] == a[mid-i] && a[mid] != a[mid+i]) {cout << -1 << '\n'; return 0;} 
        cout << a[mid] << '\n'; 
    }
    else {
        if (a[mid] != a[mid1]) {cout << -1 << '\n'; return 0;}
        for (int i = 1; i < len/2; ++i) 
            if (a[mid1] != a[mid1-i] && a[mid] == a[mid+i] || 
                a[mid1] == a[mid1-i] && a[mid] != a[mid+i]) {cout << -1 << '\n'; return 0;}
        cout << a[mid] << '\n';
    }
    return 0;
}