```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        int curr = 0;

        while(curr <= r){
            switch(nums[curr]){
                case 0:
                    swap(nums[curr++], nums[l++]);
                    break;
                case 1: 
                    curr++;
                    break;
                case 2: 
                    swap(nums[curr], nums[r--]);
                    break;
            }
        }
    }
};
```
