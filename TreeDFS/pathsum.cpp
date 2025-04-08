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

bool findsum(Node* root, int sum) {

  if(root == NULL)
    return false;

  if(root->val == sum && root->left == NULL && root->right == NULL)
    return true;

  return findsum(root->left, (sum-root->val)) || findsum(root->right, (sum-root->val));
 
}
 


int main() {



    Node* node3 = new Node(3,NULL,NULL);
    Node* node2 = new Node(2,node3,NULL);
    Node* node1 = new Node(1,node2,NULL);
 
 
    cout << endl << " result " << findsum(node1,7) <<endl; 
 
    return 0;
  


}