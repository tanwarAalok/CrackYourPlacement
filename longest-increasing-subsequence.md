```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        int dp[n];
        dp[0] = 1;

        for(int i = 1; i<n; i++){
            int curr = 1;
            for(int j = i-1; j>=0; j--){
                if(nums[j] < nums[i]) curr = max(curr, 1 + dp[j]);
            }
            dp[i] = curr;
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
```
