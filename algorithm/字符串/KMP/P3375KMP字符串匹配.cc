#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
int nextarr[MAXN];
string s1, s2;
inline void get_next() { // 在线操作
    int t1 = 0, t2;
    nextarr[0] = t2 = -1;
    while(t1 < s2.length()) {
        if(t2 == -1 || s2[t1] == s2[t2]) nextarr[++t1] = ++t2;
        else t2 = nextarr[t2];
    }
} 
inline void KMP() { 
    int t1 = 0, t2 = 0;
    while(t1 < s1.length()) { 
        if(t2==-1 || s1[t1]==s2[t2]) t1++, t2++;
        else t2 = nextarr[t2];
        if(t2 == s2.length()) cout << t1-s2.length()+1 << '\n', t2=nextarr[t2];
    }
} 
int main(void) {
    cin >> s1 >> s2;
    get_next();
    KMP();
    // for(int i = 1; i <= s2.length(); ++i) cout << nextarr[i] << ' ';
    // cout << '\n';
    return 0;
}