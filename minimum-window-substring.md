```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

```
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash1, hash2;

        int cnt = 0, j = 0, idx = -1, min_size = INT_MAX, curr_size = 0;

        for(auto it: t){
            hash1[it]++;
        }

        for(int i = 0; i<s.size(); i++){
            hash2[s[i]]++;

            if(hash1.count(s[i]) && hash2[s[i]] <= hash1[s[i]]){
                cnt++;
            }

            if(cnt == t.size()){
                while(!hash1.count(s[j]) or hash2[s[j]] > hash1[s[j]]){
                    hash2[s[j]]--;
                    j++;
                }

                curr_size = i - j + 1;
                if(curr_size < min_size){
                    min_size = curr_size;
                    idx = j;
                }
            }
        }

        if(idx == -1) return "";

        return s.substr(idx, min_size);
    }
};
```
