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

#define ppf pop_front
#define ppb pop_back
#define puf push_front
#define pub push_back
#define mv erase
#define eqr equal_range
#define ub upper_bound
#define lb lower_bound
#define np next_permutation

#define LL long long
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define rep(i, a, b) for(int i = (a), __ = (b); i < __; ++i)
bool cmp(LL& a, LL& b) {return a > b;}

namespace IO    {
    inline LL read()    {
        LL x = 0, w = 1;
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
    inline void write(LL x, char endchar)    {
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
        putchar(endchar);
    }
};

LL n, m;
deque<int> ctr;
void Input()    {
    n = IO::read(), m = IO::read();
    LL val, op;
    while (m--)    {
        op = IO::read();
        switch(op)    {
            case 1 : val = IO::read(); ctr.puf(val); 
                break;
            case 2 : ctr.ppf();
                break;
            case 3 : val = IO::read(); ctr.pub(val);
                break;
            case 4 : ctr.ppb();
                break;
            case 5 : reverse(ctr.begin(), ctr.end());
                break;
            case 6 : IO::write(ctr.size(), '\n');
                for (auto i: ctr) IO::write(i, ' '); putchar('\n');
                break;
            case 7 : sort(ctr.begin(), ctr.end());
                break;
        }
    }
    
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

    Input();

    return 0;
}