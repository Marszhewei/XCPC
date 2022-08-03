#include <bits/stdc++.h>

using namespace std;
int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n;
    cin >> n;
    cout << (n * (n-1)/2 * (n-2)/3 * (n-3)/4) << "\n";
    return 0;
}