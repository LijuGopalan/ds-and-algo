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

 
    
    bool iscycle(vector<vector<int>>& g, vector<bool>& v, vector<bool>& loop, int vertex) {
    
      if(loop[vertex]) {
        return true;
      }
    
      v[vertex] = true;
      loop[vertex] = true;
    
      for(int ver : g[vertex] ) {
    
          if(loop[ver]) {
            return true;
          } else if(!v[ver] && iscycle(g,v,loop,ver)) {
            return true;
          }
    
      }
    
      loop[vertex] = false;
      return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
      if(numCourses < 1 || prerequisites.size() < 1 )
        return false;
    
      //create a graph. 
      vector<vector<int>> g(numCourses); 
      for (vector<int> t : prerequisites) {
        g[t[0]].push_back(t[1]);
      }
    
      vector<bool> visited;
      vector<bool> dfsloop;
    
      for(int i=0;i<numCourses; i++) {
    
        if(!visited[i] && !iscycle(g,visited,dfsloop,i)) { 
          return false;
        }
    
      }
    
      return true;
    
     
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
