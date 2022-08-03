#include <bits/stdc++.h>
using namespace std;
#define i64 int
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

i64 n, len = 1;
// vector<i64> a(5005), b(5005), c(5005);
vector<vector<i64>> dp(5005, vector<i64>(5005));
void add(int k) {
	rep(i, 1, len+1)
	    dp[k][i]=dp[k-1][i]+dp[k-2][i];
	rep(i, 1, len+1)
		if(dp[k][i]>=10) {
			dp[k][i+1]+=dp[k][i]/10;
			dp[k][i]%=10;
			if(dp[k][len+1]>0)len++;
		}
}

void solve() {
    dp[1][1] = 1, dp[2][1] = 2;
    rep(i, 3, n+1) add(i);
    per(i, 1, len+1) {printf("%lld",dp[n][i]);}
}

int main(int argc, char** argv)    {
#ifdef _FILE_IO
    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);
#endif
#ifdef _DEBUG
    
#endif
    n = read<i64>();
    solve();

    return 0;
}
