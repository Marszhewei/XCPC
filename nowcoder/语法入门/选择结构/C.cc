#include <iostream>

void solve()
{
    int m, n;
    std::cin >> m >> n;
    if (n == m)
        puts("Tacit！");
    else
        puts("No Tacit!");
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}