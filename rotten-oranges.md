```
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>, int>> q;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int fresh = 0, rotted = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
                else if(grid[i][j] == 1) fresh++;
            }
        }
        
        int ans = 0;
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!q.empty()){
            int t = q.front().second;
            int row = q.front().first.first;
            int col = q.front().first.second;
            q.pop();
            
            ans = max(ans, t);
            
            for(int i = 0; i<4; i++){
                int nrow = row + dx[i], ncol = col + dy[i];
                
                if(nrow < 0 || nrow >= n || ncol < 0 || ncol >= m || vis[nrow][ncol] == 2 || grid[nrow][ncol] != 1) continue;
                
                q.push({{nrow, ncol}, t+1});
                vis[nrow][ncol] = 2;
                rotted++;
            }
        }
        
        if(rotted != fresh) return -1;
        
        return ans;
    }
};
```
