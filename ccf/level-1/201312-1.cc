#include<bits/stdc++.h>
using namespace std;

map<int, int> hash_table;
int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)    {
        int t; cin >> t;
        if (hash_table.find(t) == hash_table.end())
            hash_table[t] = 1;
        else hash_table[t]++;
    }
    int idx = -1, val = 0;
    for (auto it = hash_table.begin(); it != hash_table.end(); ++it)    {
        if (it->second > val) val = it->second, idx = it->first;
    }
    cout << idx << '\n';
    return 0;
}
