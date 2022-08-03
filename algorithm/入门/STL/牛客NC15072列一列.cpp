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

map<LL, LL> hash_table;
pair<LL, LL> p1 {1, 1}, p2 {2, 2};
LL temp;
const LL k = 100000;
void pre_solve()    {
    hash_table[1] = 1, hash_table[2] = 2;
    rep(i, 3, k+1)    {
        temp = p1.first+p2.first;
        hash_table[temp] = i;
        swap(p1, p2);
        p2 = {temp, i};
    }
}

void input()    {
    string op;
    LL ans;
    while(cin >> op){
        ans = 0;
        for(int i =0; i < op.size(); i++){
            int t =(op[i] ^ 48);
            ans=ans*10+t;
        }
        cout<<hash_table[ans]<<endl;
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
    pre_solve();
    input();

    return 0;
}