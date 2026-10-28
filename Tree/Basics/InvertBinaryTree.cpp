/*
    Invert Binary Tree (LeetCode 226)

    Mirror every node: swap left and right children recursively.

    Example:
        Input:        Output:
            4             4
           / \           / \
          2   7         7   2
         / \ / \       / \ / \
        1  3 6  9     9  6 3  1

    Time:  O(n)
    Space: O(h) — recursion stack, where h = height
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

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;

    // Swap left and right subtrees
    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}

// ─── Helper: level order print ────────────────────────────────────

void printLevelOrder(TreeNode* root) {
    if (!root) { cout << "(empty)" << endl; return; }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            cout << node->val << " ";
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << "| ";
    }
    cout << endl;
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(4,
        new TreeNode(2, new TreeNode(1), new TreeNode(3)),
        new TreeNode(7, new TreeNode(6), new TreeNode(9)));

    cout << "Original:  ";
    printLevelOrder(root);

    invertTree(root);

    cout << "Inverted:  ";
    printLevelOrder(root);

    freeTree(root);
    return 0;
}
