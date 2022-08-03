#include <bits/stdc++.h>
using namespace std;
#define i64 long long

i64 m1[] {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
i64 m2[] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 y, d;
    cin >> y >> d;
    if (y%400==0 || y%4==0&&y%100!=0) {
        i64 m = 1, dd = d;
        for (int i = 1; i < 12; ++i) {
            if (dd-m1[i]>0) m=i+1, dd-=m1[i]; 
            else break;
        }
        cout << m << '\n' << dd << '\n';
    }
    else {
        i64 m = 1, dd = d;
        for (int i = 1; i < 12; ++i) {
            if (dd-m2[i]>0) m=i+1, dd-=m2[i]; 
            else break;
        }
        cout << m << '\n' << dd << '\n';
    }
    return 0;
}