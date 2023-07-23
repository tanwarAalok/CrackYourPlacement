```
class Solution {
public:
    int ans = 0;

    int f(TreeNode* root){
        if(!root) return 0;

        int lheight = f(root->left);
        int rheight = f(root->right);

        ans = max(ans, lheight + rheight);

        return 1 + max(lheight, rheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return ans;
    }
};
```
