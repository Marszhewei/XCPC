#include <iostream>


void solve()
{
    int32_t t;
    while (std::cin >> t) {
        for (int i = 1; i <= t; ++i) {
            for (int j = 1; j < t + 1 - i; ++j) {
                std::cout << ' ';
            }
            for (int j = 1; j <= 1 + (i - 1) * 2; ++j) {
                std::cout << '*';
            }
            std::cout << std::endl;
        }
        for (int i = t - 1; i >= 1; --i) {
            for (int j = 1; j < t + 1 - i; ++j) {
                std::cout << ' ';
            }
            for (int j = 1; j <= 1 + (i - 1) * 2; ++j) {
                std::cout << '*';
            }
            std::cout << std::endl;
        }
    }
}


int main(int argc, char **argv)
{
    solve();
    return 0;
}