```
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
```

```
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        stringstream ss(path);
        string currDir;

        while(getline(ss, currDir, '/')){
            if(!dir.empty() && currDir == ".."){
                dir.pop_back();
            }
            else if(currDir != "." && currDir != "" && currDir != ".."){
                dir.push_back(currDir);
            }
        }

        string simplified_path = "";
        for(string str : dir){
            simplified_path += "/" + str;
        }

        return simplified_path.empty() ? "/" : simplified_path;
    }
};



```
