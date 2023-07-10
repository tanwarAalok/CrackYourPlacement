```
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
```

```
class Solution {
public:
    int dp[1001][1001];

    int f(string s, string t, int idx, int curr){
        if(idx >= s.size()) return t.size() == curr;

        if(dp[idx][curr] != -1) return dp[idx][curr];

        int c1 = 0;
        int need = t.size() - curr - 1;
        if(idx + need < s.size()){
            c1 = f(s, t, idx+1, curr);
        }

        int c2 = 0;
        if(t[curr] == s[idx]){
            c2 = f(s, t, idx+1, curr + 1);
        }

        return dp[idx][curr] =  c1 + c2;
    }

    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return f(s, t, 0, 0);
    }
};
```
