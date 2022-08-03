#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const i64 INF = 0x7fffffff;;
const i64 MOD = 1000000007;
#define rep(i, a, b) for(int i=(a), __=(b); i<__; ++i)
#define per(i, a, b) for(int i=(b-1), __=(a); i>=__; --i)
i64 powmod(i64 a, i64 b) {i64 res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
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
// #define _DEBUG
// #define _FILE_IO

inline int mx(int x, int y, int z) {
    return x>y ? (x>z?x:z) : (y>z?y:z);
}
inline int mn(int x, int y, int z) {
    return x<y ? (x<z?x:z) : (y<z?y:z);
}
void solve() {
    int n = read<int>();
    map<int, int> hashtab;
    hashtab.clear();
    rep(i, 0, n) {
        int t = read<int>();
        hashtab[t]++;
    }
    auto lit = hashtab.begin(), rit = hashtab.end();
    rit--;
    int A = 0, B = 0, C = 0, ans = INF;
    bool f1 = false, f2 = false;
    while (lit != rit) {
        if (!f1) {A += lit->second;lit++;f1=true;}
        else if (!f2) {C += rit->second;rit--; lit--;f2=true;}
        if (f1&&f2) {lit++;f1=f2=false;}
        B = n - A - C;
        if (ans > (mx(A, B, C)-mn(A, B, C))) ans = mx(A, B, C)-mn(A, B, C);
        if (ans == 0) break;
        // cout << A << ' ' << B << ' ' << C << '\n';
        // cout << mx(A, B, C) << ' ' << mn(A, B, C) << '\n';
    }
    write<int>(ans, '\n');
}

int main(int argc, char** argv)    {
#ifdef _FILE_IO
    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);
#endif
#ifdef _DEBUG
    
#endif
    int t = read<int>();
    while (t--) {
        solve();
    }

    return 0;
}