/*
    Symmetric Tree (LeetCode 101)

    Check whether a binary tree is a mirror of itself (symmetric around its center).

    Example:
        Symmetric:          Not Symmetric:
            1                    1
           / \                  / \
          2   2                2   2
         / \ / \                \   \
        3  4 4  3                3   3

    Approach:
    - Compare left subtree with right subtree recursively.
    - left->left matches right->right, left->right matches right->left.

    Time:  O(n)
    Space: O(h)
*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    return (left->val == right->val)
        && isMirror(left->left, right->right)
        && isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    // Symmetric tree
    TreeNode* sym = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(2, new TreeNode(4), new TreeNode(3)));

    cout << "Symmetric tree: " << (isSymmetric(sym) ? "true" : "false") << endl;

    // Not symmetric
    TreeNode* asym = new TreeNode(1,
        new TreeNode(2, nullptr, new TreeNode(3)),
        new TreeNode(2, nullptr, new TreeNode(3)));

    cout << "Asymmetric tree: " << (isSymmetric(asym) ? "true" : "false") << endl;

    freeTree(sym);
    freeTree(asym);
    return 0;
}
