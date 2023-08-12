```
class Solution{
    public:
    
    int longestCommonSubstr (string s, string r, int n, int m)
    {
          int dp[n+1][m+1];
          memset(dp, 0, sizeof(dp));
          
          int ans = 0;
        
          for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
              if(s[i-1] == r[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
              }
              else{
                dp[i][j] = 0;
              }
            }
          }
        
          return ans;
    }
};
```
