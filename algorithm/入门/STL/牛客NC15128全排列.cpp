#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

#define pb push_back
#define mv erase
#define eqr equal_range
#define ub upper_bound
#define lb lower_bound
#define np next_permutation

#define LL long long
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define rep(i, a, b) for(int i = (a), __ = (b); i < __; ++i)

namespace IO    {
    template<typename T> inline T read()    {
        T x = 0, w = 1;
        char ch = getchar();
        while (!isdigit(ch))    {
            if (ch == '-')    w *= -1;
            ch = getchar();
        }
        while (isdigit(ch))    {
            x = (x << 1) + (x << 3) + (ch ^ 48);
            ch = getchar();
        }
        return x * w;
    }
    template<typename T> inline void write(T x, char end_ch)    {
        if (x < 0)    { 
            x = -x;
            putchar('-'); 
        }
        static int sta[101];
        int top = 0;
        do {
            sta[top++] = x % 10;
            x /= 10;
        } while (x);
        while (top)    putchar(sta[--top] + 48);
        putchar(end_ch);
    }
};

void input()    {
    return;
}

int n = 8, base[10];
bool book[10];
void dfs(int step)    {
    if (step == n + 1)    {
        rep(i, 1, n+1)     {
            if (i == n) IO::write<int>(base[i], '\n');
            else IO::write<int>(base[i], ' ');
        }
        return;
    }
    rep(i, 1, n+1)    {
        if (!book[i])    {
            base[step] = i;
            book[i] = true;
            dfs(step+1);
            book[i] = false;
        }
    }
    return;
}

void solve()    {
    // vector<int> range {1, 2, 3, 4, 5, 6, 7, 8};	
    // do {
    //     forn(i, 8)    {
    //         if (i == 7) IO::write<int>(range[i], '\n');
    //         else IO::write<int>(range[i], ' ');
    //     }
    // }while(np(begin(range), end(range)));

    memset(book, false, sizeof(book));
    dfs(1);
}

// #define _DEBUG
// #define _FILE_IO

int main(int argc, char** argv)    {
#ifdef _FILE_IO
    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);
#endif
#ifdef _DEBUG
    
#endif
    input();
    solve();

    return 0;
}