#include <bits/stdc++.h>

using namespace std;
int main(void)   {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    cin >> x;
    cout << ((x % 2 == 0 && x > 4 && x <= 12) ? "1 " : "0 ") 
    << ((x % 2 == 0 || (x > 4 && x <= 12)) ? "1 " : "0 ") 
    << (((x % 2 == 1 && (x > 4 && x <= 12)) || ((x % 2) == 0 && (x <= 4 || x > 12))) ? "1 " : "0 ")
    << ((x % 2 == 1 && !(x > 4 && x <= 12)) ? "1" : "0");
    return 0;
}