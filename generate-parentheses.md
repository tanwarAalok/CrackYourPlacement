```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

```
class Solution {
public:
    vector<string> ans;

    void f(int open, int close, int n, string curr){
        if(curr.size() == n*2){
            ans.push_back(curr);
            return;
        }

        if(open < n) f(open+1, close, n, curr + "(");
        if(close < open) f(open, close + 1, n, curr + ")");
    }

    vector<string> generateParenthesis(int n) {
        f(0, 0, n, "");
        return ans;
    }
};
```
