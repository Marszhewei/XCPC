#include <iostream>

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    a = (a > b) ? a : b;
    std::cout << ((a > c) ? a : c) << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}