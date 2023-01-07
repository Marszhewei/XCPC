/**
 * @file tournament_sort.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 锦标赛算法
 * @version 0.1
 * @date 2022-12-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using std::cin, std::cout, std::endl;
using std::vector;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node *create_tree(int lo, int hi);
void update_tree(Node *node, int i, int val);
int find_max(Node *node, int lo, int hi);
void tournament_sort(vector<int> &arr);

int main(int argc, char **argv)
{
    vector<int> arr {-71, 64, 5, 444, 3, 10, 2, -1};
    tournament_sort(arr);
    auto print = [&arr]() {
        for (auto i: arr)
            cout << i << ' ';
        cout << endl;
    };
    print(); 
    return 0;
}

// 创建锦标赛树
Node *create_tree(int lo, int hi)
{
    if (lo == hi)
        return new Node(lo);

    int mid = lo + (hi - lo) / 2;
    Node *node = new Node(-1);
    node->left = create_tree(lo, mid);
    node->right = create_tree(mid + 1, hi);

    return node;
}

// 更新锦标赛树
void update_tree(Node *node, int i, int val)
{
    if (node == nullptr)
        return;

    if (node->val == -1) {
        update_tree(node->left, i, val);
        update_tree(node->right, i, val);
        node->val = std::max(node->left->val, node->right->val);
    } else if (node->val == i) {
        node->val = val;
    } else {
        nullptr;
    }
}

// 查找锦标赛树中最大值
int find_max(Node *node, int lo, int hi)
{
    if (node == nullptr)
        return -1;

    if (node->val == -1) {
        if (lo == hi)
            return node->left->val;

        int mid = lo + (hi - lo) / 2;
        int left_max = find_max(node->left, lo, mid);
        int right_max = find_max(node->right, mid + 1, hi);

        return std::max(left_max, right_max);
    } else {
        return node->val;
    }
}

// 锦标赛排序
void tournament_sort(vector<int> &arr)
{
    // 创建锦标赛树
    Node *root = create_tree(0, arr.size() - 1);

    // 将每个元素插入到锦标赛树中
    for (int i = 0; i < arr.size(); i++)
        update_tree(root, i, arr[i]);

    // 将锦标赛树中的元素按顺序拿出来，即为排序后的数
    for (int i = arr.size() - 1; i >= 0; i--) {
        int max_index = find_max(root, 0, i);
        arr[i] = max_index;
        update_tree(root, max_index, -1);
    }
}
