# print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n

```

#include <bits/stdc++.h>
using namespace std;

void f(int arr[], int n, int r, int curr[], int idx, int pos){
    if(idx == r){
        for(int i = 0; i<r; i++) cout<<curr[i]<<" ";
        cout<<endl;
        return;
    }
    if(pos >= n) return;
    
    curr[idx] = arr[pos];
    f(arr, n, r, curr, idx+1, pos + 1);
    
    f(arr, n, r, curr, idx, pos + 1);
    
    
}

void combinations(int arr[], int n, int r){
    int curr[r];
    f(arr, n, r, curr, 0, 0);
}


int main()
{
    int arr[] = {1, 2, 3, 4};
    int r = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    combinations(arr, n, r);
    return 0;
}
```
