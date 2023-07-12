```
Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
```

```
class Solution {
public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, mini = INT_MAX;

        // Think reverse if n-1 elements can be incremented then we can think like
        // 1 element can be decremented in one move 
        
        for(auto it : arr) mini = min(mini, it);

        for(auto it : arr) ans += (it - mini);
        
        return ans;
    }
};
```
