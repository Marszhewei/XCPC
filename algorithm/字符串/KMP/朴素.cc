#include <iostream>

int solve(std::string s1, std::string s2) {
    int len1 = s1.length(), len2 = s2.length(), i = 0, j = 0;
    for ( ; i < len1, j < len2; ) {
        if (s1[i] == s2[j]) ++i, ++j;
        else i = i-j+1, j = 0;
    }
    if (j == len2) return i-j;
    else return -1;
}

int main(void) {
    std::string s1, s2; std::cin >> s1 >> s2;
    std::cout << solve(s1, s2) << '\n';
 
    return 0;
}