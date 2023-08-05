```
class Solution{
public:

    bool f(int n, int arr[], int target){
        if(target == 0) return true;
        
        bool dp[n+1][target+1];
        
        for(int i = 0; i<=n; i++){
            dp[i][0] = true;
        }
        
        for(int i = 1; i<=target; i++){
            dp[0][i] = false;
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=target; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][target];
    }

    int equalPartition(int n, int arr[])
    {
        int totalSum = accumulate(arr, arr+n, 0);
        
        if(totalSum&1) return 0;
        
        int target = totalSum/2;
        
        sort(arr, arr+n);
        
        return f(n, arr, target);
    }
};
```
