#include <bits/stdc++.h>
#define LL long long
#define _rep(i, a, b) for(int i = (a), __ = (b); i < __; ++i)
using namespace std;

// #define _STD_CPP
// #define _STD_CPP_TIE
// #define _STD_C
// #define _GETCHAR
#define _FREAD_BUF

#ifdef _FREAD_BUF
#define MAXSIZE 1<<16
char buf[MAXSIZE], *p1 = buf, *p2 = buf;
// inline char gc()    {
//     if (p1 == p2)    {
//         p2 = (p1 = buf) + fread(buf, sizeof(char), MAXSIZE, stdin);
//     }
//     return *(p1++);
// }
#define gc()                                                                                 \
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, sizeof(char), MAXSIZE, stdin), p1 == p2)  \
        ? EOF                                                                                \
        : *(p1++))
#endif

#if  defined(_GETCHAR) || defined(_FREAD_BUF)
inline LL read()    {
    LL x = 0, w = 1;
    char ch = gc();
    while (!isdigit(ch))    {
        if (ch == '-')    w *= -1;
        ch = gc();
    }
    while (isdigit(ch))    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = gc();
    }
    return x * w;
}
#endif

int main(void)    {
    LL res = 0, n, t;
    #ifdef _STD_CPP
    // 过一个点
    cin >> n;
    while (n--)    {
        cin >> t;
        res ^= t;
    }
    #endif

    #ifdef _STD_CPP_TIE
    // 过三个点
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--)    {
        cin >> t;
        res ^= t;
    }
    #endif

    #ifdef _STD_C
    // 过三个点
    scanf("%lld", &n);
    while (n--)    {
        scanf("%lld", &t);
        res ^= t;
    }
    #endif

    #if defined(_GETCHAR) || defined(_FREAD_BUF)
    // 不开O2优化过四个点，开O2优化AC
    n = read();
    while (n--)    {
        t = read();
        res ^= t;
    }
    #endif

    printf("%lld\n", res);
    return 0;
}
