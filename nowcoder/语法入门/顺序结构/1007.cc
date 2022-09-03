#include <iostream>

void solve()
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%.3f\%\n", 100.0*n/m);
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}