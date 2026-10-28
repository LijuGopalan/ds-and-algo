/*
    Vertical Order Traversal of a Binary Tree (LeetCode 987)

    Given the root of a binary tree, return the vertical order traversal.
    For each column (from leftmost to rightmost), report nodes top-to-bottom.

    Approach:
    - BFS with a map<int, vector<int>> keyed by column index.
    - Root is column 0; left child = col - 1, right child = col + 1.
    - std::map keeps columns sorted automatically.

    Example:
            3
           / \
          9  20
            /  \
           15   7

    Output: [[9], [3, 15], [20], [7]]

    Time:  O(n log n) — map insertions
    Space: O(n)
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    // column → values (in BFS order, so top-to-bottom is natural)
    map<int, vector<int>> columns;
    queue<pair<TreeNode*, int>> q;  // {node, column}
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, col] = q.front(); q.pop();
        columns[col].push_back(node->val);
        if (node->left)  q.push({node->left,  col - 1});
        if (node->right) q.push({node->right, col + 1});
    }

    for (auto& [col, values] : columns) {
        result.push_back(values);
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

    vector<vector<int>> result = verticalOrder(root);

    cout << "Vertical Order Traversal:" << endl;
    for (auto& col : result) {
        cout << "  [ ";
        for (int x : col) cout << x << " ";
        cout << "]" << endl;
    }

    freeTree(root);
    return 0;
}
