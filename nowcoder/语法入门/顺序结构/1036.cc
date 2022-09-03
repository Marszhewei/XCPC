#include <iostream>
#include <vector>
#include <algorithm>

void solve()
{
    std::vector<int> v;
    for (int i = 0; i < 4; ++i) {
        int t;
        std::cin >> t;
        v.push_back(t);
    }
    std::sort(v.begin(), v.end());
    std::cout << abs((v[0]+v[3])-(v[1]+v[2])) << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}