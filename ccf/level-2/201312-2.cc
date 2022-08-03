#include <bits/stdc++.h>
using namespace std;
#define i64 long long

char mp[] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'X'};
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    i64 k = 1, ss = 0;
    for (i64 i = 0; i < 12; ++i) {
        if (s[i] != '-') {
            ss += (s[i] ^ 48) * (k++);
        }
    }
    ss %= 11;
    if (mp[ss] == s.back()) cout << "Right\n";
    else { s[12] = mp[ss]; cout << s << '\n';}
    return 0;
}