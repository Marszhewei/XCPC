#include <iostream>

void solve()
{
    int n;
    std::cin >> n;
    if (0 == n % 4 && 0 != n % 100 || 0 == n % 400)
        puts("yes");
    else
        puts("no");
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}