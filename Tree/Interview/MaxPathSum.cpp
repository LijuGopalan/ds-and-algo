/*
    Binary Tree Maximum Path Sum (LeetCode 124) — HARD

    A path in a binary tree is a sequence of nodes where each pair of
    adjacent nodes has an edge. A path does NOT need to pass through the root.
    Return the maximum path sum of any non-empty path.

    Key insight:
    - At each node, the max "contribution" it can offer to its parent is:
        node->val + max(leftGain, rightGain, 0)
    - But the max path *through* this node (not extending upward) is:
        node->val + leftGain + rightGain
    - We track the global maximum across all nodes.

    Example:
           -10
           / \
          9  20
            /  \
           15   7

    Best path: 15 → 20 → 7 = 42

    Time:  O(n)
    Space: O(h)
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

int maxGain(TreeNode* root, int& globalMax) {
    if (!root) return 0;

    // Max gain from left and right subtrees (ignore negative contributions)
    int leftGain  = max(maxGain(root->left, globalMax), 0);
    int rightGain = max(maxGain(root->right, globalMax), 0);

    // Path through this node (as the "turning point")
    int pathThroughNode = root->val + leftGain + rightGain;
    globalMax = max(globalMax, pathThroughNode);

    // Return max gain this node can contribute to its parent
    return root->val + max(leftGain, rightGain);
}

int maxPathSum(TreeNode* root) {
    int globalMax = INT_MIN;
    maxGain(root, globalMax);
    return globalMax;
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(-10,
        new TreeNode(9),
        new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    cout << "Max Path Sum: " << maxPathSum(root) << endl;  // 42

    // Single negative node
    TreeNode* neg = new TreeNode(-3);
    cout << "Max Path Sum (single -3): " << maxPathSum(neg) << endl;  // -3

    freeTree(root);
    freeTree(neg);
    return 0;
}
