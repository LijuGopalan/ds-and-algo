/*
    Path Sum II

    Problem Statement:
    Given a binary tree and a number ‘S’, find all paths from root-to-leaf
    such that the sum of all the node values of each path equals ‘S’.

    Example:
    S = 22,
                  5
                 / \
                4   8
               /   / \
              11  13  4
             /  \    / \
            7    2  5   1

    Output:
    [
      [5, 4, 11, 2],
      [5, 8, 4, 5]
    ]
*/

#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void findPathsRecursive(Node* currentNode, int requiredSum, std::vector<int>& currentPath, std::vector<std::vector<int>>& allPaths) {
    if (!currentNode) {
        return;
    }

    // Add the current node to the path
    currentPath.push_back(currentNode->val);

    // Check if it's a leaf node and the sum matches
    if (currentNode->left == nullptr && currentNode->right == nullptr && currentNode->val == requiredSum) {
        allPaths.push_back(currentPath);
    } else {
        // Recurse for left and right children
        findPathsRecursive(currentNode->left, requiredSum - currentNode->val, currentPath, allPaths);
        findPathsRecursive(currentNode->right, requiredSum - currentNode->val, currentPath, allPaths);
    }

    // Backtrack: remove the current node from the path to explore other branches
    currentPath.pop_back();
}

/**
 * @brief Finds all root-to-leaf paths in a binary tree that sum up to a given value.
 *
 * This function serves as a wrapper to initialize the recursive search for paths.
 * It uses a helper function `findPathsRecursive` that performs a Depth-First Search (DFS)
 * to explore all paths.
 *
 * @param root A pointer to the root of the binary tree.
 * @param sum The target sum for the paths.
 * @return A vector of vectors, where each inner vector represents a root-to-leaf path
 *         that sums to the target value.
 */
std::vector<std::vector<int>> findPaths(Node* root, int sum) {
    std::vector<std::vector<int>> allPaths;
    std::vector<int> currentPath;
    findPathsRecursive(root, sum, currentPath, allPaths);
    return allPaths;
}

/**
 * @brief Prints the found paths.
 * @param allPaths A vector of vectors representing the paths.
 */
void printResult(const std::vector<std::vector<int>>& allPaths) {
    for (const auto& path : allPaths) {
        std::cout << "[ ";
        for (int num : path) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }
}

/**
 * @brief Main function to test the findPaths function.
 * @return 0 on successful execution.
 */
int main() {
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->left = new Node(5);
    root->right->right->right = new Node(1);

    int sum = 22;
    std::cout << "Finding paths with sum " << sum << "..." << std::endl;
    std::vector<std::vector<int>> result = findPaths(root, sum);
    printResult(result);

    // Note: In a real application, you would need to deallocate the tree nodes.
    return 0;
}