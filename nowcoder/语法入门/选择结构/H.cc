#include <iostream>

void solve()
{
    int a, b, n;
    std::cin >> a >> b >> n;
    if (a + b > n || 1 == ((a + b - n) & 1))
        puts("NO");
    else
        puts("YES");
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}