```
class Solution {
public:
    int minDeletions(string s) {
        int hash[26] = {0};
        unordered_set<int> st;

        for(int i = 0; i<s.size(); i++) hash[s[i] - 'a']++;

        int ans = 0;

        for(int i : hash){
            while(i > 0 && st.count(i)){
                i--; ans++;
            }

            if(i > 0) st.insert(i);
        }

        return ans;
    }
};
```
