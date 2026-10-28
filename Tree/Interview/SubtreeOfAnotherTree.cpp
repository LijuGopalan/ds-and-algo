/*
    Subtree of Another Tree (LeetCode 572)

    Given the roots of two binary trees `root` and `subRoot`,
    return true if there is a subtree of `root` with the same
    structure and node values as `subRoot`.

    Approach:
    - For every node in `root`, check if the subtree rooted there
      is identical to `subRoot`.
    - "Identical" = same structure and values (recursive comparison).

    Example:
        root:           subRoot:
            3               4
           / \              / \
          4   5            1   2
         / \
        1   2

    → true (subtree rooted at node 4 matches)

    Time:  O(m * n) — for each of m nodes in root, compare up to n nodes
    Space: O(h) — recursion depth
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

bool isSameTree(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return (a->val == b->val)
        && isSameTree(a->left, b->left)
        && isSameTree(a->right, b->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;
    if (isSameTree(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(3,
        new TreeNode(4, new TreeNode(1), new TreeNode(2)),
        new TreeNode(5));

    TreeNode* subRoot = new TreeNode(4, new TreeNode(1), new TreeNode(2));

    cout << "Is subtree: " << (isSubtree(root, subRoot) ? "true" : "false") << endl;  // true

    TreeNode* notSub = new TreeNode(4, new TreeNode(1), new TreeNode(3));
    cout << "Is subtree: " << (isSubtree(root, notSub) ? "true" : "false") << endl;  // false

    freeTree(root);
    freeTree(subRoot);
    freeTree(notSub);
    return 0;
}
