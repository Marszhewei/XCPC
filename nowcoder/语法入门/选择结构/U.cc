#include <iostream>

void solve()
{
    int n, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    std::cin >> n;
    if (0 != n * 0.1 - int(n * 0.1))
        cnt1++;
    if (0 != n * 0.2 - int(n * 0.2))
        cnt2 = cnt1 + 1;
    else
        cnt2 = cnt1;
    if (0 != n * 0.3 - int(n * 0.3))
        cnt3 = cnt2 + 1;
    else
        cnt3 = cnt2;
    std::cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}