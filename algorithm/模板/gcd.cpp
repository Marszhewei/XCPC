#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)    {
    if (!b)    return a;
    return gcd(b, a%b);
}

long long gcd_1(long long a, long long b)    {
    while (b^=a^=b^=a%=b);
    return a;
}

long long gcd_2(long long a, long long b)    {
    long long r;
    while (a%b)    {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int main(void)    {
    cout << gcd(27, 18) << "\n";
    cout << gcd_1(27, 21) << "\n";
    cout << gcd_2(27, 18) << "\n";
    cout << gcd_2(27, 21) << "\n";
    return 0;
}