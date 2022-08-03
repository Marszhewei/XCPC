#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define rep(i, n) for (int i = 0; i < n; ++i)

// bool cmp(const string& s1, const string& s2) {
//     if (s1.size() == s2.size()) return s1 > s2;
//     else {
//         bool f = s1.size() > s2.size() ? true : false;
//         int len = min(s1.size(), s2.size());
//         for (int i = 0; i < s1.size(); ++i) {
//             if (s1[i] == s2[i]);
//             else if (s1[i]>s2[i]) return true;
//             else return false;
//         }
//         return !f;
//     }
// }
bool cmp(string s1, string s2) {
    return s1+s2>s2+s1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s;
    vector<string> v(n);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    for (auto i: v) cout << i;

    return 0;
}