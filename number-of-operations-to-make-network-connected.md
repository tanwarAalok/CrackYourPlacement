```
class Solution {
public:
    
    void dfs(vector<int> adj[], vector<int> &vis, int node){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj, vis, it);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1) return -1;
        
        vector<int> adj[n];
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int groups = 0;
        vector<int> vis(n, 0);
        
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                groups++;
            }
        }
        
        return groups - 1;
    }
};
```
