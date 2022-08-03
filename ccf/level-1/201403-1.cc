#include <bits/stdc++.h>
using namespace std;

map<int ,int> hasht;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cnt = 0;
    cin >> n;
    while (n--) {
        int t; cin >> t;
        if (hasht.find(t) == hasht.end()) hasht[t] = t;
        if (hasht.find(-t) != hasht.end())cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
