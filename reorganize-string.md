```
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for(auto c : s) freq[c - 'a']++;

        priority_queue<pair<int, int>> pq;

        for(int i = 0; i<26; i++){
            if(freq[i] > 0) pq.push({freq[i], i + 'a'});
        }

        string res;
        while(!pq.empty()){
            auto first = pq.top();
            pq.pop();

            if(res.empty() || first.second != res.back()){
                res += char(first.second);
                if(--first.first > 0) pq.push(first);
            }
            else{
                if(pq.empty()) return "";
                auto second = pq.top();
                pq.pop();

                res += char(second.second);
                if(--second.first > 0) pq.push(second);

                pq.push(first);
            }
        }

        return res;
    }
};
```
