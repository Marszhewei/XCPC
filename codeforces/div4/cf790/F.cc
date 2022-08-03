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

void solve() {
    int n = read<int>(), k = read<int>();
    map<int, int> mp; set<int> st;
    rep(i, 0, n) {int tt=read<int>(); mp[tt]++;}
    for (auto i: mp) if (i.second>=k) st.insert(i.first);
    if (st.empty()) write<int>(-1, '\n');
    else {
        int maxn = 0, left, right, cnt = 0, tp = 0;
        for (auto i: st) {
            cnt = (i==tp+1) ? cnt+1 : 1;
            if (cnt > maxn) {maxn = cnt; left=i-cnt+1; right=i;}
            tp = i;
        }
        write<int>(left, ' '), write<int>(right, '\n');
    }
}

int main(int argc, char** argv)    {
#ifdef _FILE_IO
    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);
#endif
#ifdef _DEBUG
    
#endif
    int t = read<int>();
    while (t--) solve();

    return 0;
}