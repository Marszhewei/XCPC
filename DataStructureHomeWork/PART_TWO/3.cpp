#include <iostream>
#include <string>

using namespace std;
int SimpleIndex(string mainStr, string subStr, int pos);

int main(int argc, char** argv)    {
    freopen("test.txt", "r", stdin);
    for (int i = 0; i < 4; ++i)    {
        string mainStr, subStr;
        int pos;
        getline(cin, mainStr);
        getline(cin, subStr);
        cin >> pos;
        getchar();

        cout << "Pos: " << SimpleIndex(mainStr, subStr, pos) << endl;
    }
    return 0;
}

int SimpleIndex(string mainStr, string subStr, int pos)    {
    int j = 0;
    int i = pos;
    for ( ; i < mainStr.size() && j < subStr.size(); )    {
        if (mainStr[i] == subStr[j])    {
            ++i;
            ++j;
        }
        else    {
            i = i - j + 1;
            j = 0;
        }
    }  
    if (j >= subStr.size())    {
        return i - subStr.size();
    }
    else    return -1;
}




