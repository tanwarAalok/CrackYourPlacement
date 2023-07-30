```
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
    void dfs(TreeNode* root, vector<string> &st, string path){
        if(!root) return;

        if(path.empty()) path += to_string(root->val);
        else path += "->" + to_string(root->val);

        if(!root->left && !root->right){
            st.push_back(path);
            return;
        }

        dfs(root->left, st, path);
        dfs(root->right, st, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> st;
        dfs(root, st, "");
        return st;
    }
};
```
