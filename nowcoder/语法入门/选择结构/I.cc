#include <iostream>

void solve()
{
    int n;
    std::cin >> n;
    if (n <= 50 || n & 1)
        puts("no");
    else
        puts("yes");
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}