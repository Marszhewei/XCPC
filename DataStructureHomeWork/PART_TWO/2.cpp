#include <iostream>
#include <cstring>


const int MAX_SIZE = 100;
typedef struct MyString    {
    char data[MAX_SIZE];
    int length;
}MyString;

MyString* FindSubString(MyString* S, int pos, int len);
MyString *Connect(MyString* S1, MyString* S2);
void RePlace(MyString* S1, MyString*S2);
using namespace std;
int main(int argc, char** argv)    {
    freopen("test.txt", "r", stdin);
    for (int k = 0; k < 4; ++k)    {
        MyString* S1 = new MyString;
        MyString* S2 = new MyString;
        S1->length = 0;
        S2->length = 0;
        // input
        // cin.getline(S1->data, MAX_SIZE);
        // cin.getline(S2->data, MAX_SIZE);
        // 输入S1
        char ch = getchar();
        for (int i = 0; ch != '\n'; ++i)    {
            S1->data[i] = ch;
            ch = getchar();
            S1->length++;
        }
        S1->data[S1->length] = '\0';
        // 输入S2
        ch = getchar();
        for (int i = 0; ch != '\n'; ++i)    {
            S2->data[i] = ch;
            ch = getchar();
            S2->length++;
        }
        S2->data[S2->length] = '\0';
        int pos, len;
        // 输入位置和定长
        cin >> pos >> len;
        getchar();
        MyString* newSub = FindSubString(S1, pos, len);
        cout << newSub->data << endl;

        MyString* S = Connect(S1, S2);
        cout << S->data << endl;

        RePlace(S1, S2);
        cout << S1->data << endl;
    }

    return 0;
}

MyString *FindSubString(MyString* S, int pos, int len)    {
    MyString* newSub = new MyString;
    newSub->length = 0;
    for (int i = pos, j = 0; i < pos + len; ++i)    {
        newSub->data[j++] = S->data[i];
        newSub->length++;
    }
    return newSub;
}
MyString *Connect(MyString* S1, MyString* S2)    {
    MyString* TS1 = new MyString;
    MyString* TS2 = new MyString;
    strcpy(TS1->data, S1->data);
    strcpy(TS2->data, S2->data);
    strcat(TS1->data, TS2->data);
    delete TS2;
    TS2 = NULL;
    return TS1;
}

void RePlace(MyString* S1, MyString* S2)    {
    for (int i = S1->length - 1, j = S2->length - 1; i >= S1->length - S2->length; --i, j--)    {
        S1->data[i] = S2->data[j];
    }
}