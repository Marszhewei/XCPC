#include <iostream>

void solve()
{
    int a, b;
    bool flag = true;
    for (int i = 1; i <= 7; ++i) {
        std::cin >> a >> b;
        if (a + b > 8 && flag) {
            std::cout << i << std::endl;
            flag = false;
        }
    }
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}