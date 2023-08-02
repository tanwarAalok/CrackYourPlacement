```
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
```

```
bool comp(vector<int> &a,vector<int> &b) {
    return a[1]<b[1];
}

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int ans = -1;
        vector<int> prev = intervals[0];
        
        for(auto it: intervals){
            if(prev[1] > it[0]) ans++;
            else prev = it;
        }
        return ans;
    }
};

```
