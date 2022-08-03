#include <bits/stdc++.h>
/* 图的遍历 */

#define LL long long
#define forn(i, a, n) for(int i = a; i < n; ++i)
#define INF 32767

using namespace std;
int m, n, t1, t2, cnt = 0; // m边， n顶点
// 地图
int mmap[101][101];
// 遍历标记
bool flag[101] {false};

void dfs(int step)    {
    cout << step << ' ';
    cnt++;
    if (cnt == n)    return;
    forn(i, 1, n+1)    {
        if (mmap[step][i] == 1 && !flag[i])    {
            flag[i] = true;
            dfs(i);
        }
    }
    return;
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    // 地图初始化
    forn(i, 1, n+1)
        forn(j, 1, n+1)
            if ( i == j)    mmap[i][j] = 0;
            else    mmap[i][j] = INF;

    forn(i, 0, m)    {
        cin >> t1 >> t2;
        mmap[t1][t2] = 1;
        mmap[t2][t1] = 1;
    }
    flag[1] = true;
    dfs(1); 

    return 0;
}