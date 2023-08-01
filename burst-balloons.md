```

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size(), i = 0;

        vector<int> v;
        v.push_back(1);

        while(i<n){
            v.push_back(nums[i]);
            i++;
        }
        v.push_back(1);

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        i = 1;
        while(i<=n){
            dp[i][i] = v[i-1]*v[i]*v[i+1];
            i++;
        }

        int len = 2;
        while(len <= n){
            i = 1;
            int j = i+len-1;

            while(j<=n){
                int k = i;
                int max_ans = INT_MIN;

                while(k<=j){
                    int res = v[i-1]*v[k]*v[j+1];
                    if(i<=k-1) res += dp[i][k-1];
                    if(k+1<=j) res += dp[k+1][j];

                    max_ans = max(max_ans, res);
                    k++;
                }
                dp[i][j] = max_ans;
                j++;i++;
            }
            len++;
        }
        
        return dp[1][n];
    }
};
```
