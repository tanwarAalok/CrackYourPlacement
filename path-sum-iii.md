```
class Solution {
public:
    int ans = 0;

    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            dfs(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }

    void dfs(TreeNode* root, long long targetSum){
        if(!root) return;
        if(root->val == targetSum) ans++;
        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);
    }
};
```
