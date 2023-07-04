# 4sum

```
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> set;

        for(int i = 0; i<n-3; i++){
            for(int j = i+1; j<n-2; j++){
                long long t1 = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] < t1){
                        low++;
                    }
                    else if(nums[low] + nums[high] > t1) high--;
                    else {
                        set.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++; high--;
                    }
                }
            }
        }

        for(auto it : set) ans.push_back(it);

        return ans;
    }
};
```
