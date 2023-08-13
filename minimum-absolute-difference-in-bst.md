```
class Solution {
public:
    int ans = INT_MAX;
    TreeNode *prev = NULL;

    void dfs(TreeNode* root){
        if(root->left) dfs(root->left);

        if(prev) ans = min(ans, abs(prev->val - root->val));
        prev = root;

        if(root->right) dfs(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```
