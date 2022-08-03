#include <bits/stdc++.h>
using namespace std;

int m[1001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(m, 0, sizeof(m));
    int n; cin >> n;
    while (n--) {
        int t; cin >> t;
        m[t]++;
        cout << m[t] << ' ';
    }
    cout << '\n';return 0;
}