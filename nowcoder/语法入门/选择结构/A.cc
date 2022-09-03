#include <iostream>

void solve()
{
    int m, n;
    std::cin >> m >> n;
    if (m < n)
        putchar('<');
    else if (m > n)
        putchar('>');
    else 
        putchar('=');
}


int main(int argc, char **argv)
{
    solve();
    return 0;
}