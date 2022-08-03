#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x7fffffff;;
const long long MOD = 1000000007;
#define rep(i, a, b) for(int i=(a), __=(b); i<=__; ++i)
#define per(i, a, b) for(int i=(b), __=(a); i>=__; --i)
inline long long powmod(long long a, long long b) {long long res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
inline long long qpow(long long a, long long b) {long long res=1LL; while(b) {if(b&1) res=res*a;b>>=1;a*=a;} return res;}
inline long long gcd(long long a, long long b) {while (b^=a^=b^=a%=b); return a;}

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

void solve() {
    int n = read<int>();
    vector<int> v(n);
    rep(i, 0, n-1) v[i] = read<int>();
    sort(v.begin(), v.end());
    rep(i, 0, n-2) {
        if (v[i]%2==0&&v[i+1]%2==1&&v[i]-v[i+1]==-1) {cout << "Yes\n"; return;}
    }
    cout << "No\n";
    return;
}

int main(int argc, char** argv)    {
#ifdef _FILE_IO
    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);
#endif
#ifdef _DEBUG
    
#endif
    long long t = read<long long>();
    while (t--) {
        solve();
    }

    return 0;
}