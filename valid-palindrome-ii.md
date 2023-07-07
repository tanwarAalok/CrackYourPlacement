```
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
```

```
class Solution {
public:
    bool validPalindrome(string s) {
        
        for(int i = 0, j = s.size() - 1; i<j; i++, j--){
            if(s[i] != s[j])
            {
                int s1 = i, e1 = j-1, s2 = i+1, e2 = j;
                
                while(s1 < e1 && s[s1] == s[e1]){
                    s1++;
                    e1--;
                }
                
                while(s2 < e2 && s[s2] == s[e2]){
                    s2++;
                    e2--;
                }
                
                return s1>=e1 || s2>=e2;
            }
        }
        
        return true;
    }
    
};
```
