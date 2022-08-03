#include <iostream>

int sumNodesOfBT = 0;
typedef struct BiNode    {
    char data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;
// 三种遍历
void PreorderTraverse(BiTree T);
void InorderTraverse(BiTree T);
void PostorderTraverse(BiTree T);
int GetDepth(BiTree T);
// 构建二叉树（以先序构建）
void CreateBiTree(BiTree *T);
using namespace std;
int main(int argc, char** argv)    {
    freopen("test.txt", "r", stdin);
    // nothing here
    BiTree bt;
    // 前序构建
    CreateBiTree(&bt);
    // 前序遍历输出
    PreorderTraverse(bt);
    cout << endl;
    // 中序遍历
    InorderTraverse(bt);
    cout << endl;
    // 后序遍历
    PostorderTraverse(bt);
    cout << endl;
    int depthOfBT = GetDepth(bt);
    cout << "The depth of this Bitree is : " << depthOfBT << endl;
    cout << "The sum nodes of this Bitree is : " << sumNodesOfBT << endl;
    
    return 0;
}


// 前序遍历
void PreorderTraverse(BiTree T)    {
    if (!T)
        return;
    cout << T->data << " ";
    PreorderTraverse(T->lchild);
    PreorderTraverse(T->rchild);
}

// 中序遍历
void InorderTraverse(BiTree T)    {
    if (!T)
        return;
    InorderTraverse(T->lchild);
    cout << T->data << " ";
    InorderTraverse(T->rchild);
}

// 后序遍历
void PostorderTraverse(BiTree T)    {
    if (!T)
        return;
    PostorderTraverse(T->lchild);
    PostorderTraverse(T->rchild);
    cout << T->data << " ";
}

// 构造二叉树
void CreateBiTree(BiTree *T)    {
    char ch;
    cin >> ch;
    if (ch == '#')
        *T = NULL;
    else    {
        sumNodesOfBT += 1;
        *T = new BiNode;
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

int GetDepth(BiTree T)    {
    if (T == NULL)    return 0;
    else    {
        int left = GetDepth(T->lchild);
        int right = GetDepth(T->rchild);
        if (left > right)    return (left + 1);
        else    return (right + 1);
    }
}