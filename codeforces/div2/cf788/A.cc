#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define mod 1000000007
#define i64 long long
#define rep(i, a, b) for(int i=(a), __=(b); i<__; ++i)
#define per(i, a, b) for(int i=(b-1), __=(a); i>=__; --i)
i64 powmod(i64 a, i64 b) {i64 res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a;}

namespace IO    {
    template<typename T> inline T read()    {
        T x = 0, w = 1; char ch = getchar();
        while (!isdigit(ch)) {if (ch == '-')w *= -1; ch = getchar();}
        while (isdigit(ch)) { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
        return x * w;
    }
    template<typename T> inline void write(T x, char end_ch)    {
        if (x < 0) {x = -x; putchar('-');}
        static int sta[101]; int top = 0;
        do {sta[top++] = x % 10; x /= 10;} while (x);
        while (top) putchar(sta[--top] + 48);
        putchar(end_ch);
    }
}using namespace IO;

const i64 N=501000;
i64 a[N]; 
void solve() {
    i64 n = read<i64>(), cnt_ng = 0;
    rep(i, 0, n) {a[i]=read<i64>(); if(a[i]<0) a[i]=-a[i], cnt_ng++;}
    rep(i, 0, cnt_ng) a[i]=-a[i];
    rep(i, 1, n) if (a[i]<a[i-1]) {puts("NO\n"); return;}
    puts("YES\n");
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; t = read<int>();
    while (t--) {
        solve();
    }
    return 0;
}