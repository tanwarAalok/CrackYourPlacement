```
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int res = 0, pre = 0;
        unordered_map<int,int> hash;
        
        for(int i = 0; i<n; i++){
            pre += A[i];
            
            if(pre == 0) res = i+1;
            
            if(hash.count(pre)){
                res = max(res, i - hash[pre]);
            }
            else hash[pre] = i;
        }
        
        return res;
    }
};
```
