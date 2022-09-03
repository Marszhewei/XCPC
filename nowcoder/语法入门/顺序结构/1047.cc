#include <iostream>

void solve()
{
    long long int n, m;
    std::cin >> n >> m;
    std::cout << n * m - n - m << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}