#include <iostream>

void solve()
{
    int m ,n;
    std::cin >> m >> n;
    if (0 == m % n)
        puts("YES");
    else 
        puts("NO");
}

int main(int argc, char **argv)
{
    solve();

    return 0;
}