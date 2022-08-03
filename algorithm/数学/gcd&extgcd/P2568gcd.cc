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

typedef long long LL;
const int N=10000005;
bool is_prime[N];
int n,prime_num,prime[N],phi[N];
long long sum[N];
int main(void){
	scanf("%d",&n);
	memset(is_prime,1,sizeof(is_prime));
	is_prime[1]=0;phi[1]=1;
	for (int i=2;i<=n;++i){
		if (is_prime[i]) phi[i]=i-1,prime[++prime_num]=i;
		for (int j=1;j<=prime_num&&prime[j]*i<=n;++j){
			is_prime[prime[j]*i]=0;
			if (__gcd(prime[j],i)==1) phi[prime[j]*i]=phi[prime[j]]*phi[i];
				else phi[prime[j]*i]=prime[j]*phi[i];
			if (i%prime[j]==0) break;
		}
	}
	for (int i=1;i<=n;++i) sum[i]=sum[i-1]+phi[i];
	long long ans=0;
	for (int i=1;i<=prime_num&&prime[i]<=n;++i) 
		ans+=(sum[n/prime[i]]<<1)-1;
	printf("%lld\n",ans);
	return 0;
}