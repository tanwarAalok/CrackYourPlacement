```
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int nums[], int n) 
    { 
        priority_queue <int, vector<int>, greater<int> > pq;
        
        for(int i = 0; i<n; i++) {
            if(nums[i] > 0) pq.push(nums[i]);
        }
        
        for(int i = 1; i<=n; i++){
            if(!pq.empty() && pq.top() == i) {
                while(!pq.empty() && pq.top() == i) pq.pop();
            }
            else return i;
        }
        
        return n+1;
    } 
};
```

```
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int nums[], int n) 
    { 
        bool contains = false;

        for(int i = 0; i<n ;i++) {
            if(nums[i] == 1) {
                contains = true;
                break;
            }
        }

        if(!contains) return 1;

        for(int i = 0; i<n; i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = 1;
            }
        }

        for(int i = 0; i<n; i++){
            int temp = abs(nums[i]);

            if(temp == n){
                nums[0] = -abs(nums[0]);
            }
            else {
                nums[temp] = -abs(nums[temp]);
            }
        }

        for(int i = 1; i<n; i++){
            if(nums[i] > 0) return i;
        }

        if(nums[0] > 0) return n;

        return n+1;
    } 
};
```
