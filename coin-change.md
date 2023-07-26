```
class Solution {
public:
    
    int f(vector<int>& coins, int amount, int idx, vector<vector<int>> &dp){
        
        if(idx == 0){
            if(amount % coins[0] == 0) return amount / coins[0];
            else return 1e9;
        }
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int not_pick = f(coins, amount, idx - 1, dp);
        
        int pick = INT_MAX;
        
        if(coins[idx] <= amount) pick = 1 + f(coins, amount - coins[idx], idx, dp);
        
        return dp[idx][amount] = min(pick, not_pick);
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        int idx = coins.size();
        
        vector<vector<int>> dp(idx+1, vector<int>(amount+1, -1));
        
        
        int result = f(coins, amount, idx-1, dp);
        
        return result == 1e9 ? -1 : result;
    }
};
```
