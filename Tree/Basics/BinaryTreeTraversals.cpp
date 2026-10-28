/*
    Binary Tree — Basic Structure & Traversals

    Covers:
    - Tree construction
    - Inorder, Preorder, Postorder (DFS — recursive + iterative)
    - Level Order (BFS)
    - Height / Max Depth

    LeetCode: 94, 144, 145, 102, 104
*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
  TreeNode(int v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r) {}
};

// ─── DFS Traversals (Recursive) ───────────────────────────────────

void inorder(TreeNode *root, vector<int> &result) {
  if (!root)
    return;
  inorder(root->left, result);
  result.push_back(root->val);
  inorder(root->right, result);
}

void preorder(TreeNode *root, vector<int> &result) {
  if (!root)
    return;
  result.push_back(root->val);
  preorder(root->left, result);
  preorder(root->right, result);
}

void postorder(TreeNode *root, vector<int> &result) {
  if (!root)
    return;
  postorder(root->left, result);
  postorder(root->right, result);
  result.push_back(root->val);
}

// ─── DFS Traversals (Iterative) ──────────────────────────────────
vector<int> inorderIterative(TreeNode *root) {

  vector<int> result;
  stack<TreeNode *> st;
  TreeNode *current = root;

  while (current || !st.empty()) {
    
    while (current) {
      st.push(current);
      current = current->left;
    }
    current = st.top();
    st.pop();
    result.push_back(current->val);
    current = current->right;
  }
  return result;

}

vector<int> preorderIterative(TreeNode *root) {

  vector<int> result;
  if (!root)
    return result;

  stack<TreeNode *> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode *node = st.top();
    st.pop();
    result.push_back(node->val);
    if (node->right)
      st.push(node->right); // right first so left is processed first
    if (node->left)
      st.push(node->left);
  }
  return result;
  
}

/*
    True iterative postorder using a single stack + lastVisited pointer.

    Logic:
    1. Push all left children onto the stack.
    2. Peek at the top:
       - If it has a right child we haven't visited yet → go right.
       - Otherwise → pop and process it (post-order visit).
    3. `lastVisited` prevents re-entering the right subtree.
*/
vector<int> postorderIterative(TreeNode *root) {
  vector<int> result;
  stack<TreeNode *> st;
  TreeNode *current = root;
  TreeNode *lastVisited = nullptr;

  while (current || !st.empty()) {
    // Go as far left as possible
    while (current) {
      st.push(current);
      current = current->left;
    }

    TreeNode *top = st.top();

    // If right child exists and hasn't been visited, go right
    if (top->right && top->right != lastVisited) {
      current = top->right;
    } else {
      // Both children processed — visit this node
      result.push_back(top->val);
      lastVisited = top;
      st.pop();
    }
  }
  return result;
}

// ─── BFS — Level Order Traversal ─────────────────────────────────
vector<vector<int>> levelOrder(TreeNode *root) {
  vector<vector<int>> result;
  if (!root)
    return result;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();
    vector<int> level;
    for (int i = 0; i < size; i++) {
      TreeNode *node = q.front();
      q.pop();
      level.push_back(node->val);
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    result.push_back(level);
  }
  return result;
}

// ─── Max Depth (LeetCode 104) ─────────────────────────────────────

int maxDepth(TreeNode *root) {
  if (!root)
    return 0;
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// ─── Helpers ──────────────────────────────────────────────────────

void printVector(const vector<int> &v) {
  for (int x : v)
    cout << x << " ";
  cout << endl;
}

void freeTree(TreeNode *root) {
  if (!root)
    return;
  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

int main() {
  /*
      Build tree:
            1
           / \
          2   3
         / \   \
        4   5   6
  */
  TreeNode *root =
      new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                   new TreeNode(3, nullptr, new TreeNode(6)));

  // Recursive traversals
  vector<int> res;
  inorder(root, res);
  cout << "Inorder (recursive):    ";
  printVector(res);

  res.clear();
  preorder(root, res);
  cout << "Preorder (recursive):   ";
  printVector(res);

  res.clear();
  postorder(root, res);
  cout << "Postorder (recursive):  ";
  printVector(res);

  // Iterative traversals
  cout << "Inorder (iterative):    ";
  printVector(inorderIterative(root));
  cout << "Preorder (iterative):   ";
  printVector(preorderIterative(root));
  cout << "Postorder (iterative):  ";
  printVector(postorderIterative(root));

  // BFS
  cout << "Level Order:            ";
  for (auto &level : levelOrder(root)) {
    cout << "[ ";
    for (int x : level)
      cout << x << " ";
    cout << "] ";
  }
  cout << endl;

  cout << "Max Depth:              " << maxDepth(root) << endl;

  freeTree(root);
  return 0;
}
