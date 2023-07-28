```
class Solution {
public:
    
    void f(vector<int>& nums, int n, vector<int>&curr,vector<int>&vis, set<vector<int>>&s){
        if(curr.size() == n){
            s.insert(curr);
            return;
        }
        
        for(int i = 0; i<n; i++){
            if(vis[i] == 0){
                vis[i] = 1;
                
                curr.push_back(nums[i]);
                f(nums, n, curr, vis, s);
                
                curr.pop_back();
                vis[i] = 0;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        set<vector<int>> s;
        
        int n = nums.size();
        
        vector<int> vis(n, 0);
        
        f(nums, n, curr, vis, s);
        
        for(auto it : s){
            ans.push_back(it);
        }
        return ans;
        
    }
};
```
