#include <iostream>
#include <algorithm>

void solve()
{
    int n, a, b;
    std::cin >> n >> a >> b;
    std::cout << std::min(n - a, b + 1) << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}