# Merge-sorted-array

```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
```


```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;

        int l1 = 0;
        for(l1 = 0; l1<m; l1++){
            if(nums1[l1] > nums2[0]){
                swap(nums1[l1], nums2[0]);
                sort(nums2.begin(), nums2.end());
            }
        }
        for(int l2 = 0; l2<n; l2++){
            nums1[l1++] = nums2[l2];
        }

    }
};
```
