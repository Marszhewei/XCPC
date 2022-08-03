#include <bits/stdc++.h>

#define LL long long
#define forn(i, a, n)  for(int i = a; i < n; ++i)
#define INF int(1<<16)

using namespace std;
// 1号顶点到各顶点的距离
int dis[101];
// 起点，终点，权值数组
int startv[101], endv[101], weight[101];
int m, n;  // m边集， n点集

void bellman_ford()    {
    forn(i, 1, n)
        forn(j, 1, m+1)
            if (dis[endv[j]] > dis[startv[j]] + weight[j])
                dis[endv[j]] = dis[startv[j]] + weight[j];
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    // 初始化
    forn(i, 1, n+1)
        dis[i] = INF;
    dis[1] = 0;

    // 读入边集
    forn(i, 1, m+1)    {
        cin >> startv[i] >> endv[i] >> weight[i];
    }

    bellman_ford();
    forn(i, 1, n+1)    cout << dis[i] << ' ';
    cout << '\n';

    return 0;
}

/* 
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
*/