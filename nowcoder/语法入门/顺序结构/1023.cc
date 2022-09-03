#include <iostream>
#include <algorithm>

void solve()
{
    std::string s;
    std::cin >> s;
    std::reverse(s.begin(), s.end());
    std::cout << s << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}