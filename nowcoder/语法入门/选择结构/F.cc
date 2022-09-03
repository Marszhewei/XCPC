#include <iostream>

void solve()
{
    int n;
    std::cin >> n;
    if (1 & n || n == 2)
        puts("NO, you can't divide the watermelon into two even parts.");
    else 
        puts("YES, you can divide the watermelon into two even parts.");
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}