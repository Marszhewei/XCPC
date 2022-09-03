#include <iostream>
#include <algorithm>

void solve()
{
    int n, x, y;
    std::cin >> n >> x >> y;
    std::cout << std::min(x, y) << ' ' << ((x+y) > n ? (x+y-n) : 0) << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}