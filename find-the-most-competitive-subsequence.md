```
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;

        priority_queue<pair<int,int>> pq;
        int ptr = 0;

        for( ;ptr < nums.size() - k + 1; ptr++){
            pq.push({-nums[ptr], -ptr});
        }

        int prev = -1;
        while(ptr < nums.size()){
            auto x = pq.top();
            pq.pop();

            if(-x.second < prev) continue;

            res.push_back(-x.first);
            prev = -x.second;

            pq.push({-nums[ptr], -ptr});

            ptr++;
        }

        while(true){
            auto x = pq.top();
            pq.pop();

            if(-x.second < prev) continue;
            else {
                res.push_back(-x.first);
                break;
            }
        }

        return res;
    }
};
```
