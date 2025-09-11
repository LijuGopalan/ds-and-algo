/*
    Clone Graph

    Problem Statement:
    Given a reference to a node in a connected undirected graph, return a deep copy (clone)
    of the graph. Each node in the graph contains a value (int) and a list of its neighbors.

    Example:
    Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
    (Represents a graph with 4 nodes)
    Output: [[2,4],[1,3],[2,4],[1,3]]
    Explanation: A deep copy of the graph is returned.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue> // For printing the graph

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node(int _val) : val(_val) {}
};

/**
 * @brief Recursively clones a graph using Depth-First Search (DFS).
 *
 * This is a helper function that performs the actual cloning. It uses a map to keep
 * track of already cloned nodes to handle cycles and avoid redundant cloning.
 *
 * @param node The current node from the original graph to clone.
 * @param visitedMap A map from original nodes to their cloned counterparts.
 * @return A pointer to the cloned node.
 */
Node* cloneGraphRecursive(Node* node, std::unordered_map<Node*, Node*>& visitedMap) {
    if (!node) {
        return nullptr;
    }

    // If the node has already been cloned, return the cloned version
    if (visitedMap.count(node)) {
        return visitedMap[node];
    }

    // Create a new node with the same value
    Node* cloneNode = new Node(node->val);
    // Add the new node to the visited map
    visitedMap[node] = cloneNode;

    // Recursively clone all the neighbors
    for (Node* neighbor : node->neighbors) {
        cloneNode->neighbors.push_back(cloneGraphRecursive(neighbor, visitedMap));
    }

    return cloneNode;
}

/**
 * @brief Clones a graph.
 *
 * This function serves as a wrapper to initiate the graph cloning process.
 * It sets up the necessary data structures for the recursive helper function.
 *
 * @param node A pointer to any node in the graph to be cloned.
 * @return A pointer to the corresponding node in the deep-copied graph.
 */
Node* cloneGraph(Node* node) {
    std::unordered_map<Node*, Node*> visitedMap;
    return cloneGraphRecursive(node, visitedMap);
}

/**
 * @brief Prints a graph level by level starting from a given node.
 * @param startNode The node to start the traversal from.
 * @param graphName A name for the graph to be printed in the header.
 */
void printGraph(Node* startNode, const std::string& graphName) {
    if (!startNode) return;

    std::cout << "--- " << graphName << " ---" << std::endl;
    std::unordered_map<Node*, bool> visited;
    std::queue<Node*> q;

    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        Node* u = q.front();
        q.pop();
        std::cout << "Node " << u->val << " (at " << u << ") neighbors: ";
        for (Node* v : u->neighbors) {
            std::cout << v->val << " (at " << v << ") ";
            if (!visited.count(v)) {
                visited[v] = true;
                q.push(v);
            }
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Main function to test the cloneGraph function.
 * @return 0 on successful execution.
 */
int main() {
    // Build a sample graph: 1--2--3--4--1 (a cycle)
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);

    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);

    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);

    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    printGraph(node1, "Original Graph");

    // Clone the graph
    Node* clonedNode1 = cloneGraph(node1);

    printGraph(clonedNode1, "Cloned Graph");

    // Note: In a real application, you would need to deallocate all nodes
    // in both the original and cloned graphs to prevent memory leaks.

    return 0;
}
 


