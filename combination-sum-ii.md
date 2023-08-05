```
class Solution {
public:

    void f(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> curr, int idx){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        
        for(int i = idx; i<candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;

            curr.push_back(candidates[i]);
            f(candidates, target - candidates[i], ans, curr, i+1);
            curr.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;

        f(candidates, target, ans, curr, 0);

        return ans;

    }
};
```
