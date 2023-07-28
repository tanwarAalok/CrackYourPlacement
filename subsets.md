```
class Solution {
public:
    
    void f(vector<int> nums,vector<vector<int>> &ans, vector<int> cur, int n, int i){
        if(i==n){
            ans.push_back(cur);
            return;
        }
        
        cur.push_back(nums[i]);
        f(nums,ans,cur,n,i+1);
        
        cur.pop_back();
        f(nums,ans,cur,n,i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> cur;
        int n = nums.size();
        int i = 0;
        f(nums,ans,cur,n,i);
        
        return ans;
        
    }
};
```
