```
class Solution {
public:

    void dfs(vector<vector<int>>& image, int i, int j,int check, int color, vector<vector<int>> &vis){
        int n = image.size(), m = image[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m || image[i][j] != check || vis[i][j] == 1) return;

        vis[i][j] = 1;
        image[i][j] = color;

        dfs(image, i+1, j, check, color, vis); 
        dfs(image, i-1, j, check, color, vis);
        dfs(image, i, j+1, check, color, vis);
        dfs(image, i, j-1, check, color, vis);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        if(image[sr][sc] == color) return image;

        dfs(image, sr, sc, image[sr][sc], color, vis);

        return image;
    }
};
```
