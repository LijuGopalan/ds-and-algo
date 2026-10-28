/*
    Sum of Root-to-Leaf Numbers (LeetCode 129)

    Each root-to-leaf path represents a number (digits concatenated).
    Return the total sum of all root-to-leaf numbers.

    Example:
            1
           / \
          2   3
    Paths: 12, 13  → Sum = 25

    Approach:
    - DFS, carrying the accumulated number (currentSum * 10 + node->val).
    - At a leaf, return the accumulated number.
    - Sum results from left and right subtrees.

    Time:  O(n)
    Space: O(h)
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

int dfs(TreeNode* root, int currentSum) {
    if (!root) return 0;

    currentSum = currentSum * 10 + root->val;

    // Leaf node — this path's number is complete
    if (!root->left && !root->right) {
        return currentSum;
    }

    return dfs(root->left, currentSum) + dfs(root->right, currentSum);
}

int sumNumbers(TreeNode* root) {
    return dfs(root, 0);
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    /*
            4
           / \
          9   0
         / \
        5   1
    Paths: 495, 491, 40  → Sum = 1026
    */
    TreeNode* root = new TreeNode(4,
        new TreeNode(9, new TreeNode(5), new TreeNode(1)),
        new TreeNode(0));

    cout << "Sum of root-to-leaf numbers: " << sumNumbers(root) << endl;  // 1026

    freeTree(root);
    return 0;
}
