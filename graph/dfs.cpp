

/*
    Depth-First Search (DFS) for Graph Traversal

    This file demonstrates two common implementations of the Depth-First Search (DFS)
    algorithm for traversing a graph:
    1. A recursive approach (`dfsRecursive`).
    2. An iterative approach using a stack (`dfsIterative`).

    Algorithm Description:
    DFS is an algorithm for traversing or searching tree or graph data structures.
    The algorithm starts at the root node (or an arbitrary node in a graph) and
    explores as far as possible along each branch before backtracking.

    Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
    Space Complexity:
    - Recursive: O(H) where H is the maximum height of the tree (or depth of the recursion),
      which can be O(V) in the worst case (for a skewed graph).
    - Iterative: O(V) for the stack and visited array.
*/

#include <iostream>
#include <vector>
#include <stack>

/**
 * @brief Adds an undirected edge between two vertices in the graph.
 *
 * @param adj The adjacency list of the graph.
 * @param u The first vertex.
 * @param v The second vertex.
 */
void addEdge(std::vector<std::vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // For an undirected graph
}

/**
 * @brief Prints the adjacency list representation of the graph.
 *
 * @param adj The adjacency list of the graph.
 */
void printGraph(const std::vector<std::vector<int>>& adj) {
    for (int i = 0; i < adj.size(); ++i) {
        std::cout << "Adjacency list of vertex " << i << ": ";
        for (int neighbor : adj[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Performs a recursive DFS traversal starting from a given vertex.
 *
 * @param adj The adjacency list of the graph.
 * @param v The starting vertex for the DFS.
 * @param visited A boolean vector to keep track of visited vertices.
 */
void dfsRecursive(const std::vector<std::vector<int>>& adj, int v, std::vector<bool>& visited) {
    // Mark the current node as visited and print it
    visited[v] = true;
    std::cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            dfsRecursive(adj, neighbor, visited);
        }
    }
}

/**
 * @brief Performs an iterative DFS traversal using a stack, starting from vertex 0.
 *
 * @param adj The adjacency list of the graph.
 */
void dfsIterative(const std::vector<std::vector<int>>& adj) {
    std::stack<int> s;
    std::vector<bool> visited(adj.size(), false);

    // Start from vertex 0
    s.push(0);

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        if (!visited[u]) {
            visited[u] = true;
            std::cout << u << " ";

            // Push all adjacent vertices to the stack.
            // Note: To mimic the recursive call order, push neighbors in reverse order.
            for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
    }
}

/**
 * @brief Main function to create a graph and test DFS traversals.
 * @return 0 on successful execution.
 */
int main() {
    int n = 5; // Number of vertices
    std::vector<std::vector<int>> adj(n);

    // Add edges to create a sample graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    std::cout << "Graph representation:" << std::endl;
    printGraph(adj);

    std::cout << "\nRecursive DFS starting from vertex 0: ";
    std::vector<bool> visited(n, false);
    dfsRecursive(adj, 0, visited);
    std::cout << std::endl;

    std::cout << "\nIterative DFS starting from vertex 0: ";
    dfsIterative(adj);
    std::cout << std::endl;

    return 0;
}