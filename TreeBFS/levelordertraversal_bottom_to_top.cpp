
#include <iostream> 
#include <vector>
#include <queue>
#include <deque>
using namespace std;

class Node {

    public:
      int val;
      Node *left;
      Node * right;
    
      Node(int v, Node* l, Node* r) {
    
        val = v;
        left = l;
        right = r;
    
      }
    
};
    
deque<vector<int>> levelordertraverse_bottom_to_top(Node* root) {

    if(root == NULL) {
    return {{}};
    }

    queue<Node*> q;
    q.push(root);

    deque<vector<int>> dq;
    while (!q.empty()) {

    int level = q.size();
    vector<int> temp;

    while(level > 0) {

        Node* n = q.front();
        q.pop();
        
        temp.push_back(n->val);
    
        if(n->left != NULL) 
        q.push(n->left);

        if(n->right != NULL)
        q.push(n->right);
        
        level--;
    }
    dq.push_front(temp);

    }

    return dq;
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

    deque<vector<int>> r = levelordertraverse_bottom_to_top(node5);

    cout << " level order BFS from Bottom to Top " << endl ;

    for(vector<int> x : r ) {
      
      cout << endl;
      for( int i: x) {
        cout << i << " ";
      }

    }

    return 0;
  
}