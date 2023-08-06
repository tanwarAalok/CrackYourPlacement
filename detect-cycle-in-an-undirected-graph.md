```
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    void dfs(int node, int par, vector<int> adj[], vector<int> &vis, bool &ans){
        vis[node] = 1;
        for(auto it : adj[node]){
            
            if(!vis[it]) dfs(it, node, adj, vis, ans);
            else if(it != par){
                ans = true;
                return;
            }
            
        }
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        bool ans = false;
       
        for(int i = 0; i<V; i++){
            if(!vis[i])  dfs(i, -1, adj, vis, ans);
        }
        
        return ans;
    }
};
```
