#include <bits/stdc++.h>
using namespace std;
#define i64 long long

bool cmp(pair<i64, i64> const &a, pair<i64, i64> const &b) {
    if (a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}
map<i64, i64> hm;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n; cin >> n;
    while (n--) {
        i64 t; cin >> t;
        hm[t]++;
    }

    vector<pair<i64, i64> > v (hm.begin(), hm.end());
    sort(v.begin(), v.end(), cmp);
    for (auto i: v) cout << i.first << ' ' << i.second << '\n';
    return 0;
}