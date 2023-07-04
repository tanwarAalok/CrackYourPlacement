# Word-search

![figure](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)
```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```

```
class Solution {
public:
    bool f(vector<vector<char>>& board, string word, int index, int i, int j){
        if(index == word.size()) return true;
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        int dx[4] = {0, 1, -1, 0};
        int dy[4] = {1, 0, 0, -1};

        bool res = false;
        for(int p = 0; p<4; p++){
            res = res || f(board, word, index+1, i+dx[p], j+dy[p]);
        }

        board[i][j] = temp;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        int n = board.size(), m = board[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans = ans || f(board, word, 0, i, j);
            }
        }
        return ans;
    }
};
```
