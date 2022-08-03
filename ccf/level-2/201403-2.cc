#include <bits/stdc++.h>
using namespace std;
#define i64 long long

typedef struct {
    i64 x1, y1, x2, y2;
    i64 num;
}P;
P pp[15];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {cin >> pp[i].x1 >> pp[i].y1 >> pp[i].x2 >> pp[i].y2; pp[i].num = i;}
    for (int i = 0; i < M; ++i) {
        i64 x, y;
        cin >> x >> y;
        bool check = true;
        for (int j = N; j > 0; --j) {
            if (x <= pp[j].x2 && x >= pp[j].x1 && y >= pp[j].y1 && y <= pp[j].y2) {
                cout << pp[j].num << '\n'; check = false;
                swap(pp[j], pp[N]);
                break;
            }
        }
        if (check) cout << "IGNORED\n";
    }
    return 0;
}