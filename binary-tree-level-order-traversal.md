```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root) return {};
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            vector<int> curr;
            
            for(int i = 0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                curr.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            ans.push_back(curr);
        }
        
        return ans;
        
        
    }
};
```
