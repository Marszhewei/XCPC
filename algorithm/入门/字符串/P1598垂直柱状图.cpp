#include <bits/stdc++.h>

int base[401][26];

using namespace std;
int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, s1;
    int t = 4, maxn = -1;
    while (t--)    {
        getline(cin ,s1);
        s += s1;
    }
    
    string ss = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; ++i)    {
        base[0][i] = count(s.begin(), s.end(), ss[i]);
        maxn = max(base[0][i], maxn);
    }

    for (int j = 0; j < 26; ++j)    {
        for (int i = 1; i <= base[0][j]; ++i)    {
            base[i][j] = 1;
        }
    }

    for (int i = maxn; i > 0; --i)    {
        for (int j = 0; j < 26; ++j)    {
            if (base[i][j] == 1 && j < 25)    cout << "* ";
            else if (base[i][j] == 1 && j == 25)    cout << "*\n";
            else if (base[i][j] == 0 && j < 25)    cout << "  ";
            else    cout << " \n";
        }
    }
    for (int i = 0; i < ss.size(); ++i)    cout << ss[i] << " ";
    cout << '\n';

    return 0;
}