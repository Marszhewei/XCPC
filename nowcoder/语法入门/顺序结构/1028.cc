#include <iostream>

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << (a*b + b*c + a*c) * 2 << std::endl << a*b*c << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}