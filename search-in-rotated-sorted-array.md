```
class Solution {
public:
    int binarySearch(vector<int> nums, int target, int start , int end) {
        int mid = start + (end - start)/2;

        while(start <= end) {
            int element = nums[mid];
            if(target == element) {
                return mid;
            }
            if(target < element) {
                end = mid - 1;
            }
            else {
                start = mid +1 ;
            }
            mid = start + (end - start)/2;
        }
        return -1;
    }

    int findPivot(vector<int> arr) {
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e - s)/2;

        while(s < e) {
            if(mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
                return mid;
            if(mid - 1 >= 0 && arr[mid - 1] > arr[mid])
                return mid - 1;

            if(arr[s] >= arr[mid]) {
                e = mid - 1;
            }
            else{
                s = mid;
            }
            mid = s + (e - s)/2;

        }
        return s;
    }
    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivot(nums);
    
        if(target >= nums[0] && target <= nums[pivotIndex]) {
            return binarySearch(nums, target, 0, pivotIndex);
        }
        
        if( pivotIndex + 1 <nums.size() && target >= nums[pivotIndex+1] && target <= nums[nums.size() - 1]) {
            return binarySearch(nums, target, pivotIndex + 1, nums.size() -1);
        }

        return -1;

    }
};
```
