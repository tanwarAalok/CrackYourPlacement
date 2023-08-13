```
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        
        return (root->left && !root->left->left && !root->left->right ? root->left->val : 0) +  sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        
    }
};
```
