```
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
```
### Using find method
```
class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle);
        if (found != string::npos){
            return found;
        }
        
        return -1;
    }
};
```

### Using KMP
```
class Solution {
public:

    void computeLPS(string pattern, int n, int *lps){
        int len = 0, i = 1;
        lps[0] = 0;
        
        while(i<n){
            if(pattern[i] == pattern[len]){
                lps[i++] = ++len;
            }
            else {
                if(len != 0) len = lps[len-1];
                else lps[i++] = 0;
            }
        }
    }

    int strStr(string text, string pattern) {
        int m = text.size();
        int n = pattern.size();
        int lps[n];
        
        computeLPS(pattern, n, lps);
        
        int i=0, j=0;
        while(i<m){
            if(text[i] == pattern[j]){
                i++; j++;
            }
            if(j == n){
                return i-j;
            }
            else if(i<m && pattern[j] != text[i]){
                if(j!=0) j = lps[j-1];
                else i++;
            }
        }

        return -1;
    }
};
```
