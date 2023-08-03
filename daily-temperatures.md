```
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<pair<int,int>> st;
        vector<int> ans;

        st.push({-1, -1});

        for(int i = n-1; i>=0; i--){
           if(temp[i] >= st.top().first){
               while(!st.empty() && temp[i] >= st.top().first) st.pop();
               if(st.empty()) ans.push_back(0);
               else ans.push_back(st.top().second - i);
           }
           else ans.push_back(1);
           st.push({temp[i], i});
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
