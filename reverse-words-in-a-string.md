```
Input: s = "the sky is blue"
Output: "blue is sky the"
```
### My solution using StringStream and reverse function
```
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans = "";
        stringstream ss(s);
        string word;
        
        while(ss >> word){
            reverse(word.begin(), word.end());
            ans += word;
            ans += " ";
        }
        ans.pop_back();
        
        return ans;        
    }
};
```

### Solution using stack
```
string reverseWords(string s) {
        if(s.size() == 0) return s;
        stack<string> stack;
        string result;
        for(int i=0; i<s.size(); i++) {
            string word;
            if(s[i]==' ') continue; //skip spaces
            while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
                word += s[i]; i++;
            }
            stack.push(word); //push word to the stack
        }
        while(!stack.empty()) {
            result += stack.top(); stack.pop();
            if(!stack.empty()) result += " ";
        }
        return result;
    }
};
```
