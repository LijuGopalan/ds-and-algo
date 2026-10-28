/*
    Validate Binary Search Tree (LeetCode 98)

    Determine if a given binary tree is a valid BST.
    A valid BST is defined as:
    - Left subtree contains only nodes with keys < node's key
    - Right subtree contains only nodes with keys > node's key
    - Both left and right subtrees must also be valid BSTs

    Approach:
    - DFS with a valid range [low, high].
    - Root starts with (-∞, +∞).
    - Left child: range becomes (low, parent_val).
    - Right child: range becomes (parent_val, high).

    Time:  O(n)
    Space: O(h)
*/

#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

bool validate(TreeNode* root, long low, long high) {
    if (!root) return true;

    if (root->val <= low || root->val >= high) return false;

    return validate(root->left, low, root->val)
        && validate(root->right, root->val, high);
}

bool isValidBST(TreeNode* root) {
    return validate(root, LONG_MIN, LONG_MAX);
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    // Valid BST
    TreeNode* valid = new TreeNode(5,
        new TreeNode(3, new TreeNode(1), new TreeNode(4)),
        new TreeNode(7, new TreeNode(6), new TreeNode(8)));

    cout << "Valid BST:   " << (isValidBST(valid) ? "true" : "false") << endl;  // true

    // Invalid BST (6 is in the left subtree of 5 but > 5)
    TreeNode* invalid = new TreeNode(5,
        new TreeNode(3, new TreeNode(1), new TreeNode(6)),
        new TreeNode(7));

    cout << "Invalid BST: " << (isValidBST(invalid) ? "true" : "false") << endl;  // false

    freeTree(valid);
    freeTree(invalid);
    return 0;
}
