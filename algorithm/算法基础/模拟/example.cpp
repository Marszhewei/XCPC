/*
一只长度不计的蠕虫位于n英寸深的井的底部。它每次向上爬u英寸，但是必须休息一次才能再次向上爬。在休息的时候，它滑落了d英寸。之后它将重复向上爬和休息的过程。蠕虫爬出井口需要至少爬多少次？如果蠕虫爬完后刚好到达井的顶部，我们也设作蠕虫已经爬出井口。
*/

#include <bits/stdc++.h>
using namespace std;
int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, u, d, dist = 0, cnt = 0;
    cin >> n >> u >> d;
    while (true)    {
        dist += u;
        cnt++;
        if (dist >= n)    break;
        dist -= d;
    }
    cout << cnt << '\n';
    return 0;
}