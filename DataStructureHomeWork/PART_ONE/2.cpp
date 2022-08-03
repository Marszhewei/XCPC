#include <iostream>

const int c_lines = 10;
typedef struct CycLink    {
    int id;
    CycLink *next;
} CycLink, *PtrCyc;
using namespace std;
int main(int argc, char** argv)    {
    freopen("test.txt", "r", stdin);
    for (int k = 0; k < c_lines; ++k)
    {
        PtrCyc cl = new CycLink;
        PtrCyc p, r = cl;
        r->id = 1;
        int len, flag;
        cin >> len >> flag;
        for (int i = 2; i <= len; ++i)    {
            p = new CycLink;
            p->id = i;
            r->next = p;
            r = p;
        }
        p->next = cl;

        int count = 0;
        PtrCyc m = p, n = cl, t;
        while (!(p->next == p))    {
            if (count == flag)    {
                flag = m->next->id;
                cout << m->next->id << " ";
                PtrCyc q = m->next;
                t = p->next;
                m->next = q->next;
                delete q;
                q = NULL;
                count = 1;
                p = t;
            }
            else    {
                m = p;
                p = p->next;
                count++;
            }
        }
        cout << p->id << endl;
    }
    return 0;
}