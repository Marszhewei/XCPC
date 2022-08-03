#include <bits/stdc++.h>
// 牛逼的解法（找规律）
// #define _NB
using namespace std;
bool base[1100][1100];

// 常规解（分治）
void solve(int left, int right, int up, int down)    {
    if (left == right || up == down)    return;
    for (int i = left; i <= (left + right) / 2; ++i)    {
        for (int j = down; j <= (up + down) / 2; ++j)   {
            base[i][j] = false;
        }
    }
    solve(left + (right-left+1) / 2, right, up - (up-down+1) / 2, down);
    solve(left, right - (right-left+1) / 2, up, down + (up-down+1) / 2);
    solve(left + (right-left+1) / 2, right, up, down + (up-down+1) / 2);
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int t = 1 << n;

    #ifdef _NB
    for (int i = 0; i < t; ++i)    {
        for(int j = 0; j < t; ++j) 
            cout << ((i | j) == (t - 1) ? "1 " : "0 ");
        cout << '\n';
    }
    #endif

    memset(base, true, sizeof(base));
    solve(1, t, t, 1);

    for (int i = 1; i <= t; ++i)    {
        for (int j = 1; j <= t; ++j)    {
            if (base[i][j])    cout << "1 ";
            else    cout << "0 ";
        }
        cout << '\n';
    }

    return 0;
}