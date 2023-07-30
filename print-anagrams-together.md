```
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hash;
        
        
        for(string s : string_list){
            string copy = s;
            sort(copy.begin(), copy.end());
            hash[copy].push_back(s);
        }
    
        for(string s : string_list){
            string copy = s;
            sort(copy.begin(), copy.end());
            
            if(hash.count(copy)) {
                ans.push_back(hash[copy]);
                hash.erase(copy);
            }
        }
        
        return ans;
    }
};
```
