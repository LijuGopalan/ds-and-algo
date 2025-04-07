/*

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

*/

#include <iostream>
#include <vector>
using namespace std;
#include <map>        
#include <set>
#include <queue>     


/*

Algorithm Overview
Build a directed graph where each course points to its prerequisites.
Use DFS (Depth-First Search) to detect cycles.
If a cycle is detected, it is impossible to complete all courses → return False.
If no cycle is found, all courses can be taken → return True.

*/



// Function to perform DFS and check for cycles
// in the directed graph represented by the prerequisites
// using a map to store the adjacency list
// and a set to keep track of visited nodes
// The function returns true if a cycle is detected, false otherwise
// The function uses recursion to traverse the graph
// and checks if a node is already visited before visiting it again
bool dfs(map<int,vector<int>>& m, set<int>& visited, int vertex) {

    if(visited.find(vertex) == visited.end()) {

        visited.insert(vertex);
        for(int t : m[vertex]) {
            return dfs(m,visited,t);
        }


    } else {
        return false;
    }

    return true;


}

// Function to check if all courses can be finished
// by performing a DFS on the directed graph represented by the prerequisites  
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
    if(prerequisites.size() < 1 || numCourses < 1) {
        return true;
    }

    map<int,vector<int>> m;

    //create a map with prerequisites
    for(vector<int> pre : prerequisites) { 
        m[pre[0]].push_back(pre[1]); 
    }

    set<int> v;

    numCourses--;
    //check if the graph is cyclic using DFS
    //if it is cyclic, return false 
    while(numCourses >= 0) { 
        return dfs(m,v,numCourses--); 
    }

    return false;


}

 
int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    bool result = canFinish(numCourses, prerequisites);

    if (result) {
        cout << "You can finish all courses." << endl;
    } else {
        cout << "You cannot finish all courses." << endl;
    }
    
      
    return 0;
}
