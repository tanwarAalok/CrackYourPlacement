```
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int solve(int num1, int num2, char op){
        if(op == '*') return num1*num2;
        if(op == '+') return num1+num2;
        if(op == '-') return num1-num2;
        if(op == '/') return num1/num2;
    }
    
    int evaluatePostfix(string S)
    {
        stack<int> st;
        int ans = 0;
        
        for(auto it : S){
            if(isdigit(it)) st.push(it-'0');
            else {
                int num2 = st.top();
                st.pop();
                
                int num1 = st.top();
                st.pop();
                
                int res = solve(num1, num2, it);
                ans = res;
                
                st.push(res);
            }
        }
        
        return ans;
    }
};
```
