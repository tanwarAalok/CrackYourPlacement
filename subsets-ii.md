```
class Solution {
public:
    
    vector<vector<int>> subsets;
    
    void subset(vector<int>& nums, vector<int> &curr, int idx){        
        
        subsets.push_back(curr);
        
        for(int i = idx; i<nums.size(); i++){
            
            if(i != idx && nums[i] == nums[i-1]) continue;
            
            curr.push_back(nums[i]);
            
            subset(nums, curr, i+1);
            
            curr.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        
        subset(nums, curr, 0);
        
        return subsets;
        
    }
};
```
