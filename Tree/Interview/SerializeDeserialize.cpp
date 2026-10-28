/*
    Serialize and Deserialize Binary Tree (LeetCode 297) — HARD

    Design an algorithm to serialize a binary tree to a string
    and deserialize the string back to the original tree.

    Approach:
    - Serialize: Preorder DFS. Use "null" for null nodes, comma-separated.
    - Deserialize: Split by comma, rebuild tree with an index counter.

    Example:
            1
           / \
          2   3
             / \
            4   5

    Serialized: "1,2,null,null,3,4,null,null,5,null,null"

    Time:  O(n) for both operations
    Space: O(n)
*/

#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

// ─── Serialize (Preorder DFS) ─────────────────────────────────────

void serializeHelper(TreeNode* root, ostringstream& out) {
    if (!root) {
        out << "null,";
        return;
    }
    out << root->val << ",";
    serializeHelper(root->left, out);
    serializeHelper(root->right, out);
}

string serialize(TreeNode* root) {
    ostringstream out;
    serializeHelper(root, out);
    return out.str();
}

// ─── Deserialize ──────────────────────────────────────────────────

TreeNode* deserializeHelper(queue<string>& tokens) {
    if (tokens.empty()) return nullptr;

    string token = tokens.front(); tokens.pop();
    if (token == "null") return nullptr;

    TreeNode* node = new TreeNode(stoi(token));
    node->left  = deserializeHelper(tokens);
    node->right = deserializeHelper(tokens);
    return node;
}

TreeNode* deserialize(const string& data) {
    queue<string> tokens;
    stringstream ss(data);
    string token;
    while (getline(ss, token, ',')) {
        if (!token.empty()) tokens.push(token);
    }
    return deserializeHelper(tokens);
}

// ─── Helpers ──────────────────────────────────────────────────────

void printLevelOrder(TreeNode* root) {
    if (!root) { cout << "(empty)" << endl; return; }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            cout << node->val << " ";
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << "| ";
    }
    cout << endl;
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(1,
        new TreeNode(2),
        new TreeNode(3, new TreeNode(4), new TreeNode(5)));

    string serialized = serialize(root);
    cout << "Serialized:   " << serialized << endl;

    TreeNode* deserialized = deserialize(serialized);
    cout << "Deserialized: ";
    printLevelOrder(deserialized);

    // Verify round-trip
    string reserialized = serialize(deserialized);
    cout << "Round-trip:   " << (serialized == reserialized ? "PASS" : "FAIL") << endl;

    freeTree(root);
    freeTree(deserialized);
    return 0;
}
