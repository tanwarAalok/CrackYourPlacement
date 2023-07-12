```
Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
```

```
class Solution{
  public:
  
    int maxRec(int row[], int m){
        stack<int> st;
        int top_val = 0, max_area = 0, area = 0, i = 0;
        
        while(i < m){
            if(st.empty() || row[st.top()] <= row[i]) st.push(i++);
            else {
                top_val = row[st.top()];
                st.pop();
                area = top_val * i;
                
                if(!st.empty()){
                    area = top_val * (i - st.top() - 1);
                }
                
                max_area = max(area, max_area);
            }
        }
        
        while(!st.empty()){
            top_val = row[st.top()];
            st.pop();
            area = top_val * i;
            
            if(!st.empty()){
                area = top_val * (i - st.top() - 1);
            }
            
            max_area = max(area, max_area);
        }
        
        return max_area;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int res = maxRec(M[0], m);
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                if(M[i][j]) M[i][j] += M[i-1][j];
            }
            res = max(res, maxRec(M[i], m));
        }
        
        return res;
    }
};
```
