# Maximum-points-you-can-obtain-from-cards

```
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
```
![figure](https://assets.leetcode.com/users/images/a539e5d3-3faa-43d3-bfcd-8a6549e4589b_1656213784.1710274.png)

```
class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int ans = 0;

        for(int i = 0; i<k; i++) ans += cp[i];

        int curr = ans;

        for(int i = k-1; i>=0; i--){
            curr -= cp[i];
            curr += cp[cp.size()-k+i];

            ans = max(ans, curr);
        }

        return ans;
    }
};
```
