```
class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int left_height = height(root->left);
        int right_height = height(root->right);
        int diff = abs(right_height - left_height);

        return diff <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
```
