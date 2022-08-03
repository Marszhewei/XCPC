#include <bits/stdc++.h>

using namespace std;
int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    stringstream ss;
    long long n, x;
    cin >> n >> x;
    for ( ; n > 0; ss << (n--));
    s = ss.str();
    cout << count(s.begin(), s.end(), x+'0') << "\n";
    return 0;
}