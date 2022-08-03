#include <bits/stdc++.h>

using namespace std;
const int MAXN = 20000010;
long long nextarr[MAXN], extend[MAXN];
int s1len, s2len, slen;
inline void getnext(char* s) {
    nextarr[0] = slen;
    int j = 0, k = 1, p, len;
    while (j+1 < slen && s[j] == s[j+1]) j++;
    nextarr[1] = j;
    for (int i = 2; i < slen; ++i) {
        p = nextarr[k]+k-1;
        len = nextarr[i-k];
        if (i+len < p+1) nextarr[i] = len;
        else {
            j = max(0, p-i+1);
            while (i+j < slen && s[i+j] == s[j]) ++j;
            nextarr[i] = j;
            k = i;
        }
    }
}
inline void ekmp(char* s1, char* s2) {
    int j = 0, k = 0, p, len;
    while (j < s1len && j < s2len && s2[j] == s1[j]) ++j;
    extend[0] = j;
    for (int i = 1; i < s1len; ++i) {
        p = extend[k]+k-1;
        len = nextarr[i-k];
        if (i+len < p+1) extend[i] = len;
        else {
            j = max(0, p-i+1);
            while (i+j < s1len && j < s2len && s1[i+j] == s2[j]) j++;
            extend[i] = j;
            k = i;
        }
    }
}

char s1[MAXN], s2[MAXN];
int main(void) {
    scanf("%s", s1); scanf("%s", s2);
    s1len = strlen(s1), s2len = slen = strlen(s2);
    getnext(s2);
    ekmp(s1, s2);
    long long ans1 = 0LL, ans2 = 0LL;
    // cout << accumulate(nextarr, nextarr+s2.length(), 0) << '\n' << accumulate(extend, extend+s1.length(), 0) << '\n';
    for (int i = 0; i < s1len; ++i) ans2 ^= (i+1)*(extend[i]+1);
    for (int i = 0; i < s2len; ++i) ans1 ^= (i+1)*(nextarr[i]+1);
    cout << ans1 << '\n' << ans2 << '\n';
    return 0;
}
