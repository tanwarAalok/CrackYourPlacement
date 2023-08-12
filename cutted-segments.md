
```
class Solution
{
    int dp[10001];
    
    int f(int n, int x, int y, int z){
        if(n == 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int c1 = INT_MIN, c2 = INT_MIN, c3 = INT_MIN;
        
        if(n - x >= 0) c1 = f(n-x, x, y, z);
        if(n - y >= 0) c2 = f(n-y, x, y, z);
        if(n - z >= 0) c3 = f(n-z, x, y, z);
        
        return dp[n] = 1 + max(c1, max(c2, c3));
    }
    
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp, -1, sizeof(dp));
        int res = f(n, x, y, z);
        if(res < 0) return 0;
        return res;
    }
};
```
