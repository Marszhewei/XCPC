#include <bits/stdc++.h>

#define LL long long
#define forn(i, a, n) for(int i = a; i < n; ++i)
#define INF int(1<<32-1)

using namespace std;
int m, n, t1, t2, cnt = 0; // m边， n顶点
// 地图
int mmap[101][101];
// 遍历标记
bool flag[101] {false};

void bfs(int step)    {
    queue<int> q;
    q.push(step);

    while (!q.empty())    {
        cnt++;
        if (cnt > n)    return;
        int cur = q.front();
        cout << cur << ' ';
        q.pop();
        forn(i, 1, n+1)    {
            if (mmap[cur][i] == 1 && !flag[i])    {
                q.push(i);
                flag[i] = true;
            }
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
    bfs(1);

    return 0;
}