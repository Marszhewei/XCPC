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

long long extend_gcd(long long a, long long b, long long &x, long long &y) {
    if (a==0&&b==0) return -1; // 无最大公约数
    if (b==0) {x=1; y=0; return a;}
    long long d = extend_gcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

int main(int argc, char** argv)    {
#ifdef _FILE_IO
    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);
#endif
#ifdef _DEBUG
    
#endif
    i64 t = read<i64>();
    while (t--) {
        i64 a = read<i64>(), b = read<i64>(), c = read<i64>();
        i64 x, y;
        i64 d = extend_gcd(a, b, x, y);
        if(c%d!=0) puts("-1"); else{
			x*=c/d,y*=c/d; i64 p=b/d,q=a/d,k;
			if(x<0) k=ceil((1.0-x)/p),x+=p*k,y-=q*k; else	//将x提高到最小正整数 
			if(x>=0)k=(x-1)/p ,x-=p*k,y+=q*k;		//将x降低到最小正整数 
			if(y>0){	//有正整数解 
				printf("%lld ",(y-1)/q+1);	//将y减到1的方案数即为解的个数 
				printf("%lld ",x);			//当前的x即为最小正整数x
				printf("%lld ",(y-1)%q+1); 	//将y取到最小正整数 
				printf("%lld ",x+(y-1)/q*p);	//将x提升到最大 
				printf("%lld ",y);			//特解即为y最大值 
			} else{		//无整数解 
				printf("%lld " ,x);			//当前的x即为最小的正整数x 
				printf("%lld",y+q*(i64)ceil((1.0-y)/q)); //将y提高到正整数 
			}
			puts("");
		}
    }

    return 0;
}