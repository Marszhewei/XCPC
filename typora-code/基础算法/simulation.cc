/**
 * @file simulation.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 基础算法模拟
 * @version 0.1
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

int solve(int h, int up, int down);

int main(int argc, char **argv)
{
    std::cout << solve(10, 7, 4) << std::endl;
    
    return 0;
}

int solve(int h, int up, int down)
{
    int cnt = 0;
    while (true) {
        h -= up;
        ++cnt;
        if (h <= 0) break;
        h += down;
    }
    return cnt;
}