/*
    Connect Level Order Siblings — Next Right Pointer (LeetCode 116 / 117)

    Given a binary tree, populate each node's `next` pointer to point
    to its next right node on the same level. If there is no next right node,
    set `next` to nullptr.

    Approach:
    - BFS with a queue.
    - For each level, chain nodes using a `prev` pointer.
    - The last node in each level points to nullptr.

    Example:
            1 -> null
           / \
          2 -> 3 -> null
         / \    \
        4-> 5 -> 7 -> null

    Time:  O(n)
    Space: O(n) — queue holds at most one level
*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;  // pointer to next sibling on same level

    TreeNode(int v) : val(v), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r)
        : val(v), left(l), right(r), next(nullptr) {}
};

void connectNextPointers(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        TreeNode* prev = nullptr;

        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front(); q.pop();

            if (prev) prev->next = curr;
            prev = curr;

            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        prev->next = nullptr;  // last node in level
    }
}

// Print using next pointers — no queue needed (proves they work)
void printUsingNextPointers(TreeNode* root) {
    TreeNode* levelStart = root;
    while (levelStart) {
        TreeNode* curr = levelStart;
        while (curr) {
            cout << curr->val;
            cout << (curr->next ? " -> " : " -> null");
            curr = curr->next;
        }
        cout << endl;

        // Move to next level: find leftmost child
        TreeNode* nextLevel = nullptr;
        curr = levelStart;
        while (curr && !nextLevel) {
            if (curr->left)       nextLevel = curr->left;
            else if (curr->right) nextLevel = curr->right;
            curr = curr->next;
        }
        levelStart = nextLevel;
    }
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(1,
        new TreeNode(2,
            new TreeNode(4),
            new TreeNode(5)),
        new TreeNode(3,
            nullptr,
            new TreeNode(7)));

    connectNextPointers(root);

    cout << "Level order using next pointers:" << endl;
    printUsingNextPointers(root);

    freeTree(root);
    return 0;
}
