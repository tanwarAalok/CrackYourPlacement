```
class Solution{
    public:
    long long int minSum(int a[], int n)
    {
        sort(a, a + n);
        
        long long int num1 = 0;
        long long int num2 = 0;
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                num1 = num1 * 10 + a[i];
            else
                num2 = num2 * 10 + a[i];
        }
        
        return num2 + num1;
    }
};
```
