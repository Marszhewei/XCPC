#include <bits/stdc++.h>
using namespace std;
#define i64 long long

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool status = false;
    i64 t, score = 0, k = 1; cin >> t;
    while (t) {
        if (t == 1) {score++;status = false; k = 1;}
        else if (t == 2 && !status) {score+=2; status = true;}
        else if (t == 2 && status) {score+=((++k)*2); status = true;}
        cin >> t;
    }
    cout << score << '\n';
    return 0;
}