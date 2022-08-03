#include <bits/stdc++.h>
using namespace std;
#define i64 long long

bool leftv[100005];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(leftv, false, sizeof(leftv));
    i64 n, k, lv, rv, cnt = 0;
    cin >> n >> k;
    while (k--) {
        cin >> lv >> rv;
        if (rv == 0) {leftv[lv] = true; continue;}
        if (!leftv[rv]) cnt++;
        leftv[lv] = true;
    }
    cout << cnt << '\n';
    return 0;
}