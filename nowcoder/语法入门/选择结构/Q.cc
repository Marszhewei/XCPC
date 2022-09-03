#include <iostream>

void solve()
{
    int map1[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int map2[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    std::string ms[] = {"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};

    int year, month, day;
    std::cin >> year;
    getchar();
    std::cin >> month;
    getchar();
    std::cin >> day;

    if (day > 2) {
        day -= 2;
        if (day < 10)
            std::cout << year << '-' << ms[month] << "-0" << day << std::endl;
        else
            std::cout << year << '-' << ms[month] << '-' << day << std::endl;
    }
    else if (month > 1) {
        if (0 == year % 4 && 0 != year % 100 || 0 == year % 400) {
            day = day + map2[--month] - 2;
            std::cout << year << '-' << ms[month] << '-' << day << std::endl;
        }
        else {
            day = day + map1[--month] - 2;
            std::cout << year << '-' << ms[month] << '-' << day << std::endl;
        }
    }
    else {
        year--;
        month = 12;
        day = day + 31 - 2;
        std::cout << year << '-' << ms[month] << '-' << day << std::endl;
    }
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}