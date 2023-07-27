```
void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &ans){
        vis[node] = true;
        ans.push_back(node);
        
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, adj, vis, ans);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V, false);
        
        for(int i = 0; i<V; i++){
            if(!vis[i]) dfs(i, adj, vis, ans);
        }
        
        return ans;
    }
```
