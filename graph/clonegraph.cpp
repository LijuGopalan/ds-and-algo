#include <cstddef>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;
 
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node, map<Node*,Node*>& m) {

  if(node == NULL)
    return nullptr;

  if(m.find(node) != m.end()) {
    return m[node];
  }

  Node* clonenode = new Node(node->val);

  for(Node* neighbor : node->neighbors)
    clonenode->neighbors.push_back(cloneGraph(neighbor,m));
  

  return clonenode;


    
}


int main() {

  


  return 1;
}
 


