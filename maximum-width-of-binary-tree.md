```
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        int ans = 0;

        while(!q.empty()){
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;

            ans = max(ans, end - start + 1);

            for(int i = 0; i<size; i++){
                auto pair = q.front();
                auto node = pair.first;
                int value = pair.second;
                q.pop();

                if(node->left) q.push({node->left, value*2LL + 1});
                if(node->right) q.push({node->right, value*2LL + 2});

                
            }
        }

        return ans;
    }
};
```
