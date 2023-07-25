```
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;

        for(auto r : matrix){
            for(auto c : r){
                pq.push(c);
                if(pq.size() > k) pq.pop();
            }
        }

        return pq.top();
    }
};
```
