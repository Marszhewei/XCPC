#include <bits/stdc++.h>
using namespace std;
#define i64 long long

bool flag[35][35];
i64 a[35][35];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(a, 0, sizeof(a));
    memset(flag, false, sizeof(flag));
    i64 m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) 
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    // row
    for (int i = 0; i < m; ++i) {
        i64 sidx = 0, eidx = 0;
        for (int j = 1; j < n; ++j) {
            if (eidx-sidx<2) {
                if (a[i][j] == a[i][j-1]) {eidx = j;}
                else {sidx = eidx = j;}
                if (j == n-1 && eidx-sidx>=2) {
                    for (int k = sidx; k <= eidx; ++k) flag[i][k] = true;
                    sidx = eidx = j;
                } 
            }
            else {
                if (a[i][j] == a[i][j-1]) {eidx = j;}
                if (a[i][j] != a[i][j-1] || j == n-1) {
                    for (int k = sidx; k <= eidx; ++k) flag[i][k] = true;
                    sidx = eidx = j;
                }
            }
        }
    }
    // clo
    for (int j = 0; j < n; ++j) {
        i64 sidx = 0, eidx = 0;
        for (int i = 1; i < m; ++i) {
            if (eidx-sidx<2) {
                if (a[i][j] == a[i-1][j]) {eidx = i;}
                else {sidx = eidx = i;}
                if (i == m-1 && eidx-sidx>=2) {
                    for (int k = sidx; k <= eidx; ++k) flag[k][j] = true;
                    sidx = eidx = i;
                } 
            }
            else {
                if (a[i][j] == a[i-1][j]) {eidx = i;}
                if (a[i][j] != a[i-1][j] || i == m-1) {
                    for (int k = sidx; k <= eidx; ++k) flag[k][j] = true;
                    sidx = eidx = i;
                }
            }
        }
    }
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (flag[i][j]) cout << "0 ";
            else cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}