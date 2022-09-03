#include <iostream>

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    if ((a + b + c) / 3.0 >= 60)
        puts("NO");
    else
        puts("YES");
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}