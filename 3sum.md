# 3Sum

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
```


```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i<n-2; i++){
            
            if(i == 0 || i>0 && nums[i] != nums[i-1]){
                int start = i+1, end = n-1, target = -nums[i];

                while(start < end){
                    if(nums[start] + nums[end] == target){
                        ans.push_back({nums[i], nums[start], nums[end]});
                        
                        while(start < end && nums[start] == nums[start+1]) start++;
                        while(start < end && nums[end] == nums[end-1]) end--;

                        start++;
                        end--;
                    }
                    else if(nums[start] + nums[end] < target) start++;
                    else end--;

                }
            }      
        }

        return ans;
    }
};
```
