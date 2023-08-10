```
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int maxTime = INT_MIN;

        vector<int> adj[n];

        for(int i = 0; i<n; i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        q.push({headID, 0});

        while(!q.empty()){
            auto m = q.front();
            q.pop();

            int parent = m.first;
            int time = m.second;

            maxTime = max(maxTime, time);

            for(auto it: adj[parent]){
                q.push({it, time + informTime[parent]});
            }
        }

        return maxTime;
    }
};
```
