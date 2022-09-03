#include <iostream>


void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    int res = a * b * c;
    if (res < a + b + c)
        res = a + b + c;
    if (res < (a + b) * c)
        res = (a + b) * c;
    if (res < a * (b + c))
        res = a * (b + c);
    std::cout << res << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}