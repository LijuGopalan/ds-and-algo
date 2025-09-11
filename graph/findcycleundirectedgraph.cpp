/*
    Detect Cycle in an Undirected Graph

    Problem Statement:
    Given an undirected graph with V vertices and E edges, check whether it contains any cycle.

    Algorithm Description:
    This solution uses Depth First Search (DFS) to detect cycles. For an undirected graph,
    we can detect a cycle if we encounter a visited vertex that is not the immediate parent
    of the current vertex in the DFS tree. A `parent` parameter is passed during the
    recursive DFS calls to keep track of the node from which the current node was visited.

    Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
    Space Complexity: O(V) for the visited array and recursion stack.
*/

#include <iostream>
#include <vector>

/**
 * @brief Helper function to detect a cycle in a subgraph using DFS.
 *
 * @param node The current vertex being visited.
 * @param parent The parent vertex in the DFS traversal tree.
 * @param adj The adjacency list representation of the graph.
 * @param visited A boolean vector to keep track of visited vertices.
 * @return True if a cycle is detected in the subgraph, false otherwise.
 */
bool dfs(int node, int parent, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited)) return true;
        } else if (neighbor != parent) {
            // If an adjacent vertex is visited and is not the parent, a cycle is found.
            return true;
        }
    }
    
    return false;
}

/**
 * @brief Checks if an undirected graph contains a cycle.
 *
 * This function handles disconnected graphs by iterating through all vertices and
 * starting a DFS traversal from each unvisited vertex.
 *
 * @param n The number of vertices in the graph.
 * @param edges A 2D vector representing the edges of the graph.
 * @return True if the graph contains a cycle, false otherwise.
 */
bool hasCycle(int n, const std::vector<std::vector<int>>& edges) {
    if (n <= 0) {
        return false;
    }
    std::vector<std::vector<int>> adj(n);
    std::vector<bool> visited(n, false);
    
    // Build adjacency list
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    // Check for cycles in all components of the graph
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) return true;
        }
    }
    
    return false;
}

/**
 * @brief Main function to test the hasCycle function.
 * @return 0 on successful execution.
 */
int main() {
    // Example 1: Graph with a cycle
    int n1 = 5;
    std::vector<std::vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {3, 4}};
    std::cout << "Graph 1 (with cycle): ";
    std::cout << (hasCycle(n1, edges1) ? "Cycle detected" : "No cycle found") << " (Expected: Cycle detected)" << std::endl;

    // Example 2: Graph without a cycle (a tree)
    int n2 = 4;
    std::vector<std::vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}};
    std::cout << "Graph 2 (no cycle): ";
    std::cout << (hasCycle(n2, edges2) ? "Cycle detected" : "No cycle found") << " (Expected: No cycle found)" << std::endl;
    
    return 0;
}