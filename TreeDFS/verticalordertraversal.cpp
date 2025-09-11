/*
    Vertical Order Traversal of a Binary Tree (Simplified)

    Problem Statement:
    Given the root of a binary tree, return the vertical order traversal of its nodes' values.
    For each column index from left to right, list the node values from top to bottom.

    Note: This is a simplified version of the problem. The standard version on platforms
    like LeetCode (e.g., problem 987) has an additional requirement: if two nodes are in
    the same row and column, they must be ordered by their values. This implementation
    does not handle that specific sorting rule and groups nodes only by column based on
    a pre-order traversal.

    Example:
    Input:
        3
       / \
      9  20
        /  \
       15   7
    Output:
    [
      [9],
      [3, 15],
      [20],
      [7]
    ]
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * @brief Performs a DFS traversal to group nodes by their vertical column.
 *
 * This recursive function traverses the tree (pre-order) and populates a map where the
 * key is the horizontal distance (column index) from the root, and the value is a
 * vector of node values found at that column.
 *
 * @param root The current node in the traversal.
 * @param col The column index of the current node.
 * @param m A reference to the map that stores the vertical order.
 */
void getVerticalOrder(TreeNode* root, int col, std::map<int, std::vector<int>>& m) {
    if (!root) {
        return;
    }
    m[col].push_back(root->val);
    getVerticalOrder(root->left, col - 1, m);
    getVerticalOrder(root->right, col + 1, m);
}

/**
 * @brief Returns the vertical order traversal of a binary tree (simplified version).
 *
 * This function initiates a DFS traversal to group nodes by their vertical column index
 * and then converts the resulting map into a 2D vector.
 *
 * @param root A pointer to the root of the binary tree.
 * @return A 2D vector representing the vertical order traversal.
 */
std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
    std::map<int, std::vector<int>> m;
    getVerticalOrder(root, 0, m);

    std::vector<std::vector<int>> result;
    for (auto const& [col, val_vec] : m) {
        result.push_back(val_vec);
    }
    return result;
}

/**
 * @brief Prints the 2D vector result of the vertical traversal.
 * @param result A vector of vectors representing the vertical order.
 */
void printResult(const std::vector<std::vector<int>>& result) {
    std::cout << "[" << std::endl;
    for (const auto& col : result) {
        std::cout << "  [";
        for (int i = 0; i < col.size(); ++i) {
            std::cout << col[i] << (i == col.size() - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Main function to test the verticalTraversal function.
 * @return 0 on successful execution.
 */
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::cout << "Performing vertical order traversal..." << std::endl;
    std::vector<std::vector<int>> result = verticalTraversal(root);
    printResult(result);

    // Note: In a real application, you would need to deallocate the tree nodes.
    return 0;
}