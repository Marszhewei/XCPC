#include <bits/stdc++.h>

#define LL long long

// 暴力不行（理解错题意了）骗30分
// using namespace std;
// LL L, N, M, P[50000+50];
// priority_queue<LL, vector<LL>, greater<LL> > pq;
// int main(void)    {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> L >> N >> M;
//     cin >> P[0];
//     int i = 1;
//     for ( ; i < N; ++i)    {
//         cin >> P[i];
//         pq.push(P[i] - P[i-1]);
//     }
//     pq.push(L - P[i-1]);
//     for (int j = 0; j < M; ++j)    pq.pop();
//     cout << pq.top() << "\n";
//     // while (!pq.empty())    {
//     //     cout << pq.top() << " ";
//     //     pq.pop();
//     // }
//     // cout << "\n";

//     return 0;
// }


using namespace std;

LL L, N, M;
vector<LL> V;

bool check(LL x)    {
    LL cnt = 0, now = 0, next = 0;
    while (next < N+1)    {
        ++next;
        if (V[next] - V[now] < x)    ++cnt;
        else    now = next;
        if (cnt > M)    return false;
    }
    return true;
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> N >> M;
    V.push_back(0);
    LL temp;
    for (int i = 1; i <= N; ++i)    {
        cin >> temp; V.push_back(temp);
    }
    V.push_back(L);

    // 二分
    LL left = 0, right = L, mid, ans;
    while (left <= right)    {
        mid = (left + right) / 2;
        if (check(mid))    {left = mid + 1; ans = mid;}
        else    right = mid - 1;
    }
    cout << right << endl;

    return 0;
}