#include <bits/stdc++.h>

using namespace std;

bitset<1> a[5][6] {0}, b[5][6] = {0}, c[5][6] = {0};
// a数组为初始地图，b数组为最终地图，c数组为执行步骤数组

// char 转 bit
void transbit(char ch)    {
    for (int i = 0; i < 6; ++i)    {
        c[0][i] = (ch >> i) & 1;
    }
}

bool check()    {
    memcpy(b, a, sizeof(a));
    for (int i = 0; i < 5; ++i)    {
        for (int j = 0; j < 6; ++j)    {
            if (c[i][j] == 1)    {
                b[i][j] = ~b[i][j];
                if (j-1>=0) b[i][j-1] = ~b[i][j-1];
                if (j+1<6) b[i][j+1] = ~b[i][j+1];
                if (i+1<5) b[i+1][j] = ~b[i+1][j];
                if (i-1>=0) b[i-1][j] = ~b[i-1][j];
            }
        }
        // 判断最后能否关闭所有灯
        if (i == 4)    {
            for (int j = 0; j < 6; ++j)    {
                if (b[4][j] == 1)    return false;
            }
            break;
        }
        // 依据上一行地图数组递推下一行执行步骤数组
        for (int k = 0; k < 6; ++k)    {
            if (b[i][k] == 0)    c[i+1][k] = 0;
            else    c[i+1][k] = 1;
        }
    }
    return true;
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> a[i][j];
    // cout << "+++++++++++++++++++++++\n";
    // 0 ~ 63进行枚举，经过transbit对第一行进行赋值
    for (char ch = 0; ch < 64; ++ch)    {
        transbit(ch);
        // 如果满足条件，直接输出步骤数组
        if (check())    {
            for (int i = 0; i < 5; ++i)    {
                for (int j = 0; j < 6; ++j)
                    cout << c[i][j] << " ";
                cout << "\n";
            }
        }
    }

    return 0;
}