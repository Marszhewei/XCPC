#include <iostream>

void solve()
{
    int n;
    scanf("%d", &n);
    double res = n * 12 * 2.54 * 10;
    if (0 == res - int(res))
        printf("%.lf", res);
    else
        printf("%.1lf", res);
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}