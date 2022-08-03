#include <bits/stdc++.h>

#define LL long long
#define forn(i, a, n) for(int i = a; i < n; ++i)
#define INF int(1<<16)

using namespace std;
int m, n, t1, t2, val, cnt = 0, mindis = INF; // m边， n顶点
// 地图
int mmap[101][101];
// 遍历标记
bool flag[101] {false};

void dfs(int step, int mm)    {
    if (mm > mindis)    return;
    if (step == n)    {
        if (mm < mindis)    mindis = mm;
        return;
    }
    forn(i, 1, n+1)    {
        if (mmap[step][i] != 1 && !flag[i])    {
            flag[i] = true;
            dfs(i, mm+mmap[step][i]);
            flag[i] = false;
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

    // 读入边集
    forn(i, 0, m)    {
        cin >> t1 >> t2 >> val;
        mmap[t1][t2] = val;
    }
    flag[1] = true;
    dfs(1, 0); 
    cout << "min distance: " << mindis << '\n';

    return 0;
}

/*
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
*/