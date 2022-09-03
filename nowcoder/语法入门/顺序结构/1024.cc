#include <iostream>

void solve()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("%.2lf %.2lf\n", (a+b+c), (a+b+c)/3);
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}