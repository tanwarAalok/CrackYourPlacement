```
Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
```

```
class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i = 1; i<=n; i++){
            if(n%i == 0){
                k--;
                if(k == 0){
                    return i;
                }
            }
        }

        return -1;
    }
};
```
