#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < s.size(); ++i) res += (s[i] ^ 48);
    cout << res << '\n';
    return 0;
}