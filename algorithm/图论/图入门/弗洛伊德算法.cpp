#include <bits/stdc++.h>
/* 最短路径 */
/* 适用情况，稠密图，有负权边 */
// 代码实现简单，空间复杂度：O(N2), 时间复杂度：O(N3)

#define LL long long
#define forn(i, a, n) for(int i = a; i < n; ++i)
#define INF int(1<<16)

using namespace std;
int m, n, t1, t2, val; // m边， n顶点
// 地图
int mmap[101][101];

void floyd()    {
    forn(k, 1, n+1)    
        forn(i, 1, n+1)
            forn(j, 1, n+1)
                if (mmap[i][j] > mmap[i][k] + mmap[k][j])   {
                    mmap[i][j] = mmap[i][k] + mmap[k][j];
                }

    cout << '\n';
    forn(i, 1, n+1)    {
        forn(j, 1, n+1)
            cout << mmap[i][j] << ' ';
        cout << '\n';
    }
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

    floyd();

    return 0;
}

/*
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/