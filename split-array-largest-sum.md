```
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
```

```
class Solution {
public:

    int count(vector<int>& nums, int sum, int n){
        int temp = 1;
        long long currSum = 0;
        for(int i = 0; i<n; i++){
            if(currSum + nums[i] <= sum){
                currSum += nums[i];
            }
            else {
                temp++;
                currSum = nums[i];
            }
        }
        return temp;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = (low + high) / 2;

            int temp = count(nums, mid, n);

            if(temp > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
```
