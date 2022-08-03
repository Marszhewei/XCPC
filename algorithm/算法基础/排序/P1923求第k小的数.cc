#include <bits/stdc++.h>
using namespace std;
#define i64 long long

void find_nth(vector<int>& v, int l, int r, int k) {
    if (l > r) return;
    // cout << v[k] << '\n';
    int mid = v[l], left = l, right = r;
    do{
        while(v[left] < mid) left++;
        while(v[right] > mid) right--;
        if(left <= right) {
            swap(v[left], v[right]);
            left++;
            right--;
        }
    }while(left <= right);
    if (right >= k) find_nth(v, l, right, k);
    else if (left <= k) find_nth(v, left, r, k);
    else {
        cout << v[k] << '\n';
        return;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    find_nth(v, 0, n-1, k);
    // nth_element(v.begin(), v.begin()+k, v.end());
    return 0;
}