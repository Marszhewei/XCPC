#include <bits/stdc++.h>
using namespace std;
#define i64 long long 
#define INF 32767
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    i64 n;
    vector<int> a;
    cin >> n;
    while (n--) {
        int t; cin >> t;
        a.push_back(t);
    }    
    sort(a.begin(), a.end());
    int sub = INF;
    for (int i = 1; i < a.size(); ++i) if (sub > (a[i]-a[i-1])) sub = a[i]-a[i-1];
    cout << sub << '\n';
    return 0;
}