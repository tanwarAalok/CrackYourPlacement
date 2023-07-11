```
Input: n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: ans = {{'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'O', 'O'}}
Explanation: Following the rule the above 
matrix is the resultant matrix. 
```

```
class Solution{
public:

    void dfs(int n, int m, vector<vector<char>>& mat, int i, int j, char toggle){
        if(i<0 || j<0 || i>=n || j>=m || mat[i][j] != 'O') return;
        
        mat[i][j] = toggle;
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        for(int c = 0; c<4; c++){
            dfs(n, m, mat, i+dx[c], j+dy[c], toggle);
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> matrix)
    {
        vector<vector<char>> mat = matrix;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(mat[i][j] == 'O') {
                        dfs(n, m, mat, i, j, '&');
                    }
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 'O') {
                    dfs(n, m, mat, i, j, 'X');
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                    if(mat[i][j] == '&') mat[i][j] = 'O';
            }
        }
        
        return mat;
    }
};
```
