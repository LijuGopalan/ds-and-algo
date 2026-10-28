/*
    Level Order Traversal — Bottom to Top (LeetCode 107)

    Given a binary tree, return the bottom-up level order traversal
    (i.e., from the level of leaf nodes up to the root).

    Approach:
    - Standard BFS with a queue, but push each level to the FRONT
      of a deque instead of the back.

    Example:
            3
           / \
          9  20
            /  \
           15   7

    Output: [[15, 7], [9, 20], [3]]

    Time:  O(n)
    Space: O(n)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root) return {};

    queue<TreeNode*> q;
    q.push(root);
    deque<vector<int>> dq;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        dq.push_front(level);  // key: push to front for bottom-up order
    }

    return vector<vector<int>>(dq.begin(), dq.end());
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(3,
        new TreeNode(9),
        new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    vector<vector<int>> result = levelOrderBottom(root);

    cout << "Level Order (Bottom to Top):" << endl;
    for (auto& level : result) {
        cout << "  [ ";
        for (int x : level) cout << x << " ";
        cout << "]" << endl;
    }

    freeTree(root);
    return 0;
}
