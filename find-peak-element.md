```
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int s = 0, e = nums.size() - 1;

        while(s <= e){
            int mid = (s+e)/2;

            if(mid == 0 && nums[mid] > nums[mid+1]) return mid;
            if(mid == nums.size()-1 && nums[mid] > nums[mid-1]) return mid;

            if(mid > 0 && mid < nums.size()-1 && nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(mid < nums.size()-1 && nums[mid+1] < nums[mid]) {
                e = mid-1;
            }
            else s = mid+1;
        }

        return -1;
    }
};
```
