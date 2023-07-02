class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> mp;
        int n = arr.size();

        for(int i = 0; i<n; i++){
            int diff = target - arr[i];
            if(mp.count(diff)){
                return {mp[diff], i};
            }
            else mp[arr[i]] = i;
        }

        return {-1, -1};
    }
};
