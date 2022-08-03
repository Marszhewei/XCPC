#include <iostream>

const int ARR_SIZE = 100;
typedef struct Node    {
    int data;
    Node* next;
}Node, *QueuePtr;

typedef struct LinkQueue    {
    QueuePtr front, rear;
}LinkQueue;

LinkQueue *InitQueue();
bool EnQueue(LinkQueue* Q, int elem);
bool OutQueue(LinkQueue* Q);
int PeekQueue(const LinkQueue* Q);
bool EmptyQueue(const LinkQueue* Q);
void ClearQueue(LinkQueue* Q);
using namespace std;
int main(int argc, char** argv)    {
    LinkQueue* Q = InitQueue();
    // 创建数组并给数组赋值
    int* arr = new int[ARR_SIZE];
    int size = 0;
    cout << "Please input the size of arr: ";
    cin >> size;
    cout << "Try to input the elems of arr." << endl;
    for (int i = 0; i < size; ++i)    {
        cin >> arr[i];
    }
    // 将数组插入到队列中
    for (int i = 0; i < size; ++i)    {
        if (!EnQueue(Q, arr[i]))     cout << "Enter Queue Error!" << endl;
    }
    // 以下是一些对队列基本操作的演示
    // 获取队首元素
    cout << "The first elem is : " << PeekQueue(Q) << endl;
    // 出队
    OutQueue(Q);
    // 再次获取队首元素以检查出队是否成功
    cout << "The first elem is : " << PeekQueue(Q) << endl;

    delete [] arr;
    arr = NULL;

    ClearQueue(Q);
    return 0;
}

LinkQueue *InitQueue()    {
    LinkQueue* Q = new LinkQueue;
    Q->front = new Node;
    Q->rear = Q->front;
    return Q;
}

bool EnQueue(LinkQueue* Q, int elem)    {
    QueuePtr p = new Node;
    if (!p)    {
        exit(EOVERFLOW);
    }
    p->data = elem;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;

    return true;
}

bool OutQueue(LinkQueue* Q)    {
    QueuePtr p;
    if (EmptyQueue(Q))    {
        cout << "The queue is empty." << endl;
        return false;
    }
    p = Q->front->next;
    Q->front->next = p->next;

    if (Q->rear == p)    {
        Q->rear = Q->front;
    }
    delete p;
    p = NULL;
    return true;
}

int PeekQueue(const LinkQueue* Q)    {
    return Q->front->next->data;
}

bool EmptyQueue(const LinkQueue* Q)    {
    return Q->front == Q->rear;
}

void ClearQueue(LinkQueue* Q)    {
    while (!EmptyQueue(Q))    {
        OutQueue(Q);
    }
    delete Q;
    Q = NULL;
}