```
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> m;
        
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int level = it.second.second;
            int vertical = it.second.first;
            
            m[vertical][level].insert(node->val);
            
            if(node->left) q.push({node->left, {vertical - 1, level + 1}});
            if(node->right) q.push({node->right, {vertical + 1, level + 1}});
        }
        
        
        for(auto it : m){
            vector<int> temp;
            for(auto v : it.second){
                temp.insert(temp.end(), v.second.begin(), v.second.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};
```
