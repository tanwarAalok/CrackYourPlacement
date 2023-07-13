```
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

```
class Solution {
public:

    int next(int n){
        int newNumber = 0;
        while(n != 0){
            int num = n % 10;
            newNumber += num * num;
            n = n/10;
        }
        return newNumber;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = next(n);

        while(fast != 1 && fast != slow){
            slow = next(slow);
            fast = next(next(fast));
        }

        return fast == 1;
    }
};
```
