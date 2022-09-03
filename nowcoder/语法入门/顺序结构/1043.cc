#include <iostream>

void solve()
{
    long long int n;
    std::cin >> n;
    std::cout << n / 3 * 2 + ((n % 3) ? 1 : 0) << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}