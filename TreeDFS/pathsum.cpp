/*
    Path Sum

    Problem Statement:
    Given a binary tree and a number ‘S’, find if the tree has a path from
    root-to-leaf such that the sum of all the node values of that path equals ‘S’.

    Example:
    S = 22,
                  5
                 / \
                4   8
               /   / \
              11  13  4
             /  \      \
            7    2      1

    Output: true
    Explanation: The path 5 -> 4 -> 11 -> 2 has a sum of 22.
*/

#include <iostream>

// Definition for a binary tree node.
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * @brief Checks if there is a root-to-leaf path with a given sum.
 *
 * This function uses a recursive Depth-First Search (DFS) approach. It subtracts the
 * current node's value from the required sum and recursively calls itself for its
 * children. The base case is reaching a leaf node, where it checks if the node's
 * value equals the remaining required sum.
 *
 * @param root A pointer to the root of the binary tree.
 * @param sum The target sum to check for.
 * @return True if a root-to-leaf path with the given sum exists, false otherwise.
 */
bool hasPathSum(Node* root, int sum) {
    if (!root) {
        return false;
    }

    // If it's a leaf node, check if its value equals the remaining sum
    if (root->left == nullptr && root->right == nullptr) {
        return root->val == sum;
    }

    // Recursively check the left and right subtrees with the updated sum
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

/**
 * @brief Main function to test the hasPathSum function.
 * @return 0 on successful execution.
 */
int main() {
    // Creating a sample binary tree
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->right = new Node(1);

    int sum1 = 22;
    std::cout << "Tree has path with sum " << sum1 << "? " << (hasPathSum(root, sum1) ? "true" : "false") << std::endl; // Expected: true

    int sum2 = 26;
    std::cout << "Tree has path with sum " << sum2 << "? " << (hasPathSum(root, sum2) ? "true" : "false") << std::endl; // Expected: true (5->8->13)

    int sum3 = 100;
    std::cout << "Tree has path with sum " << sum3 << "? " << (hasPathSum(root, sum3) ? "true" : "false") << std::endl; // Expected: false

    // Note: In a real application, you would need to deallocate the tree nodes.
    return 0;
}