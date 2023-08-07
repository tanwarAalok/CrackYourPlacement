```
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";

        for(int i = 0; i<num.size(); i++){
            while(!ans.empty() && ans.back() > num[i] && k){
                ans.pop_back();
                k--;
            }
            if(!ans.empty() || num[i] != '0') ans.push_back(num[i]);
        }

        while(!ans.empty() && k--){
            ans.pop_back();
        }

        return (ans == "") ? "0" : ans;
    }
};
```
