#include <bits/stdc++.h>
#define LL long long
#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int MAXSIZE = 1 << 20;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)

LL n, v[101];

// 快读
inline LL read()    {
    LL x = 0, w = 1;
    char ch = gc();
    while (!isdigit(ch))    { // 读入正负号
        if (ch == '-')    w = -1;
        ch = gc();
    }
    while (isdigit(ch))    { // 读入数字
        x = x * 10 + (ch ^ 48);                    
        ch = gc();
    }
    return x * w;
} 

char pbuf[1 << 20], *pp = pbuf;

inline void pc(const char &c) {
  if (pp - pbuf == 1 << 20) fwrite(pbuf, 1, 1 << 20, stdout), pp = pbuf;
  *pp++ = c;
}

// 快写
inline void write(LL x)    {
    if (x < 0)    { // 输出符号位
        x = -x;
        pc('-'); 
    }
    static int sta[101];
    int top = 0;
    do {
        sta[top++] = x % 10;
        x /= 10;
    } while (x);
    while (top)    pc(sta[--top] + 48);
}

using namespace std;
int main(void)    {
    LL t = n = read();
    
    f(i, 0, n)    {
        v[i] = read();
    }

    while (t--)    {
        write(v[t]);
        pc(' ');
    }
    pp = pbuf + (1 << 20);
    pc('\n');
    return 0;
}