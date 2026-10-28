/*
    Flatten Binary Tree to Linked List (LeetCode 114)

    Given the root of a binary tree, flatten it into a "linked list"
    in-place, using the right pointer as next and left as nullptr.
    The order should follow a pre-order traversal.

    Example:
        Input:              Output (as linked list):
            1               1
           / \               \
          2   5               2
         / \   \               \
        3   4   6               3
                                 \
                                  4
                                   \
                                    5
                                     \
                                      6

    Approach (Reverse Postorder — right, left, root):
    - Process right subtree, then left subtree, then current node.
    - Maintain a `prev` pointer to the previously processed node.
    - Set current->right = prev, current->left = nullptr.
    - This naturally builds the flattened list from tail to head.

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

TreeNode* prev_node = nullptr;

void flatten(TreeNode* root) {
    if (!root) return;

    flatten(root->right);
    flatten(root->left);

    root->right = prev_node;
    root->left = nullptr;
    prev_node = root;
}

void printFlattened(TreeNode* root) {
    while (root) {
        cout << root->val;
        if (root->right) cout << " -> ";
        root = root->right;
    }
    cout << endl;
}

void freeList(TreeNode* root) {
    while (root) {
        TreeNode* next = root->right;
        delete root;
        root = next;
    }
}

int main() {
    TreeNode* root = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(5, nullptr, new TreeNode(6)));

    prev_node = nullptr;  // reset global
    flatten(root);

    cout << "Flattened: ";
    printFlattened(root);  // 1 -> 2 -> 3 -> 4 -> 5 -> 6

    freeList(root);
    return 0;
}
