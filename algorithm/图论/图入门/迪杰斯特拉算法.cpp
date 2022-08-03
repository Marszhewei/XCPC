#include <bits/stdc++.h>
/* 单源最短路径 */
/* 适用情况，稠密图，不存在负权边 */
// 空间复杂度：O(M), 时间复杂度：O((M+N)logN)

#define LL long long
#define forn(i, a, n) for(int i = a; i < n; ++i)
#define INF int(1<<16)

using namespace std;
int m, n, t1, t2, val; // m边集，n点集
// 地图
int mmap[101][101];
// 一号顶点到其它各顶点的距离
int dis[101];
// 标志数组
bool mark[101] {false};

void dijkstra()    {
    // 初始化dis数组
    forn(i, 1, n+1)     dis[i] = mmap[1][i];
    // 初始化mark数组
    mark[1] = true;
    
    forn(k, 1, n)    {
        // 找到距离1号点最近的一个点
        int mindis = INF, u;
        forn(i, 1, n+1)    {
            if (!mark[i] && dis[i] < mindis)    {
                mindis = dis[i];
                u = i;
            }
        }
        mark[u] = true;

        forn(j, 1, n+1)    {
            if (mmap[u][j] < INF)    {
                if (dis[j] > dis[u] + mmap[u][j])    
                    dis[j] = dis[u] + mmap[u][j];
            }
        } 
    }
}


int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    // 初始化
    forn(i, 1, n+1)
        forn(j, 1, n+1)
            if (i == j)    mmap[i][j] = 0;
            else    mmap[i][j] = INF;

    forn(i, 1, m+1)    {
        cin >> t1 >> t2 >> val;
        mmap[t1][t2] = val;
    }

    dijkstra();

    // 输出
    forn(i, 1, n+1)    cout << dis[i] << ' ';
    cout << '\n';

    return 0;
}

/*
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/