#include <iostream>

void solve()
{
    int year, month, day;
    std::cin >> year;
    getchar();
    std::cin >> month;
    getchar();
    std::cin >> day;

    if (month > 10 || month == 10 && day >= 29)
        std::cout << "QAQ" << std::endl;
    else 
        std::cout << "No. It's not too late." << std::endl;
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}