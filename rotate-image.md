![img](https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg)

```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose of matrix
        int n = matrix.size();

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};
```
