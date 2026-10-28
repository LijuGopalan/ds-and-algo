/*
    Path Sum (LeetCode 112)

    Given a binary tree and a target sum, determine if the tree has
    a root-to-leaf path such that the sum of all node values equals the target.

    Approach:
    - DFS, subtracting each node's value from the target.
    - At a leaf, check if the remaining sum equals the node's value.

    Time:  O(n)
    Space: O(h) — recursion stack
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;

    // Leaf node: check if remaining sum matches
    if (!root->left && !root->right) {
        return root->val == targetSum;
    }

    int remaining = targetSum - root->val;
    return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
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
       / \       \
      7   2       1

      Target: 22  → true (5 → 4 → 11 → 2)
    */
    TreeNode* root = new TreeNode(5,
        new TreeNode(4,
            new TreeNode(11, new TreeNode(7), new TreeNode(2)),
            nullptr),
        new TreeNode(8,
            new TreeNode(13),
            new TreeNode(4, nullptr, new TreeNode(1))));

    cout << "Has path sum 22: " << (hasPathSum(root, 22) ? "true" : "false") << endl;
    cout << "Has path sum 27: " << (hasPathSum(root, 27) ? "true" : "false") << endl;

    freeTree(root);
    return 0;
}
