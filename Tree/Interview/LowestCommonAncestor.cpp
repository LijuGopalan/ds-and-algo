/*
    Lowest Common Ancestor of a Binary Tree (LeetCode 236)

    Given a binary tree and two nodes p and q, find their lowest common ancestor (LCA).
    The LCA is the deepest node that is an ancestor of both p and q.

    Approach:
    - Recursive DFS.
    - If current node is null, or equals p or q, return it.
    - Recurse on left and right subtrees.
    - If both return non-null → current node is the LCA.
    - If only one returns non-null → that's the LCA (both p and q are in that subtree).

    Example:
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4

    LCA(5, 1) = 3
    LCA(5, 4) = 5

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* left  = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;  // p and q are in different subtrees
    return left ? left : right;      // both are in the same subtree
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2, node7, node4);
    TreeNode* node5 = new TreeNode(5, node6, node2);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node1 = new TreeNode(1, node0, node8);
    TreeNode* root  = new TreeNode(3, node5, node1);

    TreeNode* lca1 = lowestCommonAncestor(root, node5, node1);
    cout << "LCA(5, 1) = " << lca1->val << endl;  // 3

    TreeNode* lca2 = lowestCommonAncestor(root, node5, node4);
    cout << "LCA(5, 4) = " << lca2->val << endl;  // 5

    freeTree(root);
    return 0;
}
