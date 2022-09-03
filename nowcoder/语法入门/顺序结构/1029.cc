#include <iostream>
#include <cmath>

void solve()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    double p = (a+b+c)*0.5;
    printf ("circumference=%.2lf area=%.2lf\n", 2*p, sqrt(p*(p-a)*(p-b)*(p-c)));
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}