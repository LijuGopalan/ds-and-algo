/*

    *  findcycleundirectedgraph.cpp
    *  Detect cycle in an undirected graph using DFS
    *  This code uses Depth First Search (DFS) to detect cycles in an undirected graph.
    *          It builds an adjacency list from the edges and checks for cycles. 
*/   

 
 

@include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited)) return true;
        } else if (neighbor != parent) {
            return true;  // Found a cycle
        }
    }
    
    return false;
}

bool hasCycle(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    
    // Build adjacency list
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);  // Because it's **undirected**
    }
    
    // Check for cycles
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) return true;
        }
    }
    
    return false;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {3, 4}};
    
    cout << (hasCycle(n, edges) ? "Cycle detected" : "No cycle found") << endl;
    return 0;
}