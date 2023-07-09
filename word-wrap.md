```
Input: nums = {3,2,2,5}, k = 6
Output: 10
Explanation: Given a line can have 6
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4
So total cost = (6-3)2 + (6-2-2-1)2 = 32+12 = 10.
As in the first line word length = 3 thus
extra spaces = 6 - 3 = 3 and in the second line
there are two word of length 2 and there already
1 space between two word thus extra spaces
= 6 - 2 -2 -1 = 1. As mentioned in the problem
description there will be no extra spaces in
the last line. Placing first and second word
in first line and third word on second line
would take a cost of 02 + 42 = 16 (zero spaces
on first line and 6-2 = 4 spaces on second),
which isn't the minimum possible cost.
```

```
class Solution {
public:

    int dp[501][2001];

    int f(vector<int> nums, int k, int idx, int rem){
        if(idx >= nums.size()) return 0;
        
        if(dp[idx][rem] != -1) return dp[idx][rem];
        
        
        if(nums[idx] > rem){
            dp[idx][rem] = f(nums, k, idx+1, k-nums[idx]-1) + pow(rem+1, 2);
        }
        else {
            int c1 = f(nums, k, idx+1, k-nums[idx]-1) + pow(rem+1, 2);
            int c2 = f(nums, k, idx+1, rem-nums[idx]-1);
            dp[idx][rem] = min(c1, c2);
        }
        
        return dp[idx][rem];
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        
        return f(nums, k, 0, k);
        
    } 
};
```
