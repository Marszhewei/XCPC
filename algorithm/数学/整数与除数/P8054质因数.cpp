#include <bits/stdc++.h>

using namespace std;

bool check(long long n)    {
    while (n > 2 && n % 2 == 0) n /= 2;
    if (n > 3) return true;
    return false;
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long T, n;
    cin >> T;
    while (T--)    {
        cin >> n;
        cout << (check(n) ? "1\n" : "0\n");
    }
    return 0;
}