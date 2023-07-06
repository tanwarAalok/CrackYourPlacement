# Max-value-of-equation

```
Input: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
Output: 4
Explanation: The first two points satisfy the condition |xi - xj| <= 1 and if we calculate the equation we get 3 + 0 + |1 - 2| = 4. Third and fourth points also satisfy the condition and give a value of 10 + -10 + |5 - 6| = 1.
No other pairs satisfy the condition, so we return the max of 4 and 1.
```

```
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ans = INT_MIN;

        priority_queue<pair<int,int>> pq;

        for(int i = 0; i<n; i++){
            
            while(!pq.empty() && points[i][0] - pq.top().second > k) pq.pop();

            if(!pq.empty()) ans = max(ans, (pq.top().first + points[i][0] + points[i][1]));

            pq.push({points[i][1] - points[i][0], points[i][0]});
        }
        
        return ans;
    }
};
```
