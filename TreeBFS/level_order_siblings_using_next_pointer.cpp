/*
    Connect Level Order Siblings using Next Pointer

    Problem Statement:
    Given a binary tree, populate each next pointer to point to its next right node.
    If there is no next right node, the next pointer should be set to NULL.
    Initially, all next pointers are set to NULL.

    This problem is also known as "Populating Next Right Pointers in Each Node".

    Example:
    Input:
         1
       /  \
      2    3
     / \  / \
    4  5  6  7

    Output:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

#include <iostream>
#include <queue>

// Definition for a binary tree node with a next pointer.
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

/**
 * @brief Populates the `next` pointer for each node to its next right node in the same level.
 *
 * This function uses Breadth-First Search (BFS) to traverse the tree level by level.
 * For each level, it iterates through the nodes, connecting each node to the next one
 * in the queue. The last node of each level has its `next` pointer set to nullptr.
 *
 * @param root A pointer to the root of the binary tree.
 */
void connect(Node* root) {
    if (!root) {
        return;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        Node* previousNode = nullptr;

        // Iterate over all nodes in the current level
        for (int i = 0; i < levelSize; ++i) {
            Node* currentNode = q.front();
            q.pop();

            // Connect the previous node in this level to the current one
            if (previousNode) {
                previousNode->next = currentNode;
            }
            previousNode = currentNode;

            // Add children to the queue for the next level
            if (currentNode->left) {
                q.push(currentNode->left);
            }
            if (currentNode->right) {
                q.push(currentNode->right);
            }
        }
        // The last node of the level points to null (already handled by initialization)
    }
}

/**
 * @brief Prints the tree level by level using the `next` pointers to verify the connections.
 *
 * It traverses down the leftmost nodes to find the start of each level, then
 * traverses across the level using the `next` pointers.
 *
 * @param root A pointer to the root of the connected binary tree.
 */
void printLevels(Node* root) {
    Node* levelStart = root;
    while (levelStart) {
        Node* current = levelStart;
        while (current) {
            std::cout << current->val << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
        levelStart = levelStart->left; // Move to the start of the next level
    }
}

/**
 * @brief Main function to build a tree, connect its nodes, and print the result.
 * @return 0 on successful execution.
 */
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    std::cout << "Connecting nodes..." << std::endl;
    connect(root);

    std::cout << "Printing levels using next pointers:" << std::endl;
    printLevels(root);

    // Note: In a real application, you would need to delete the allocated nodes
    // to prevent memory leaks. This is omitted for simplicity in this example.

    return 0;
}