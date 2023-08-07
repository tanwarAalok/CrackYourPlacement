```
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int i = 0, j = 0;

        while(i < neededTime.size() && j < neededTime.size()){
            int curr = 0, currMax = 0;

            while(j < neededTime.size() && colors[i] == colors[j]){
                curr += neededTime[j];
                currMax = max(currMax, neededTime[j]);
                j++;
            }

            ans += curr - currMax;
            i = j;
        }        

        return ans;
    }
};
```
