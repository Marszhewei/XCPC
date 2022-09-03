#include <iostream>

void solve()
{
    char map[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'X'};
    std::string s;
    std::cin >> s;
    int sm = 0, cnt = 1;
    for (int i = 0; i < 12; ++i) {
        if ('-' != s[i]) {
            sm += (s[i] ^ 48) * cnt;
            cnt++;
        }
    }
    if (map[sm % 11] == s[12])
        puts("Right");
    else {
        s[12] = map[sm % 11];
        std::cout << s << std::endl;
    }
}


int main(int argc, char **argv)
{
    solve();
    return 0;
}