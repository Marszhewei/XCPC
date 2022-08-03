#include <bits/stdc++.h>
using namespace std;
#define i64 long long

int m, arr[105];
void dfs(int n, int i, int a) {
    if (n == 0 && i > m) {for (int j = 1; j <= i - 1; ++j) cout << arr[j] << ' '; cout << '\n';}
    if (i <= m) {
    for (int j = a; j <= n; ++j) {
        arr[i] = j;
        dfs(n - j, i + 1, j);  
    }
  }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n >> m;
    dfs(n, 1, 1);
    return 0;
}