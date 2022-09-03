#include <iostream>

void solve()
{
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    printf("%.1lf\n", (a+b+c+d+e)/5.0);
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}