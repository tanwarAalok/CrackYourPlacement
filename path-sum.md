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
    void pre(TreeNode* root, int targetSum, bool &ans, int &curr){
        if(!root) return;
        if(!root->left && !root->right) {
            if((curr + root->val) == targetSum) ans = true;
            return;
        }
        curr += root->val;
        pre(root->left, targetSum, ans, curr);
        pre(root->right, targetSum, ans, curr);
        curr -= root->val;
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        int curr = 0;
        pre(root, targetSum , ans, curr);
        return ans;
        
    }
};
```
