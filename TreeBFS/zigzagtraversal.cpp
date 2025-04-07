/*
Problem Statement #
Given a binary tree, populate an array to represent its zigzag level order traversal. You should populate the values of all nodes of the first level from left to right, 
then right to left for the next level and keep alternating in the same manner for the following level  

*/


// Time Complexity: O(n) where n is the number of nodes in the tree. We are traversing each node once.
// Space Complexity: O(n) where n is the number of nodes in the tree. We are storing all nodes in the queue at any given time.  

#include <iostream>
#include <string>
#include <vector>
#include <queue>


using namespace std;

class Node {
  public:
    int val;
    Node* left;
    Node* right;

  Node(int v, Node* l, Node* r) {
    val = v;
    left = l;
    right = r;
    
  }
};

// Function to perform zigzag level order traversal of a binary tree   
// Input: root of the binary tree
// Output: 2D vector containing the zigzag level order traversal of the binary tree    
// Example:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Explanation: The first level is [3], the second level is [20,9] and the third level is [15,7].   
// The zigzag level order traversal is [[3],[20,9],[15,7]].
// The first level is traversed from left to right, the second level is traversed from right to left and the third level is traversed from left to right.   
// The zigzag level order traversal is [[3],[20,9],[15,7]].
vector<vector<int>> zigzagLevelOrder(Node* root) {

  if( root == NULL ) {
    return {{}};
  }

  vector<vector<int>> nodes;
  queue<Node*> q;

  q.push(root);

  bool lefttoright = true;

  // this variable is the key player in the zigzag traversal.
  // it will help us to decide to size of the level. 
  int levelsize = 0;
  while(!q.empty()) {

    levelsize = q.size();

    //initializing the vector with the size of the level is the key player in the zigzag traversal.
    // it will help us to insert the elements where we want them to be. ( push_back will not work here in right to left traversal)
    // if we use push_back, the elements will be inserted at the end of the vector and we will not get the zigzag traversal.    
    // we need to insert the elements at the beginning of the vector in right to left traversal.
    // so we need to initialize the vector with the size of the level.
    vector<int> temp(levelsize);

    while(levelsize > 0) { 

      Node* n = q.front();
      q.pop(); 

      if(lefttoright) {
        temp[temp.size()-levelsize] = n->val;
      } else {
        temp[levelsize-1] = n->val; 
      }

   
        if(n->left != NULL) {
          q.push(n->left);
        }

        if(n->right != NULL) {
          q.push(n->right);
        }
 
      levelsize--;

    }
    nodes.push_back(temp);

    lefttoright = !lefttoright;
  }

  return nodes;


}


int main() {

        Node* node40 = new Node(40,NULL,NULL);
    Node* node50 = new Node(50,NULL,NULL);


    Node* node20 = new Node(20,NULL,NULL);
    Node* node30 = new Node(30,NULL,NULL);

    Node* node1 = new Node(15,node20,node30);
    Node* node2 = new Node(7,node40,node50);

    Node* node3 = new Node(20,node1,node2);

    Node* node4 = new Node(9,NULL,NULL);
    Node* node5 = new Node(3,node4,node3);

    vector<vector<int>> r = zigzagLevelOrder(node5);

    cout << " zig zag " << endl ;

    for(vector<int> x : r ) {
      
      cout << endl;
      for( int i: x) {
        cout << i << " ";
      }

    }





  return 0;
}

