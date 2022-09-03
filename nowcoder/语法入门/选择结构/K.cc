#include <iostream>

void solve()
{
    int t, a = 0, b = 0;
    for (int i = 0; i < 10; ++i) {
        std::cin >> t;
        if (t < 0)
            a++;
        else
            b++;
    }
    std::cout << "positive:" << b << std::endl << "negative:" << a << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}