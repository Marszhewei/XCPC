#include <iostream>
#include <cmath>

void solve()
{
    int n;
    scanf("%d", &n);
    printf("%.3lf\n", pow(n, 1.0/3)*3);
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}