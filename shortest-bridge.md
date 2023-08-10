```
class Solution {
    int dir[5] = {0, -1, 0, 1, 0};
public:
    void dfs(int i, int j, vector<vector<int>>& grid, queue<pair<int,int>> &q){
        q.push({i, j});
        grid[i][j] = -1;

        for(int d = 0; d<4; d++){
            int x = i + dir[d],  y = j + dir[d+1];
            if(x >= 0 and x < grid.size() and y >= 0 and y < grid.size() and grid[x][y] == 1) dfs(x, y, grid, q);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        bool found = false;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, q);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        while(!q.empty()){
            int i = q.front().first, j = q.front().second;
            q.pop();

            for(int d = 0; d<4; d++){
                int x = i+dir[d], y = j+dir[d+1];
                if(x >= 0 and x < n and y >= 0 and y < n){
                    if(grid[x][y] < 0) continue;
                    if(grid[x][y] == 1) return abs(grid[i][j]) - 1;
                    grid[x][y] = -1 * (abs(grid[i][j]) + 1);
                    q.push({x, y});
                }
            }
        }

        return -1;
    }
};
```
