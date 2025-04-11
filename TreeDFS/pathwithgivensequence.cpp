#include <iostream>
#include <vector>
#include <array>
#include <map>

using namespace std;

// path with given sequence

/*

Sequence: [1, 9, 9]  Output: true Explaination: The tree has a path 1 -> 9 -> 9. 


*/


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


bool dfs(Node* root, vector<int>& s, int i) {

  if(root == NULL)
    return false;

  if(root->val != s[i]) {
    return false;
  }

  if(root->left == NULL && root->right == NULL) {
    return true;
  }
  

  return dfs(root->left,s,i+1) || dfs(root->right, s, i+1);


}

int main() {

  vector<int> sequence {1,9,9};

  
    Node* node3 = new Node(2,NULL,NULL);
    Node* node2 = new Node(9,NULL,NULL);
    Node* node1 = new Node(9,node3,node2);

    Node* node7 = new Node(7,NULL,NULL);
    Node* root = new Node(1,node7,node1);

    //Node* root = node1;

    cout << " path is : " << dfs(root,sequence,0);


}