```
class Solution {
public:
    int bitCount(int n){
        int cnt = 0;
        while(n){
            cnt++;
            n = n & (n-1);
        }
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int> bits(n+1, 0);
        
        for(int i = 0; i<=n; i++){
            bits[i] = bitCount(i);
        }
        
        return bits;
    }
};
```
