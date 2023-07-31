```
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                auto node = q.front();
                q.pop();

                if(i == size-1) ans.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return ans;
    }
};
```
