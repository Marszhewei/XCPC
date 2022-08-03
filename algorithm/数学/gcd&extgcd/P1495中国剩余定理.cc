#include <bits/stdc++.h>
using namespace std;

inline long long extend_gcd(long long a, long long b, long long &x, long long &y) {
    if (a==0&&b==0) return -1;
    if (b==0) {x=1; y=0; return a;}
    long long d = extend_gcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

// (mi, mj) ?= 1 （不一定互质）
long long mod(long long a, long long m) {    //处理取模
    long long res = a%m;
    if(res <= 0) res += m;
    return res;
}
long long CRT(long long a[], long long m[], long long k) {
    long long ans = a[0];
    long long lcm = m[0], x, y, d;
    if(ans == 0) ans = m[0];
    for(long long i = 1; i < k; ++i) {
        d = extend_gcd(lcm, m[i], x, y);    //求t: t = (a[i]-ans)/d*x;
        if((a[i]-ans)%d) return 0;
        ans = mod(ans + lcm*mod((a[i]-ans)/d*x, m[i]/d),(lcm/d*m[i]));
        lcm = lcm/d*m[i];
    }
    return ans;
}

long long aa[15], bb[15];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> aa[i] >> bb[i];
    }
    cout << CRT(bb, aa, n) << '\n';
    return 0;
}
