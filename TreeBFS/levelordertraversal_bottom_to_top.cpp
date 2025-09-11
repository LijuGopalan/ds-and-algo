
/*
    Binary Tree Level Order Traversal II (Bottom-up)

    Problem Statement:
    Given a binary tree, return the bottom-up level order traversal of its nodes' values.
    (i.e., from left to right, level by level from leaf to root).

    Example:
    Given binary tree [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    return its bottom-up level order traversal as:
    [
      [15,7],
      [9,20],
      [3]
    ]
*/

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm> // For std::reverse if needed, though deque is used here

// Definition for a binary tree node.
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * @brief Performs a bottom-up level order traversal of a binary tree.
 *
 * This function traverses the tree level by level using Breadth-First Search (BFS).
 * The node values for each level are stored in a temporary vector. This vector is then
 * pushed to the front of a deque, which efficiently reverses the order of the levels.
 *
 * @param root A pointer to the root of the binary tree.
 * @return A deque of vectors, where each inner vector contains the node values of a level,
 *         ordered from the leaf level to the root level.
 */
std::deque<std::vector<int>> levelOrderBottom(Node* root) {
    std::deque<std::vector<int>> result;
    if (!root) {
        return result;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        std::vector<int> currentLevel;
        currentLevel.reserve(levelSize);

        for (int i = 0; i < levelSize; ++i) {
            Node* n = q.front();
            q.pop();
            currentLevel.push_back(n->val);

            if (n->left) {
                q.push(n->left);
            }
            if (n->right) {
                q.push(n->right);
            }
        }
        // Add the level at the beginning of the result deque
        result.push_front(currentLevel);
    }

    return result;
}

/**
 * @brief Prints the result of the bottom-up traversal.
 * @param result A deque of vectors representing the levels of the tree.
 */
void printResult(const std::deque<std::vector<int>>& result) {
    std::cout << "[" << std::endl;
    for (const auto& level : result) {
        std::cout << "  [";
        for (int i = 0; i < level.size(); ++i) {
            std::cout << level[i] << (i == level.size() - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Main function to build a tree and test the levelOrderBottom function.
 * @return 0 on successful execution.
 */
int main() {
    // Creating a sample binary tree: [3,9,20,null,null,15,7]
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    std::cout << "Performing bottom-up level order traversal..." << std::endl;
    std::deque<std::vector<int>> result = levelOrderBottom(root);

    std::cout << "Result:" << std::endl;
    printResult(result);

    // Note: In a real application, you would need to delete the allocated nodes.
    return 0;
}