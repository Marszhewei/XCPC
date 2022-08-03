#include <bits/stdc++.h>

using namespace std;

long long quick_pow(long long a, long long b, long long mod)    {
    long long res = 1;
    while (b)    {
        if (b&1)    res = res * a % mod;
        b >>= 1;
        a *= a % mod;
    }
    return res;
}

int main(void)    {
    cout << quick_pow(8, 3, 7) << "\n";
    return 0;
}