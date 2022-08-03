#include <iostream>
#include <string>

using namespace std;
const int MAXN = 1000010;
int nextarr[MAXN];
inline void getnext(string s) {
    nextarr[0] = -1;
    for (int i = 0, j = -1; i < s.length(); ) {
        while (-1!=j && s[i]!=s[j]) j = nextarr[j];
        nextarr[++i] = ++j;
    }
}

inline void kmpnext(string s) { // 优化
    nextarr[0] = -1;
    for (int i = 0, j = -1; i < s.length(); ) {
        while (-1!=j && s[i]!=s[j]) j = nextarr[j];
        if (s[++i] == s[++j]) nextarr[i] = nextarr[j];
        else nextarr[i] = j;
    }
}

int kmp(string s1, string s2) {
    int ans = 0; // 模式串在主串中出现的次数
    // getnext(s2);
    kmpnext(s2);
    for (int i = 0, j = 0; i < s1.length(); ) {
        while (-1!=j && s1[i]!=s2[j]) j = nextarr[j];
        i++, j++;
        if (j == s2.length()) {cout << i-s2.length()+1 << '\n'; ans++; j = nextarr[j];}
    }
    return ans;
}

int main(void) {
    string s1, s2; cin >> s1 >> s2;
    // cout << kmp(s1, s2) << '\n';
    kmp(s1, s2);
    for (int i = 1; i <= s2.length(); ++i) cout << nextarr[i] << ' '; cout << '\n';
    return 0;
}

