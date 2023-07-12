```
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int last3 = nums[n-1]*nums[n-2]*nums[n-3];
        int first3 = nums[0]*nums[1]*nums[2];

        int first1_last2 = nums[0]*nums[n-1]*nums[n-2];
        int first2_last1 = nums[0]*nums[1]*nums[n-1];
        

        return max(last3, max(first3, max(first1_last2, first2_last1)));
    }
};
```
