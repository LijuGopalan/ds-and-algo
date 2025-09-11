/*
    Path With Given Sequence

    Problem Statement:
    Given a binary tree and a sequence, find if the sequence is present as a
    root-to-leaf path in the tree. A root-to-leaf path is a path starting from
    the root and ending at any leaf node.

    Example 1:
    Sequence: [1, 9, 9]
    Tree:
        1
       / \
      7   9
         / \
        2   9
    Output: true
    Explanation: The tree has a path 1 -> 9 -> 9.

    Example 2:
    Sequence: [1, 0, 7]
    (Same tree as above)
    Output: false
    Explanation: The tree does not have a root-to-leaf path 1 -> 0 -> 7.
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

/**
 * @brief Recursively checks if a path matching the sequence exists.
 *
 * @param currentNode The current node in the traversal.
 * @param sequence The sequence of values to find.
 * @param sequenceIndex The current index in the sequence to match.
 * @return True if a valid root-to-leaf path is found, false otherwise.
 */
bool findPathRecursive(Node* currentNode, const std::vector<int>& sequence, int sequenceIndex) {
    if (!currentNode) {
        return false;
    }

    // Check if we are within the sequence bounds and if the node value matches
    if (sequenceIndex >= sequence.size() || currentNode->val != sequence[sequenceIndex]) {
        return false;
    }

    // If it's a leaf node, check if we have also reached the end of the sequence
    if (currentNode->left == nullptr && currentNode->right == nullptr && sequenceIndex == sequence.size() - 1) {
        return true;
    }

    // Recursively call for the left and right children with the next index
    return findPathRecursive(currentNode->left, sequence, sequenceIndex + 1) ||
           findPathRecursive(currentNode->right, sequence, sequenceIndex + 1);
}

/**
 * @brief Finds if a given sequence exists as a root-to-leaf path in the binary tree.
 *
 * This function serves as a wrapper to start the recursive DFS process from the root
 * of the tree and the beginning of the sequence.
 *
 * @param root A pointer to the root of the binary tree.
 * @param sequence A constant reference to the vector of integers representing the sequence.
 * @return True if the path exists, false otherwise.
 */
bool findPath(Node* root, const std::vector<int>& sequence) {
    if (!root) {
        return sequence.empty();
    }
    return findPathRecursive(root, sequence, 0);
}

/**
 * @brief Main function to test the findPath function.
 * @return 0 on successful execution.
 */
int main() {
    Node* root = new Node(1);
    root->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(2);
    root->right->right = new Node(9);

    std::vector<int> sequence1 = {1, 9, 9};
    std::cout << "Path [1, 9, 9] exists? " << (findPath(root, sequence1) ? "true" : "false") << std::endl; // Expected: true

    std::vector<int> sequence2 = {1, 7};
    std::cout << "Path [1, 7] exists? " << (findPath(root, sequence2) ? "true" : "false") << std::endl; // Expected: true

    std::vector<int> sequence3 = {1, 9, 5};
    std::cout << "Path [1, 9, 5] exists? " << (findPath(root, sequence3) ? "true" : "false") << std::endl; // Expected: false

    std::vector<int> sequence4 = {1, 9}; // Not a root-to-leaf path
    std::cout << "Path [1, 9] exists? " << (findPath(root, sequence4) ? "true" : "false") << std::endl; // Expected: false

    // Note: In a real application, you would need to deallocate the tree nodes.
    return 0;
}