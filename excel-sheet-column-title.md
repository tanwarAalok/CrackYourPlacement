```
Input: columnNumber = 28
Output: "AB"
```

```
class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(columnNumber > 0 && columnNumber <= 26){
            string temp = "";
            char c = char(64 + columnNumber);
            temp += c;
            return temp;
        }
        int q, r;
        if(columnNumber % 26 == 0){
            q = columnNumber / 26;
            q--;
            r = 26;
        }
        else {
            q = columnNumber / 26;
            r = columnNumber % 26;
        }

        

        string quotient = "", rem = "";

        if(q <= 26 && r <= 26){
            string s = "";
            if(q > 0){
                char c1 = char(64 + q);
                s += c1;
            }
            if(r > 0){
                char c2 = char(64 + r);
                s += c2;
            }
            return s;
        }

        if(q > 0 && q <= 26){
            char c = char(64 + q);
            quotient += c;
        }
        if(r > 0 && r <= 26){
            char c = char(64 + r);
            rem += c;
        }

        if(q > 26 && r > 26){
            return convertToTitle(q) + quotient + convertToTitle(r) + rem;
        }

        if(q > 26){
            return convertToTitle(q) + quotient + rem;
        }

        return quotient + convertToTitle(r) + rem;
    }
};
```
