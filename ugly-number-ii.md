```
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
```

```
class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_map<long long, int> map;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        pq.push(1);
        int cnt = 0;
        long long popped;

        while(cnt < n){
            popped = pq.top();
            pq.pop();

            if(map[popped] == 0){
                pq.push(popped*2);
                pq.push(popped*3);
                pq.push(popped*5);

                cnt++;
                map[popped] = 1;
            }
        }

        return int(popped);
    }
};
```
