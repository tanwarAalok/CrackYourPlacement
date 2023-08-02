```
class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> freq;

        
        int ans = 0, j = 0, i = 0, maxCount = 0;
        
        
        for(int i = 0; i<s.size(); i++){    
            
            maxCount = max(maxCount, ++freq[s[i]]);
            
            while( i + 1 - j - maxCount > k){
                freq[s[j]]--;
                j++;
            }
            
            ans = max(ans, i + 1 - j);
            
        }
        
        return ans;
    }
};
```
