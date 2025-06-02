/*

Given a binary tree and a number ‘S’, find all paths from root-to-leaf such that the sum of all the node values of each path equals ‘S’.


*/

#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {

public:

  int val;
  Node* left;
  Node* right;

    Node(int v, Node* x, Node* y) {
      left =x;
       right = y;
      val = v;
    }

};


// Function to find all paths from root to leaf with a given sum
// and store them in the result vector
// currentpath is used to store the current path being explored
// sum is the remaining sum we need to find in the current path
// result is a vector of vectors that will store all valid paths
// The function uses depth-first search (DFS) to explore all paths in the tree
// If a leaf node is reached and the sum matches, the current path is added to the result
// After exploring a path, the function backtracks by popping the last element from currentpath
// This allows the function to explore other paths without affecting the current path
// The function handles both left and right children of the current node
// It recursively calls itself for both left and right subtrees, reducing the sum by the value of the current node
// The base case is when the current node is NULL, in which case the function simply returns
// time complexity: O(N), where N is the number of nodes in the tree
// space complexity: O(H), where H is the height of the tree due to recursion stack
void getPaths(Node* root, vector<vector<int>>& result, vector<int> currentpath, int sum) {

  if(root == NULL) {
    return;
  }

  currentpath.push_back(root->val);

  if(root->left == NULL && root->right == NULL && root->val == sum ) {
    //currentpath.push_back(root->val);
    result.push_back(currentpath);
  } 
  
  else {

    getPaths(root->left, result, currentpath, sum-root->val);
    getPaths(root->right, result, currentpath, sum-root->val);

  }

  // Backtrack: remove the last element from currentpath
  // This allows us to explore other paths without affecting the current path
  currentpath.pop_back();
  
}


int main() {

  vector<vector<int>> result;

  
    int sum = 6;

    Node* node5 = new Node(5,NULL,NULL);

    Node* node3 = new Node(3,NULL,NULL);
    Node* node2 = new Node(2,node3,NULL);
    Node* node1 = new Node(1,node2,node5);
 

    getPaths(node1, result, vector<int>(),sum);

    cout << endl << " result " << endl;
    for(vector<int> v : result) {

      cout << " Path : ";
      for(int i: v)
        cout << i << " -> ";
    }


    return 0;
  




  return 1;
}