#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000010;
int nextarr[MAXN], extend[MAXN];
inline void getnext(string s) {
    nextarr[0] = s.length();
    int j = 0, k = 1;
    while (j+1 < s.length() && s[j] == s[j+1]) j++;
    nextarr[1] = j;
    for (int i = 2; i < s.length(); ++i) {
        int p = nextarr[k]+k-1;
        int len = nextarr[i-k];
        if (i+len < p+1) nextarr[i] = len;
        else {
            j = max(0, p-i+1);
            while (i+j < s.length() && s[i+1] == s[j]) ++j;
            nextarr[i] = j;
            k = i;
        }
    }
}
void ekmp(string s1, string s2) {
    getnext(s2);
    int j = 0, k = 0;
    while (j < s1.length() && j < s2.length() && s2[j] == s1[j]) ++j;
    extend[0] = j;
    for (int i = 1; i < s1.length(); ++i) {
        int p = extend[k]+k-1;
        int len = nextarr[i-k];
        if (i+len < p+1) extend[i] = len;
        else {
            j = max(0, p-i+1);
            while (i+j < s1.length() && j < s2.length() && s1[i+j] == s2[j]) j++;
            extend[i] = j;
            k = i;
        }
    }
}

int main(void) {
    string s1, s2; cin >> s1 >> s2;
    ekmp(s1, s2);
    int ans1 = 0, ans2 = 0;
    // cout << accumulate(nextarr, nextarr+s2.length(), 0) << '\n' << accumulate(extend, extend+s1.length(), 0) << '\n';
    for (int i = 0; i < s1.length(); ++i) ans2 ^= (i+1)*(extend[i]+1);
    for (int i = 0; i < s2.length(); ++i) ans1 ^= (i+1)*(nextarr[i]+1);
    cout << ans1 << '\n' << ans2 << '\n';
    return 0;
}