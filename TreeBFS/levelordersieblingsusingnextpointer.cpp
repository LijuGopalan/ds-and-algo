#include <cstddef>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*

connect level order sieblings

*/

class Node {

  public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int v, Node* l, Node* r , Node* n) {
      val =v;
      left = l;
      right = r;
    }

};

void connect_sieblings_levelorder(Node * root) {

  if(root == NULL)
    return;

  queue<Node*> q;
  q.push(root);

  while(!q.empty()) {

    int level = q.size();
 
    Node* n = NULL;

    while(level > 0) {

      n = q.front();
      q.pop();

      if(n->left != NULL)
        q.push(n->left);

      if(n->right != NULL)
        q.push(n->right);

      if(q.empty()) 
        n->next = NULL;
      else
        n->next = q.front();

      level--;
    }
    n->next = NULL;

  }
  
}

void connectNextPointers(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        Node* prev = nullptr;

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            if (prev) prev->next = curr;
            prev = curr;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        // The last node in the current level points to nullptr
        if (prev) prev->next = nullptr;
    }
}

// Function to print level order traversal using next pointers
void printLevelOrderUsingNext(Node* root) {
    while (root) {
      
        Node* curr = root;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;

        // Move to the next level (leftmost node of the next level)
        if (root->left) {
            root = root->left; 
        } else if (root->right) {
            root = root->right;
        } else {
            root = nullptr;
        }
    }
}


 


int main() {

    Node* node40 = new Node(40,NULL,NULL,NULL);
    Node* node50 = new Node(50,NULL,NULL,NULL);

    Node* node20 = new Node(20,NULL,NULL,NULL);
    Node* node30 = new Node(30,NULL,NULL,NULL);

    Node* node1 = new Node(15,node20,node30,NULL);
    Node* node2 = new Node(7,node40,node50,NULL);

    Node* node3 = new Node(20,node1,node2,NULL);

    Node* node4 = new Node(9,NULL,NULL,NULL);
    Node* node5 = new Node(3,node4,node3,NULL);

    connectNextPointers(node5);

    //connect_sieblings_levelorder(node5);
    printLevelOrderUsingNext(node5);

    return 1;
}


/*

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* next; // Pointer to the next node in the same level

    Node(int val) : data(val), left(nullptr), right(nullptr), next(nullptr) {}
};

// Function to establish 'next' pointers for level order traversal
void connectNextPointers(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        Node* prev = nullptr;

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            if (prev) prev->next = curr;
            prev = curr;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        // The last node in the current level points to nullptr
        if (prev) prev->next = nullptr;
    }
}

// Function to print level order traversal using next pointers
void printLevelOrderUsingNext(Node* root) {
    while (root) {
        Node* curr = root;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;

        // Move to the next level (leftmost node of the next level)
        if (root->left) {
            root = root->left;
        } else if (root->right) {
            root = root->right;
        } else {
            root = nullptr;
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    connectNextPointers(root);
    cout << "Level order traversal using next pointer:\n";
    printLevelOrderUsingNext(root);

    return 0;
}

*/