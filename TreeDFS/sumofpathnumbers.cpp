/*
    Sum Root to Leaf Numbers

    Problem Statement:
    You are given the root of a binary tree containing digits from 0 to 9 only.
    Each root-to-leaf path in the tree represents a number. For example, the
    root-to-leaf path 1 -> 2 -> 3 represents the number 123.
    Return the total sum of all root-to-leaf numbers.

    Example 1:
    Input:
        1
       / \
      2   3
    Output: 25
    Explanation:
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.
    Therefore, sum = 12 + 13 = 25.

    Example 2:
    Input:
        4
       / \
      9   0
     / \
    5   1
    Output: 1026
    Explanation:
    The root-to-leaf path 4->9->5 represents the number 495.
    The root-to-leaf path 4->9->1 represents the number 491.
    The root-to-leaf path 4->0 represents the number 40.
    Therefore, sum = 495 + 491 + 40 = 1026.
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
 * @brief Recursively calculates the sum of all root-to-leaf numbers.
 *
 * This function performs a DFS traversal. It builds the number represented by the
 * current path by passing down the `currentSum`. When a leaf node is reached,
 * the full number for that path is returned. For non-leaf nodes, it returns the
 * sum of the results from its left and right subtrees.
 *
 * @param currentNode The current node in the traversal.
 * @param currentSum The number formed by the path from the root to the parent of the current node.
 * @return The sum of all numbers formed by root-to-leaf paths in the subtree of the current node.
 */
int sumNumbersRecursive(Node* currentNode, int currentSum) {
    if (!currentNode) {
        return 0;
    }

    // Calculate the number represented by the path to this node
    currentSum = currentSum * 10 + currentNode->val;

    // If it's a leaf node, we have a complete number, so return it
    if (currentNode->left == nullptr && currentNode->right == nullptr) {
        return currentSum;
    }

    // Otherwise, return the sum of numbers from left and right subtrees
    return sumNumbersRecursive(currentNode->left, currentSum) +
           sumNumbersRecursive(currentNode->right, currentSum);
}

/**
 * @brief Calculates the total sum of all root-to-leaf numbers.
 *
 * This function serves as a wrapper to start the recursive DFS process.
 *
 * @param root A pointer to the root of the binary tree.
 * @return The total sum of all root-to-leaf numbers.
 */
int sumNumbers(Node* root) {
    return sumNumbersRecursive(root, 0);
}

/**
 * @brief Main function to test the sumNumbers function.
 * @return 0 on successful execution.
 */
int main() {
    // Example 1: Tree = [1, 2, 3]
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    std::cout << "Tree: [1, 2, 3]" << std::endl;
    std::cout << "Sum of root-to-leaf numbers: " << sumNumbers(root1) << std::endl; // Expected: 25
    std::cout << "--------------------" << std::endl;

    // Example 2: Tree = [4, 9, 0, 5, 1]
    Node* root2 = new Node(4);
    root2->left = new Node(9);
    root2->right = new Node(0);
    root2->left->left = new Node(5);
    root2->left->right = new Node(1);
    std::cout << "Tree: [4, 9, 0, 5, 1]" << std::endl;
    std::cout << "Sum of root-to-leaf numbers: " << sumNumbers(root2) << std::endl; // Expected: 1026
    std::cout << "--------------------" << std::endl;

    // Note: In a real application, you would need to deallocate the tree nodes.
    return 0;
}