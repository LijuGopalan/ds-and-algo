/*
    Binary Tree Zigzag Level Order Traversal (LeetCode 103)

    Given a binary tree, return the zigzag level order traversal:
    - Level 0: left → right
    - Level 1: right → left
    - Level 2: left → right
    - ... alternating

    Approach:
    - Standard BFS with a queue.
    - Pre-allocate a vector of level size.
    - Use an index to insert from the left or right depending on direction.

    Example:
            3
           / \
          9  20
            /  \
           15   7

    Output: [[3], [20, 9], [15, 7]]

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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};

    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();

            // Place element at the correct index based on direction
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->val;

            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(level);
        leftToRight = !leftToRight;
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
    TreeNode* root = new TreeNode(3,
        new TreeNode(9),
        new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    vector<vector<int>> result = zigzagLevelOrder(root);

    cout << "Zigzag Level Order:" << endl;
    for (auto& level : result) {
        cout << "  [ ";
        for (int x : level) cout << x << " ";
        cout << "]" << endl;
    }

    freeTree(root);
    return 0;
}
