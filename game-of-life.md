# Game-of-life

```
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
```

![figure](https://assets.leetcode.com/uploads/2020/12/26/grid1.jpg)
```
class Solution {
public:
    bool check(int n, int m, int i, int j, vector<vector<int>> v){
        int dx[8] = {0, 0, -1, 1, 1, -1, 1, -1};
        int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

        int lives = 0;
        for(int c = 0; c<8; c++){
            int newi = i + dx[c], newj = j + dy[c];
            if(newi < 0 || newi >= n || newj < 0 || newj >= m) continue;
            if(v[newi][newj]) lives++;
        }

        if(v[i][j]){
            if(lives < 2 || lives > 3) return true;
        }
        else {
            if(lives == 3) return true;
        }

        return false;
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy = board;

        int n = board.size(), m = board[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(check(n, m, i, j, copy)) board[i][j] ^= 1;
            }
        }
    }
};
```
