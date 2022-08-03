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

int main(int argc, char** argv)    {
#ifdef _FILE_IO
    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);
#endif
#ifdef _DEBUG
    
#endif
    long long n = read<long long>();
    long long odd = 0LL, even = 0LL;
    rep(i, 1, n) {
        long long t = read<long long>();
        if (t%2) odd++;
        else even++;
    }
    if (abs(odd-even) > 1) cout << "Not Good\n";
    else cout << "Good\n";

    return 0;
}