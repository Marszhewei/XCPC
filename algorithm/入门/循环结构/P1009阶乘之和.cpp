#include <bits/stdc++.h>

using namespace std;

int a[500], b[500] = {1, 1}, c[500];
int n, la = 0, lb = 1, lc = 0;

void add(int aa[], int bb[])    {
    int dd[500];
    memset(dd, 0, sizeof(dd));
    int ld = max(la, lb);
    for (int i = 1; i <= ld; ++i)    {
        dd[i] += aa[i] + bb[i];
        dd[i + 1] = dd[i] / 10;
        dd[i] = dd[i] % 10;
    }
    ld++;
    if (dd[ld] == 0 && ld > 0) ld--;
    la = ld;
    memcpy(aa, dd, sizeof(dd));
}

void multiply(int bb[], int cc[])    {
    int dd[500];
    memset(dd, 0, sizeof(dd));
    int ld = lb + lc;
    for (int i = 1; i <= lb; ++i)    {
        for (int j = 1; j <= lc; ++j)    {
            dd[i + j - 1] += bb[i] * cc[j];
            dd[i + j] += dd[i + j - 1] / 10;
            dd[i + j - 1] = dd[i + j - 1] % 10;
        }
    }
    while (dd[ld] == 0 && ld > 0)    ld--;
    memcpy(bb, dd, sizeof(dd));
    lb = ld;
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(a, 0, sizeof(a));
    cin >> n;
    for (int i = 1; i <= n; ++i)    {
        // 把i放到数组中区
        int t = i;
        memset(c, 0, sizeof(c));
        lc = 0;
        while (t > 0){ 
            c[++lc] = t % 10;
            t /= 10;
        }
        multiply(b, c);
        add(a, b);
    }

    while (a[la] == 0 && la > 0)    la--;
    for (int i = la; i > 0; --i)    cout << a[i];
    cout << '\n';


    return 0;
}