#include <iostream>


void solve()
{
    long long int n;
    std::cin >> n;
    if (n & 1)
        n = 3 * n + 1;
    else 
        n /= 2;
    std::cout << n << std::endl;    
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}