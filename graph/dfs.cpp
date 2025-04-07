

#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

void addedge(vector<vector<int>>& g, int x, int y) {

  g[x].push_back(y);
  g[y].push_back(x); // comment if not bidirectional
 
}

void printgraph(vector<vector<int>>& g) {

  int index = 0;

  for(vector<int> x : g) {

    cout << "\n vertex " << index << " connected to " ;

    for (int y : x ) {

      cout << y << ' ';

    }
    index++; 

  }

}

void recursivedfs(vector<vector<int>>& g, int vertex, set<int>& visited) {

  if(visited.find(vertex) != visited.end()) {
    return;
  }

    visited.insert(vertex);
    cout << endl <<  "visited " << vertex ;

    for(int v : g[vertex]) {
      // Check if the vertex is already visited
      if(visited.find(v) == visited.end()) {
        // If not, recursively call DFS on the adjacent vertex
        recursivedfs(g,v,visited); 
      }
    } 

  
}


// DFS using stack
// This is an iterative implementation of DFS using a stack.
void dfsusingstack(vector<vector<int>>& g) {

  stack<int> st;
  set<int> visited;

  int root = 0;
  st.push(root);

  while (!st.empty()) {
    
    root = st.top();
    st.pop();
    if(visited.find(root) == visited.end()) {
      
      cout << endl << " visited " << root;
      visited.insert(root);
 
      // Push all adjacent vertices onto the stack in reverse order
      // to maintain the original order of traversal.
      // This is because stacks are LIFO (Last In First Out) structures.  
      for(int i=g[root].size()-1; i>=0 ; i--) {
        st.push(g[root][i]);
      } 
    }
    
  }

}



int main() {

    int n = 5; // Number of nodes
    vector<vector<int>> graph(n); // Create a graph with `n` nodes

    // Add edges (example graph)
    addedge(graph, 0, 1);
    addedge(graph, 0, 4);
    addedge(graph, 1, 2);
    addedge(graph, 1, 3);
    addedge(graph, 1, 4);
    addedge(graph, 2, 3);
    addedge(graph, 3, 4);

    // Print the graph
    printgraph(graph);

    //dfs(graph); // Perform DFS
    set<int> visited;
    recursivedfs(graph, 0, visited); // Perform DFS recursively

    dfsusingstack(graph);
 
    return 0;
}