#include <iostream>

void solve()
{
    int m, n;
    std::cin >> m >> n;
    std::cout << ((m + n) % 7 ? (m + n) % 7 : 7) << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}