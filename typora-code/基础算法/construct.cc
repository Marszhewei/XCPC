/**
 * @file construct.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 构造
 * @version 0.1
 * @date 2022-12-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

void solve_cf_div2_384_c()
{
    // x,y,z互不同，给定n，满足1/x + 1/y + 1/z = 2/n
    // (x+y)/xy + 1/z = 2/n, 令z = xy, 2xy = n(x+y+1), y = x+1 => x=n, y=n+1, z=n(n+1)
    int n, x, y, z; std::cin >> n;
    x = n;
    y = n + 1;
    z = n * (n + 1);
    std::cout << x << ' ' << y << ' ' << z << std::endl;
}

int main(int argc, char **argv)
{
    solve_cf_div2_384_c();

    return 0;
}