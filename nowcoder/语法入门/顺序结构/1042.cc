#include <iostream>
#include <cmath>

void solve()
{
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    std::cout << std::min(a, e) + std::min(b, f) + std::min(c, d) << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}