```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int startRow = 0;
        int startCol = 0;
        int endRow = matrix.size()-1;
        int endCol = matrix[0].size()-1;

        //transverse condition
        while(startRow<=endRow && startCol <= endCol){
            //L to r
            for(int i=startCol;i<=endCol;++i){
                ans.push_back(matrix[startRow][i]);
            }
            startRow++;
            //u to b
            for(int i=startRow;i<=endRow;++i){
                ans.push_back(matrix[i][endCol]);
            }
            endCol--;
             if((startRow>endRow )|| (startCol>endCol))
             break;
            //r to l
            for(int i=endCol;i>=startCol;--i){
                ans.push_back(matrix[endRow][i]);
            }
            endRow--;
            //b to u
            for(int i=endRow;i>=startRow;--i){
                ans.push_back(matrix[i][startCol]);
            }
            startCol++;
        }
        return ans;
    }
};
```
