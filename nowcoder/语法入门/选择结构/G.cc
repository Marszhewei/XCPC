#include <iostream>

void solve()
{
    int n;
    std::cin >> n;
    n--;
    if (0 == n % 2 || 0 == n % 4 || 0 == n % 6)
        std::cout << n + 1 << std::endl;
    else 
        std::cout << -1 << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}