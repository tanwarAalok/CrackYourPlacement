class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> dr(row, -1), dc(col, -1);

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(matrix[i][j] == 0){
                    dr[i] = 0;
                    dc[j] = 0;
                }
            }
        }

        for(int i = 0; i<row; i++){
            if(dr[i] == 0){
                for(int j=0; j<col; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0; i<col; i++){
            if(dc[i] == 0){
                for(int j=0; j<row; j++){
                    matrix[j][i] = 0;
                }
            }
        }

    }
};
