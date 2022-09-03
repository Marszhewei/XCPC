#include <iostream>
#include <cstring>
#include <cstdlib>

#define SIZE 1005

static void solve()
{
    int n;
    std::cin >> n;
    bool flag[SIZE];
    memset(flag, 0, sizeof(flag));
    int temp;
    std::cin >> temp;
    for (int i = 1; i < n; ++i) {
        int next;
        std::cin >> next;
        int pos = abs(next - temp);
        if (flag[pos] || pos > n - 1) {
            puts("Not jolly");
            return;
        }
        flag[pos] = true;
        temp = next;
    }
    puts("Jolly");
}


int main(int argc, char **argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}