/*
    Kth Smallest Element in a BST (LeetCode 230)

    Given a BST, find the kth smallest element (1-indexed).

    Approach:
    - In-order traversal of a BST visits nodes in ascending order.
    - Count nodes visited; when count == k, that's the answer.
    - Early termination once found.

    Example:
            5
           / \
          3   6
         / \
        2   4
       /
      1

    k=3 → answer = 3

    Time:  O(h + k)
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

void inorder(TreeNode* root, int k, int& count, int& result) {
    if (!root || count >= k) return;

    inorder(root->left, k, count, result);

    count++;
    if (count == k) {
        result = root->val;
        return;
    }

    inorder(root->right, k, count, result);
}

int kthSmallest(TreeNode* root, int k) {
    int count = 0, result = -1;
    inorder(root, k, count, result);
    return result;
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(5,
        new TreeNode(3,
            new TreeNode(2, new TreeNode(1), nullptr),
            new TreeNode(4)),
        new TreeNode(6));

    for (int k = 1; k <= 6; k++) {
        cout << "k=" << k << " → " << kthSmallest(root, k) << endl;
    }
    // k=1→1, k=2→2, k=3→3, k=4→4, k=5→5, k=6→6

    freeTree(root);
    return 0;
}
