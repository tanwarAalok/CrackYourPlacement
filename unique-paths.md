```
class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>> &dp){
        if(i == n-1 && j == m-1){
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int c1 = 0, c2 = 0;
        if(i < n-1) c1 = dfs(i+1, j, n, m, dp);
        if(j < m-1) c2 = dfs(i, j+1, n, m, dp);

        return dp[i][j] = c1+c2;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(0,0, m, n, dp);
    }
};
```
