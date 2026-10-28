/*
    Binary Tree Right Side View (LeetCode 199)

    Given the root of a binary tree, return the values of the nodes
    you can see when looking at the tree from the right side.
    (i.e., the last node at each level)

    Approach:
    - BFS level-by-level, take the last element of each level.

    Example:
            1
           / \
          2   3
           \   \
            5   4

    Output: [1, 3, 4]

    Time:  O(n)
    Space: O(n)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == size - 1) result.push_back(node->val);  // rightmost node
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(1,
        new TreeNode(2, nullptr, new TreeNode(5)),
        new TreeNode(3, nullptr, new TreeNode(4)));

    vector<int> view = rightSideView(root);

    cout << "Right Side View: ";
    for (int x : view) cout << x << " ";
    cout << endl;  // 1 3 4

    freeTree(root);
    return 0;
}
