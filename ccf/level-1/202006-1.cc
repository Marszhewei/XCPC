#include <bits/stdc++.h>
using namespace std;
#define i64 long long

typedef struct { int x, y; char type;}Point; // 点集
Point a[1005];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;
    for (i64 i = 0; i < N; ++i) cin >> a[i].x >> a[i].y >> a[i].type;
    for (i64 i = 0; i < M; ++i) {
        int w1, w2, w3;
        cin >> w1 >> w2 >> w3;
        bool flag = false; // if true: A < 0, B > 0
        if (a[0].type == 'A' && w1+w2*a[0].x+w3*a[0].y < 0 || a[0].type == 'B' && w1+w2*a[0].x+w3*a[0].y > 0) flag = true;
        bool f = true;
        for (i64 j = 0; j < N; ++j) {
            if (flag) {
                if (w1+w2*a[j].x+w3*a[j].y > 0 && a[j].type == 'A' || w1+w2*a[j].x+w3*a[j].y < 0 && a[j].type == 'B') 
                    {cout << "No\n"; f = false; break;}
            }
            else {
                if (w1+w2*a[j].x+w3*a[j].y < 0 && a[j].type == 'A' || w1+w2*a[j].x+w3*a[j].y > 0 && a[j].type == 'B') 
                    {cout << "No\n"; f = false; break;}
            }
        }
        if (f) cout << "Yes\n";
    }
    return 0;
}