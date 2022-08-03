#include <iostream>
#define _BIN
// #define _OCT
// #define _MYHEX

const int MAX_SIZE = 100;

typedef struct SqStack    {
    char data[MAX_SIZE];
    int top;
}SqStack;

bool Coversion();
SqStack *InitStack();
bool StackEmpty(const SqStack* S);
bool Push(SqStack* S, char elem);
char Pop(SqStack* S);
using namespace std;
int main(int argc, char** argv)    {
    freopen("test.txt", "r", stdin);
    while (true)
        if (!Coversion())
            break;


    return 0;
}

bool Coversion()    {
    SqStack* S = InitStack();
    int n;
    if (!cin.eof())
        cin >> n;
    else    return false;

    #ifdef _BIN
    char C[2]{'0', '1'};
    cout << "BIN: ";
    while (n > 0)    {
        Push(S, C[n % 2]);
        n /= 2;
    }
    #endif

    #ifdef _OCT
    char C[8]{'0', '1', '2', '3', '4', '5', '6', '7'};
    cout << "OCT: ";
    while (n > 0)    {
        Push(S, C[n % 8]);
        n /= 8;
    }
    #endif

    #ifdef _MYHEX
    cout << "HEX: ";
    char C[16]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n > 0)    { 
        Push(S, C[n % 16]);
        n /= 16;
    }
    #endif

    while (StackEmpty(S))    {
        putchar(Pop(S));
    }
    cout << endl;
    return true;
}

SqStack *InitStack()    {
    SqStack* S = new SqStack;
    S->top = 0;

    return S;
}   

bool StackEmpty(const SqStack* S)    {
    if (S->top == 0)    {
        return false;
    }
    return true;
}


bool Push(SqStack* S, char elem)   {
    if (S->top == MAX_SIZE - 1)    {
        cout << "The stack is full." << endl;
        return false;
    }

    S->top++;
    S->data[S->top] = elem;

    return true;
}


char Pop(SqStack* S)    {
    char elem = S->data[S->top];
    S->top--;

    return elem;
}
