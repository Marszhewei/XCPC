#include <iostream>
#include <cstring>

void solve()
{
    char s[] = "hello world";
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        s[i] += 1;
        putchar(s[i]);
    }
    putchar('\n');
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}