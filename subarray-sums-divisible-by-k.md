# Subarray Sums Divisible by K

![Screenshot 2023-07-03 215457](https://github.com/tanwarAalok/CrackYourPlacement/assets/78805153/bab4cff5-b665-4e6d-ba5f-8ec9af375022)

```
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
```

```
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> hash;
        hash[0] = 1;

        int cnt = 0, sum = 0, r;
        for(int num : nums){
            sum += num;

            r = (sum%k + k) % k;

            cnt += hash[r];

            hash[r]++;
        }

        return cnt;
    }
};
```
