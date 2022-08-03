#include <iostream>
#include <queue>

int main(int argc, char** argv)    {
    #ifdef _TEMP_
    // #define _TEMP_
    int *LA = new int[]{3, 5, 8, 11};
    int *LB = new int[]{2, 6, 8, 9, 11, 15, 20};
    int *LC = new int[12];
    #endif
    // 初始化（采用队列来处理此题）
    std::deque<int> dqLA{3, 5, 8, 11};
    std::deque<int> dqLB{2, 6, 8, 9, 11, 15, 20};
    std::queue<int> LA(dqLA), LB(dqLB), LC;

    while (!LA.empty() || !LB.empty())    {
        if (LA.empty())    {
            LC.push(LB.front());
            LB.pop();
        }
        else if (LB.empty())    {
            LC.push(LA.front());
            LA.pop();
        }
        else    {
            if (LA.front() < LB.front())     {
                LC.push(LA.front());
                LA.pop();
            }
            else     {
                LC.push(LB.front());
                LB.pop();
            }
        }
    }

    // 遍历队列并输出
    while (!LC.empty())    {
        std::cout << LC.front() << " ";
        LC.pop();
    }
    std::cout << std::endl;
    return 0;
}