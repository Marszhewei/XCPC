#include <bits/stdc++.h>

using namespace std;
int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    cout << ((!(n%400) || !(n%4) && (n%100)) ? 1 : 0) << "\n";
    return 0;
}