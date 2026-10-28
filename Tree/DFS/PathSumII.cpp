/*
    Path Sum II — Find All Paths (LeetCode 113)

    Given a binary tree and a target sum, find ALL root-to-leaf paths
    where the sum of node values equals the target.

    Approach:
    - DFS with backtracking.
    - Maintain a `currentPath` vector; push on enter, pop on leave.
    - At a leaf, if remaining sum == node value, snapshot the path.

    Time:  O(n * h) — n nodes, each path can be up to h long
    Space: O(h) — recursion + path storage
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

void dfs(TreeNode* root, int remaining, vector<int>& path, vector<vector<int>>& result) {
    if (!root) return;

    path.push_back(root->val);

    // Leaf check
    if (!root->left && !root->right && root->val == remaining) {
        result.push_back(path);
    } else {
        dfs(root->left,  remaining - root->val, path, result);
        dfs(root->right, remaining - root->val, path, result);
    }

    path.pop_back();  // backtrack
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(root, targetSum, path, result);
    return result;
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    /*
            5
           / \
          4   8
         /   / \
        11  13  4
       / \     / \
      7   2   5   1

      Target: 22
      Paths: [5,4,11,2] and [5,8,4,5]
    */
    TreeNode* root = new TreeNode(5,
        new TreeNode(4,
            new TreeNode(11, new TreeNode(7), new TreeNode(2)),
            nullptr),
        new TreeNode(8,
            new TreeNode(13),
            new TreeNode(4, new TreeNode(5), new TreeNode(1))));

    vector<vector<int>> paths = pathSum(root, 22);

    cout << "Paths with sum 22:" << endl;
    for (auto& p : paths) {
        cout << "  [ ";
        for (int x : p) cout << x << " ";
        cout << "]" << endl;
    }

    freeTree(root);
    return 0;
}
