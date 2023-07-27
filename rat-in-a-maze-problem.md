```
class Solution{
    public:
    
    void dfs(vector<vector<int>> &m, int n, set<string> &st, vector<vector<int>> vis, string curr, int i, int j){
        if(i < 0 || i >= n || j < 0 || j >= n || vis[i][j] == 1 || m[i][j] == 0) return;
        
        if(i == n-1 && j == n-1) {
            st.insert(curr);
            return;
        }
        
        
        vis[i][j] = 1;
        
        dfs(m, n, st, vis, curr + "L", i, j-1);
        dfs(m, n, st, vis, curr + "R", i, j+1);
        dfs(m, n, st, vis, curr + "D", i+1, j);
        dfs(m, n, st, vis, curr + "U", i-1, j);
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        set<string> st;
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        dfs(m, n, st, vis, "", 0, 0);
        
        
        for(auto it : st){
            ans.push_back(it);
        }
        
        return ans;
    }
};
```
