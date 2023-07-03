# Find All Duplicates in an Array

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
```

```
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans = {};
        
        for(int i = 0; i<nums.size(); i++){
            nums[abs(nums[i])-1] *= -1;
            
            if(nums[abs(nums[i])-1] > 0) ans.push_back(abs(nums[i]));
        }
        
        return ans;
    }
};
```
