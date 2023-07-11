```
    void dfs(vector<vector<char>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        
        int dx[8] = {0, 0, 1, 1, -1, -1, 1, -1};
        int dy[8] = {1, -1, -1, 0, 1, 0, 1, -1};
        
        for(int c = 0; c<8; c++){
            int newi = i + dx[c], newj = j + dy[c];
            dfs(grid, newi, newj);
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        
        int n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
```
