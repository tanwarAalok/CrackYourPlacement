```
Input : 
a[] = {2, 1, 3}, 
b[] = { 7, 8, 9 }, 
k = 10. 
Output : 
True
Explanation:
Permutation  a[] = { 1, 2, 3 } 
and b[] = { 9, 8, 7 } 
satisfied the condition a[i] + b[i] >= K.
```

```
bool isPossible(long long a[], long long b[], int n, long long k) {
      // Your code goes here
      sort(a, a+n, greater<int>());
      sort(b, b+n);
      
      for(int i = 0; i<n; i++){
          if(a[i] + b[i] < k) return false;
      }
      return true;
}
```
