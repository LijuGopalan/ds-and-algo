/*
    Construct Binary Tree from Preorder and Inorder Traversal (LeetCode 105)

    Given two integer arrays `preorder` and `inorder`, construct
    the original binary tree.

    Key Insight:
    - preorder[0] is always the root.
    - Find root in inorder → everything to its left is left subtree,
      everything to its right is right subtree.
    - Use a hash map for O(1) lookup in inorder.

    Example:
    Preorder: [3, 9, 20, 15, 7]
    Inorder:  [9, 3, 15, 20, 7]

    Output:
            3
           / \
          9  20
            /  \
           15   7

    Time:  O(n)
    Space: O(n) — hash map + recursion
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution
{
    unordered_map<int, int> inorderIndex;
    int preIdx = 0;

public:
    TreeNode *build(vector<int> &preorder, int left, int right)
    {
        if (left > right)
            return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode *root = new TreeNode(rootVal);

        int mid = inorderIndex[rootVal]; // root's position in inorder
        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < (int)inorder.size(); i++)
        {
            inorderIndex[inorder[i]] = i;
        }
        preIdx = 0;
        return build(preorder, 0, (int)inorder.size() - 1);
    }
};

void printLevelOrder(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout << "| ";
    }
    cout << endl;
}

void freeTree(TreeNode *root)
{
    if (!root)
        return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);

    cout << "Constructed tree (level order): ";
    printLevelOrder(root); // 3 | 9 20 | 15 7 |

    freeTree(root);
    return 0;
}
