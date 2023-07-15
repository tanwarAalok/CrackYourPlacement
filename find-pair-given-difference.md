```
Input:
L = 6, N = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.
```

```
bool findPair(int arr[], int n, int k){
    
    sort(arr, arr+n);
    
    int i = 0, j = 1;
    
    while(i < n && j < n){
        int diff = arr[j] - arr[i];
        
        if(i!=j && diff == k) return true;
        
        if(diff > k) i++;
        else j++;
    }
    
    return false;
}
```
