#include <iostream>
#include <algorithm>
#include <cmath>

void solve()
{
    double h, s, v, l, k, n;
    int g = 10;
    scanf("%lf %lf %lf %lf %lf %lf",  &h, &s, &v, &l, &k, &n);
    double t1 = sqrt(2.0 * (h - k) / g);
    double t2 = sqrt(2.0 * h / g);
    double x1 = s - v * t2;
    double x2 = s + l - v * t1;

    printf("%d\n", int(std::min(x2, n * 1.0)) - int(std::max(x1, 0.0)));
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}