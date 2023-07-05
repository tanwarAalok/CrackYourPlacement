# Majority-element

```
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

### Moore's Voting Algorithm
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int cnt = 1;

        for(int i = 1; i<nums.size(); i++){
            if(cnt == 0) ans = nums[i];

            if(nums[i] == ans) cnt++;
            else cnt--;
        }

        return ans;
    }
};
```
