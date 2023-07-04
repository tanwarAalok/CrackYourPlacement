# Jump-game

```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

### Trick - Think backwords

```
class Solution {
public:

    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int last = n-1, i, j;

        for(i = n-2; i>=0; i--){
            if(i + nums[i] >= last) last = i;
        }

        return last <= 0;
    }
};

```
