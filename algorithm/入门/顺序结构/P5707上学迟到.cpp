#include <bits/stdc++.h>

using namespace std;
int main(void)   {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long s, v;
    cin >> s >> v;
    long long t = ceil(1.0 * s / v);
    long long T = (7 + 24) * 60 + 50;
    T = T - t;
    cout << setw(2) << setfill('0') << T / 60 % 24 <<  ":" << setw(2) << setfill('0') << T % 60 << "\n";
    return 0;
}