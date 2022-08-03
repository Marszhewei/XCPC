#include <bits/stdc++.h>
using namespace std;
#define i64 long long

i64 n, X, Y;
struct P{
    i64 x, y, num;
    bool operator< (const P& p1) {
        double dis = (pow((this->x-X), 2) + pow((this->y-Y), 2)) - (pow((p1.x-X), 2) + pow((p1.y-Y), 2));
        if (dis == 0) return this->num < p1.num;
        else if (dis < 0) return true;
        else return false;
    }
};
vector<P> pp;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> X >> Y;
    i64 t = 1;
    while (n--) {P p1; cin >> p1.x >> p1.y; p1.num = t++; pp.push_back(p1);}
    sort(pp.begin(), pp.end());
    for (int i = 0; i < 3; ++i) cout << pp[i].num << '\n';
    return 0;
}