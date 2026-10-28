/*
    Path With Given Sequence

    Given a binary tree and a sequence (array), check if the sequence
    represents a valid root-to-leaf path in the tree.

    Example:
            1
           / \
          7   9
             / \
            2   9

    Sequence: [1, 9, 9] → true  (path: 1 → 9 → 9)
    Sequence: [1, 7]    → true  (path: 1 → 7)
    Sequence: [1, 9, 2] → true  (path: 1 → 9 → 2)

    Approach:
    - DFS, tracking the current index in the sequence.
    - At each node, check if node value matches sequence[index].
    - At a leaf, also verify that we've matched the entire sequence.

    Time:  O(n)
    Space: O(h)
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

bool dfs(TreeNode* root, const vector<int>& seq, int index) {
    if (!root) return false;

    // Out of bounds or mismatch
    if (index >= (int)seq.size() || root->val != seq[index]) {
        return false;
    }

    // Leaf: valid only if we've consumed the entire sequence
    if (!root->left && !root->right) {
        return index == (int)seq.size() - 1;
    }

    return dfs(root->left, seq, index + 1) || dfs(root->right, seq, index + 1);
}

bool hasPath(TreeNode* root, const vector<int>& sequence) {
    return dfs(root, sequence, 0);
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(1,
        new TreeNode(7),
        new TreeNode(9, new TreeNode(2), new TreeNode(9)));

    cout << "[1,9,9]: " << (hasPath(root, {1, 9, 9}) ? "true" : "false") << endl;  // true
    cout << "[1,7]:   " << (hasPath(root, {1, 7})     ? "true" : "false") << endl;  // true
    cout << "[1,9,2]: " << (hasPath(root, {1, 9, 2})  ? "true" : "false") << endl;  // true
    cout << "[1,9,3]: " << (hasPath(root, {1, 9, 3})  ? "true" : "false") << endl;  // false

    freeTree(root);
    return 0;
}
