# largest-rectangle-in-histogram

![img](https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg)
```
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
```
![img](https://lh5.googleusercontent.com/oaeAuE8CGysBUJ3ZKkuYAhFsafVxhRaqDLkyQ1FmuLEPJDt3GfxELltO5ges15F79WYzyMEDErnEpV_FDwyECQMeW6-QiBEogB_dlpe9-rxFXInd4xnf7akUIBHPIxmfaTrBg4uk)
```
class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;

        stack<int> st;
        
        int leftsmall[n], rightsmall[n];

        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) leftsmall[i] = 0;
            else leftsmall[i] = st.top() + 1;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) rightsmall[i] = n-1;
            else rightsmall[i] = st.top() - 1;
            st.push(i);
        }

        for(int i = 0; i<n; i++){
            int curr = (rightsmall[i] - leftsmall[i] + 1) * heights[i];
            ans = max(ans, curr);
        }

        return ans;
    }
};
```
