#include <iostream>
#include <algorithm>

void solve()
{
    int a[3];
    for (int i = 0; i < 3; ++i)
        std::cin >> a[i];
    std::sort(a, a + 3);
    std::cout << "The maximum number is : " << a[2] << std::endl
              << "The minimum number is : " << a[0] << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}