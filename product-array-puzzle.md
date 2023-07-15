```
Input:
n = 5
nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
```

```
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        vector<long long int> pre(n+1), suff(n+1), ans(n);
        pre[0] = suff[n] = 1;
        
        for(int i = 1; i<=n; i++) pre[i] = pre[i-1] * nums[i-1];
        for(int i = n-1; i>=0; i--) suff[i] = suff[i+1] * nums[i];
        
        for(int i = 0; i<n; i++){
            ans[i] = pre[i] * suff[i+1];
        }
        
        return ans;
    }
};
```
