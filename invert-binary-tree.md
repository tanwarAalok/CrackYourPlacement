```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;

        TreeNode* l = root->left;
        TreeNode* r = root->right;

        root->left = invertTree(r);
        root->right = invertTree(l);
        
        return root;
    }
};
```
