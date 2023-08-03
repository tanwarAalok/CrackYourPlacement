```
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
```

```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> hash;

        int n = nums2.size();

        st.push(nums2[n-1]);

        hash[nums2[n-1]] = -1;

        for(int i = n-2; i>=0; i--){
            if(st.top() < nums2[i]){
                while(!st.empty() && nums2[i] > st.top()) st.pop();
                if(st.empty()) hash[nums2[i]] = -1;
                else hash[nums2[i]] = st.top();
            }
            else hash[nums2[i]] = st.top();
            st.push(nums2[i]);
        }

        vector<int> ans;

        for(auto it  : nums1) ans.push_back(hash[it]);

        return ans;
    }
};
```
