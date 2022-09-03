#include <iostream>

void solve()
{
    int m, n;
    std::cin >> m >> n;
    std::cout << std::hex <<  (m + n) << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}