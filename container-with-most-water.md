# Container With Most Water

![figure](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)
```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```

```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        
        int res = INT_MIN;
        
        while(l < r){
            int lh = height[l], rh = height[r];
            
            int area = min(lh, rh) * (r - l);
            res = max(res, area);
            
            if(lh < rh) l++;
            else r--;
        }
        
        return res;
    }
};
```
