/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*       created by weizhe                                      *
*       ques two (using BFS and DFS ergodic the graph)         *
*                                                              *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>
#include <cstring>
#include <queue>

typedef long long LL;

const LL NODE = 1 << 3;
const LL EDGE = 2 * NODE - 5;

typedef struct Node    {      // create the link
    int adjvex;
    Node* next;
}EdgeNode;

typedef struct VexNode    {          // create the node list
    char vertex;
    EdgeNode* link;
}VexNode;

bool visit[NODE] {false};    // determine whether it is traversed

void CreateGraph(VexNode* G)    {
    /*
    *   create graph
    *   input pars: G (type: VexNode[])
    *   return pars: None
    */
    for (int i = 0; i < NODE; ++i)    {
        G[i].vertex = getchar();
        G[i].link = nullptr;
    }

    for (int i = 0; i < EDGE; ++i)    {
        int vi, vj;
        EdgeNode* tempEdge = new EdgeNode;
        std::cin >> vi >> vj;
        getchar();
        tempEdge->adjvex = vj;
        tempEdge->next = G[vi].link;
        G[vi].link = tempEdge;
        tempEdge = new EdgeNode;
        tempEdge->adjvex = vi;
        tempEdge->next = G[vj].link;
        G[vj].link = tempEdge;
    }
}

void DFS(VexNode* G, int start)    {
    /*
    *   depth first search to ergodic graph
    *   input pars: G (type: VexNode[]), start pos (type: int)
    *   return pars: None
    */
    std::cout << G[start].vertex << " ";
    visit[start] = true;

    EdgeNode* tempEdge = G[start].link;
    while (tempEdge)    {
        if (!visit[tempEdge->adjvex])    DFS(G, tempEdge->adjvex);
        tempEdge = tempEdge->next;
    }
}

void BFS(VexNode* G, int start)    {
    /*
    *   breadth first search to ergodic graph
    *   input pars: G (type: VexNode[]), start pos (type: int)
    *   return pars: None
    */
    std::queue<int> Q;
    EdgeNode* tempEdge = nullptr;
    std::cout << G[start].vertex << " ";
    visit[start] = true;
    Q.push(start);

    while (!Q.empty())    {
        int ads = Q.front();
        Q.pop();
        tempEdge = G[ads].link;
        while (tempEdge)    {
            if (!visit[tempEdge->adjvex])    {
                std::cout << G[tempEdge->adjvex].vertex << " ";
                visit[tempEdge->adjvex] = true;
                Q.push(tempEdge->adjvex);
            }
            tempEdge = tempEdge->next;
        }
    }
}

int main(int argc, char** argv)    {
    freopen("data2.txt", "r", stdin);
    std::string flag;
    while (std::getline(std::cin, flag))    {
        VexNode G[NODE];
        CreateGraph(G);

        std::cout << "DFS:\n";
        DFS(G, 0);
        memset(visit, 0, sizeof(visit));
        std::cout << "\nBFS:\n";
        BFS(G, 0);
        std::cout << std::endl;
        memset(visit, 0, sizeof(visit));
    }

    return 0;
}
