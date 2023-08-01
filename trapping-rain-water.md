```
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;

        vector<int> leftHigh(n, 0), rightHigh(n, 0);
        leftHigh[0] = height[0];
        rightHigh[n-1] = height[n-1];

        for(int i = 1; i<n; i++){
            leftHigh[i] = max(leftHigh[i-1], height[i]);
        }
        for(int i = n-2; i>=0; i--){
            rightHigh[i] = max(rightHigh[i+1], height[i]);
        }

        for(int i = 0; i<n; i++){
            int water = min(leftHigh[i], rightHigh[i]) - height[i];
            if(water > 0) ans += water; 
        }
        return ans;

    }
};
```
