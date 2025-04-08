#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

/*
  Given a binary tree and a number ‘S’, 
  find if the tree has a path from root-to-leaf such that the sum of all the node values of that path equals ‘S’.
*/


class Node {

    public:
      int val;
      Node *left; 
      Node *right;
    
      Node(int v, Node* l, Node* r) {
    
        val = v;
        left = l; 
        right = r;
    
      }
    
};
 
int sumofpath(Node* root,  int totalsum) {

  if(root == NULL) 
    return 0;

  totalsum = totalsum*10+root->val;

  //a full path reached. time to create the current path sum
  if(root->left == NULL && root->right == NULL) {
    return totalsum ;
  }

  return sumofpath(root->left,totalsum)+ sumofpath(root->right,totalsum);

}
 


int main() {
  
    Node* node3 = new Node(3,NULL,NULL);
    Node* node2 = new Node(2,node3,NULL);
    Node* node1 = new Node(1,node2,NULL);

    cout << " sum of path " << sumofpath(node1,0);
    return 0;

}