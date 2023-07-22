```
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;

        for(auto it : s){
            if(it != '#') s1.push(it);
            else if(!s1.empty()) s1.pop();
        }

        for(auto it : t){
            if(it != '#') s2.push(it);
            else if(!s2.empty()) s2.pop();
        }

        if(s1.size() != s2.size()) return false;

        while(!s1.empty()){
            if(s1.top() != s2.top()) return false;
            s1.pop();
            s2.pop();
        }

        return true;
    }
};
```
