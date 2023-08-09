```
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int n = s.size();

        for(int i = 0; i<n; i++){
            if(s[i] == ']') {
                string temp = "";
                while(st.top() != '['){
                    temp += st.top();
                    st.pop();
                }
                st.pop();

                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num += st.top();
                    st.pop();
                }

                reverse(num.begin(), num.end());

                int k = stoi(num);

                reverse(temp.begin(), temp.end());

                string str = temp;
                for(int j = 0; j<k-1; j++){
                    temp += str;
                }

                for(int i = 0; i<temp.size(); i++) st.push(temp[i]);
            }
            else{
                st.push(s[i]);
            }
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
```
