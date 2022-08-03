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
    string s; cin >> s;
    int part1 = 0, part2 = 0, lens = s.length(), i = 0;
    if (lens == 1) {cout << "1\n"; return;}
    // 特判开头和结尾
    if (s[0]=='0'&&s[1]=='0' || s[lens-1]=='0'&&s[lens-2]=='0') {cout << "-1\n"; return;}
    for ( ; i < lens-1; ++i) {
        if (s[i]=='1' && s[i+1]=='1') part1++;
        else if (s[i]=='1' && s[i+1]=='0' || s[i]=='0' && s[i+1]=='1') {part2++;i++;}
        else if (s[i]=='0' && s[i+1]=='0') {cout << "-1\n"; return;}
    }
    if (s[lens-1]=='1' && i==lens-1) part1++;
    if (s[lens-1]=='0' && i==lens-1) {cout << "-1\n"; return;}
    cout << max(part1, part2) << '\n';
    return;
}

int main(int argc, char** argv)    {
#ifdef _FILE_IO
    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);
#endif
#ifdef _DEBUG
    
#endif
    solve();

    return 0;
}