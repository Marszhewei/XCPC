/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*       created by weizhe                                      *
*       ques one (using huffman tree to build huffman code)    *
*                                                              *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>

#define INF 1 << 8      // this is Infinity num

// #define _DEBUG

typedef long long LL;

const LL NODE_SIZE = 1 << 3;    // tree node size (include no named)
const LL TREE_SIZE = NODE_SIZE * 2 - 1;    // node that has name

// tree
typedef struct Node    {
    int weight;      // weight
    char name;          // the name of node
    int lchild, rchild, parent;   // left and right child, and parent
}HFMtree;

// code
typedef struct Code    {
    std::string bits;  // huffman code
    char name;         // node name
}CodeType;


using namespace std;

void CreateTree(HFMtree* tree)    {
    /*
    *   create huffman tree
    *   intput pars: tree (type: struct HFMtree[])
    *   return pars: None
    */
    int small_1, small_2;   // record the smallest and the second small node

    for (int i = 0; i < TREE_SIZE; ++i)    {     // init
        tree[i].parent = -1;
        tree[i].lchild = -1;
        tree[i].rchild = -1;
        tree[i].weight = 0;
        tree[i].name = '0';
    }

    for (int i = 0; i < NODE_SIZE; ++i)    {     // input node name and weight
        tree[i].name = getchar();
        cin >> tree[i].weight;
        // getchar();
    }

    // use of debugger
    #ifdef _DEBUG
    for (int i = 0; i < NODE_SIZE; ++i)    {
        cout << tree[i].name << " " << tree[i].weight << endl;
    }
    #endif

    for (int i = NODE_SIZE; i < TREE_SIZE; ++i)    {   // main part of create
        int ptr1 = 0, ptr2 = 0;
        small_1 = small_2 = INF;
        for (int j = 0; j <= i - 1; ++j)    {
            if (tree[j].parent == -1)    {
                if (tree[j].weight < small_1)    {
                    small_2 = small_1;
                    small_1 = tree[j].weight;
                    ptr2 = ptr1;
                    ptr1 = j;
                }
                else if (tree[j].weight < small_2)    {
                    small_2 = tree[j].weight;
                    ptr2 = j;
                }
            }
        }
        tree[ptr1].parent = tree[ptr2].parent = i;
        tree[i].lchild = ptr1;
        tree[i].rchild = ptr2;
        tree[i].weight = tree[ptr1].weight + tree[ptr2].weight;
    }
}

void CreateCode(CodeType* code, HFMtree* tree)     {
    /*
    *   create huffman code by huffman tree
    *   intput pars: tree (type: struct HFMtree[]), code (type: struct CodeType[])
    *   return pars: None
    */
    CodeType ct;
    for (int i = 0; i < NODE_SIZE; ++i)    {
        int p = tree[i].parent;
        ct.name = tree[i].name;
        ct.bits = "";
        int k = 0;
        while (p != -1)    {         // reverse building huffman code
            if (tree[p].lchild == i) ct.bits = '0' + ct.bits;
            else ct.bits = '1' + ct.bits;
            p = tree[p].parent;
        }
        code[i] = ct;
    }
}


int main(int argc, char** argv)    {
    freopen("data1.txt", "r", stdin);
    string flag = "";        // the group of data
    while (getline(cin, flag))    {
        HFMtree tree[TREE_SIZE];
        CodeType code[NODE_SIZE];
        CreateTree(tree); 
        CreateCode(code, tree);
        getchar();          // read the endline

        for (int i = 0; i < TREE_SIZE; ++i)    {         // output the info of huffman tree
            cout << "name:\t" << tree[i].name << "\tparent: " << tree[i].parent 
                << "\tlchild: " << tree[i].lchild << "\tright: " << tree[i].rchild << endl;
        }
        cout << endl;


        for (int i = 0; i < NODE_SIZE; ++i)    {         // output the huffman code
            cout << code[i].name << " : "<< code[i].bits << "    ";
        }
        cout << endl;
    }

    return 0;
}