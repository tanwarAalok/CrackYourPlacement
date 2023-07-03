# Subarray Sum Equals K

```
Input: nums = [1,1,1], k = 2
Output: 2
```


```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, sum = 0;

        unordered_map<int,int> hash;

        for(int i = 0; i<n; i++){
            sum += nums[i];
            if(sum == k) cnt++;

            cnt += hash[sum - k];

            hash[sum]++;
        }

        return cnt;
    }
};
```
