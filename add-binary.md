```
Input: a = "11", b = "1"
Output: "100"
```

```
class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;

        int i = a.size()-1, j = b.size()-1;

        while(i >= 0 && j >= 0){
            int bit1 = a[i] - '0';
            int bit2 = b[j] - '0';

            int res = bit1 + bit2 + carry;

            if(res == 2){
                ans += '0';
                carry = 1;
            }
            else if(res == 3){
                ans += '1';
                carry = 1;
            }
            else {
                ans += to_string(res);
                carry = 0;
            }
            i--;j--;
        }

        while(i >= 0){
            int bit = a[i] - '0';
            int res = bit + carry;
            if(res > 1) {
                ans += '0';
                carry = 1;
            }
            else {
                ans += to_string(res);
                carry = 0;
            }
            i--;
        }

        while(j >= 0){
            int bit = b[j] - '0';
            int res = bit + carry;
            if(res > 1) {
                ans += '0';
                carry = 1;
            }
            else {
                ans += to_string(res);
                carry = 0;
            }
            j--;
        }

        if(carry > 0){
            ans += '1';
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
```
