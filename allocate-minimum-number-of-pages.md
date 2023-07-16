```
Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113,
which is selected as the output.
```

```
class Solution 
{
    public:
    
    int countStudents(int A[], int pages, int n){
        int students = 1;
        long long pagesStudent = 0;
        for(int i = 0; i<n; i++){
            if(pagesStudent + A[i] <= pages) {
                pagesStudent += A[i];
            }
            else {
                students++;
                pagesStudent = A[i];
            }
        }
        return students;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M > N) return -1;
        int low = *max_element(A, A + N);
        int high = accumulate(A, A + N, 0);
        
        while(low <= high){
            int mid = (low + high) / 2;
            
            int students = countStudents(A, mid, N);
            
            if(students > M){
                low = mid + 1;
            }
            else high = mid-1;
        }
        
        return low;
    }
};
```
