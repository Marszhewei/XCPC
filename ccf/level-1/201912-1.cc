#include <bits/stdc++.h>
using namespace std;
#define i64 long long 

bool have(i64 t) {
    stringstream ss;
    ss << t;
    string s;
    ss >> s;
    if (s.find('7') != -1) return true;
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, cnt = 0, a=0, b=0, c=0, d=0;
    cin >> n;
    for (int i = 1; cnt != n; ++i) {
        if (i%4==1 && (i%7==0 || have(i))) a++;
        else if (i%4==2 && (i%7==0 || have(i))) b++;
        else if (i%4==3 && (i%7==0 || have(i))) c++;
        else if (i%4==0 && (i%7==0 || have(i))) d++;
        else cnt++;
    }
    cout << a << '\n' << b << '\n' << c << '\n' << d << '\n';
    return 0;
}