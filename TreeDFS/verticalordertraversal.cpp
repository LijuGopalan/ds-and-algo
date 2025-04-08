/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
    
        void dfs(TreeNode* root, int order, map<int,vector<int>>& m) {
    
            if(root == NULL)
                return;
    
            m[order].push_back(root->val);
    
            dfs(root->left,order-1,m);
            dfs(root->right,order+1,m);
             
        }
    
        vector<vector<int>> verticalTraversal(TreeNode* root) {
    
            map<int,vector<int>> m;
            dfs(root,0,m);
    
            vector<vector<int>> v;
    
            for(pair<int,vector<int>> t : m) {
                v.push_back(t.second);
            }
    
            return v; 
        }
    };