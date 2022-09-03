#include <iostream>

void solve()
{
    long long int n;
    std::cin >> n;
    std::string map[] = {"00", "winter", "winter", "spring", "spring", "spring", "summer",
                        "summer", "summer", "autumn", "autumn", "autumn", "winter"};
    std::cout << map[n % 100] << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}