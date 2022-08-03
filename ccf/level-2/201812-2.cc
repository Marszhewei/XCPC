#include <bits/stdc++.h>
using namespace std;
#define i64 long long 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 r, y, g; cin >> r >> y >> g;
    i64 n, cnt = 0, tt; cin >> n;
    while (n--) {
        i64 sg, t; cin >> sg >> t;
        tt = cnt%(r+g+y);
        switch(sg) {
            case 0 : cnt += t; break;
            case 1 : 
                if (tt < t) cnt += (t-tt);
                else if (tt < t+g);
                else cnt += (g+r+y-tt+t);
                break;
            case 2 : 
                if (tt < t+r) cnt += (t+r-tt);
                else if (tt < t+r+g);
                else cnt += (g+r+y-tt+t+r);
                break;
            case 3 : 
                if (tt >= t) cnt += (t+y+r-tt);
                break;
        }
        cout << cnt << '\n';
    }
    cout << cnt << '\n';
    return 0;
}