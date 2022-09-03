#include <iostream>

void solve()
{
    int n;
    std::cin >> n;
    std::cout << n % 100 / 10 << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}