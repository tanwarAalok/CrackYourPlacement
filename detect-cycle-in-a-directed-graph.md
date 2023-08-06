```
class Solution {
  public:
    
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &path){
        vis[node] = 1;
        path[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]) {
                if(dfs(it, adj, vis, path)) return true;
            }
            else if(path[it]) return true;
        }
        
        path[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        
        for(int i = 0; i<V; i++){
            if(!vis[i]) {
                if(dfs(i, adj, vis, path)) return true;
            }
        }
        
        return false;
    }
};
```
