/*
    Binary Tree Zigzag Level Order Traversal

    Problem Statement:
    Given a binary tree, populate an array to represent its zigzag level order traversal.
    You should populate the values of all nodes of the first level from left to right,
    then right to left for the next level, and keep alternating in the same manner for
    the following levels.

    Example:
    Given binary tree [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    return its zigzag level order traversal as:
    [
      [3],
      [20,9],
      [15,7]
    ]
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Definition for a binary tree node.
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * @brief Performs a zigzag level order traversal of a binary tree.
 *
 * This function traverses the tree level by level using Breadth-First Search (BFS).
 * A boolean flag, `leftToRight`, tracks the traversal direction for the current level.
 * The function pre-allocates a vector for the current level and fills it according to
 * the direction: left-to-right for normal levels, and right-to-left for zigzag levels.
 *
 * @param root A pointer to the root of the binary tree.
 * @return A vector of vectors, where each inner vector contains the node values of a level,
 *         arranged in zigzag order.
 */
std::vector<std::vector<int>> zigzagLevelOrder(Node* root) {
    std::vector<std::vector<int>> result;
    if (!root) {
        return result;
    }

    std::queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int levelSize = q.size();
        std::vector<int> currentLevel(levelSize);

        for (int i = 0; i < levelSize; ++i) {
            Node* n = q.front();
            q.pop();

            // Determine the index to place the node value based on the traversal direction
            int index = leftToRight ? i : (levelSize - 1 - i);
            currentLevel[index] = n->val;

            if (n->left) {
                q.push(n->left);
            }
            if (n->right) {
                q.push(n->right);
            }
        }
        result.push_back(currentLevel);
        leftToRight = !leftToRight; // Flip the direction for the next level
    }

    return result;
}

/**
 * @brief Prints the 2D vector result of the zigzag traversal.
 * @param result A vector of vectors representing the levels of the tree.
 */
void printResult(const std::vector<std::vector<int>>& result) {
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
 * @brief Main function to build a tree and test the zigzagLevelOrder function.
 * @return 0 on successful execution.
 */
int main() {
    // Creating a sample binary tree: [3,9,20,null,null,15,7]
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    std::cout << "Performing zigzag level order traversal..." << std::endl;
    std::vector<std::vector<int>> result = zigzagLevelOrder(root);

    std::cout << "Result:" << std::endl;
    printResult(result);

    // Note: In a real application, you would need to delete the allocated nodes.
    return 0;
}

