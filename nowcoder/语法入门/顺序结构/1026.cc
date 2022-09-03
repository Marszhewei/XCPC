#include <iostream>

void solve()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%.3lf", 0.5*(a+b)*c);
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}