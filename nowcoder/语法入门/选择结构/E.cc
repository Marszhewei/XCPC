#include <iostream>

void solve()
{
    long long int x, y;
    std::cin >> x >> y;
    if (0 != y % x)
        std::cout << y - x << std::endl;
    else
        std::cout << x + y << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}