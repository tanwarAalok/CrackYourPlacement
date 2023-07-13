```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x != 0 && x % 10 == 0) return false;

        int check = 0;

        while( x > check){
            check = check * 10 + x % 10;
            x /= 10;
        }

        return (x==check || x==check/10);
    }
};

```
