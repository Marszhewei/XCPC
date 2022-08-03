#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long n)    {
    for (int i = 2; i <= sqrt(n); ++i)    {
        if (!(n % i)) return false;
    }
    return true;
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long L, cnt = 0, s = 0;
    cin >> L;

    for (int i = 2; s <= L; ++i)    {
        if (is_prime(i)) {s += i;if (s <= L)cout << i << "\n";cnt++;}
    }
    cout << cnt-1 << "\n";
    return 0;
}
