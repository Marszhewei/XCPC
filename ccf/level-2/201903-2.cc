#include <bits/stdc++.h>
using namespace std;
#define i64 long long

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n; cin >> n;
    while (n--) {
        string s; cin >> s;
        stack<i64> nums; stack<char> ops;
        char op = '+'; i64 res = 0;
        for (int i = 0; i < 7; ++i) {
            if (isdigit(s[i])) {if (op == '-') nums.push(-(s[i]^48)); else nums.push(s[i]^48);}
            else if (s[i] == 'x' || s[i] == '/') {
                op = s[i];
            }
            else {
                ops.push('+'), op = s[i];
            }
            if ((op == 'x' || op == '/') && isdigit(s[i])) {
                i64 num1 = nums.top(); nums.pop();
                i64 num2 = nums.top(); nums.pop();
                if (op == 'x') nums.push(num1*num2);
                else nums.push(num2/num1);
            }
        }
        while (!ops.empty()) {
            ops.pop();
            i64 num1 = nums.top(); nums.pop();
            i64 num2 = nums.top(); nums.pop();
            nums.push(num2+num1);
        }
        // cout << nums.top() << '\n';
        if (nums.top() == 24) cout << "Yes\n";
        else cout << "No\n";
        nums.pop();
    }
    return 0;
}

// 10
// 9+3+4x3
// 5+4x5x5
// 7-9-9+8
// 5x6/5x4
// 3+5+7+9
// 1x1+9-9
// 1x9-5/9
// 8/5+6x9
// 6x7-3x6
// 6x4+4/5
