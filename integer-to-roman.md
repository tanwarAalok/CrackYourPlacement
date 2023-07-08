```
Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
```

```
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> map = {{1000, "M"},{900, "CM"} , {500, "D"},{400, "CD"} , {100, "C"} , {90, "XC"}, {50, "L"}, {40, "XL"},{10, "X"}, {9, "IX"},{5, "V"} , {4, "IV"},{1, "I"} };

        string ans = "";

        while(num > 0){
            for(auto x : map){
                if(num >= x.first){
                    ans += x.second;
                    num -= x.first;
                    break;
                }
            }
        }

        return ans;
    }
};
```
