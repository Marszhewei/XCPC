#include <bits/stdc++.h>

using namespace std;
string s = "abcdefghijklmnopqrstuvwxyz";

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ss;
    int n;
    cin >> n >> ss;
    for (int i = 0; i < ss.size(); ++i)    {
        auto it = find(s.begin(), s.end(), ss[i]) - s.begin();
        cout << s[(it + n) % 26];
    }
    cout << '\n';
    return 0;
}