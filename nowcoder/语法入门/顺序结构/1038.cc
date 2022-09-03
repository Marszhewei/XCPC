#include <iostream>
#include <cmath>

void solve()
{
    int x, y, z;
    std::cin >> x >> y >> z;
    int a2 = x * y / z;
    int b2 = x * z / y;
    int c2 = y * z / x;
    std::cout << int(sqrt(a2)+sqrt(b2)+sqrt(c2))*4 << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}