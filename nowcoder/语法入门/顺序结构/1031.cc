#include <iostream>

void solve()
{
    long long int n;
    std::cin >> n;
    std::cout << n/3600 << ' ' << n%3600/60 << ' ' << n%3600%60 << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}