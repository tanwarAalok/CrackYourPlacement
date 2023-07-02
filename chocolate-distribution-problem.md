# Chocolate Distribution Problem

```
Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3 
Output: Minimum Difference is 2 
Explanation:
We have seven packets of chocolates and we need to pick three packets for 3 students 
If we pick 2, 3 and 4, we get the minimum difference between maximum and minimum packet sizes.
```
#### Approach: Just sort the array and find min diff of max and min by running loop from 1 to  n - m + 1;
### TC - O(nlogn)

```
#include <bits/stdc++.h>
using namespace std;

int findMinDiff(int arr[], int n, int m)
{
	if (m == 0 || n == 0)
		return 0;

	sort(arr, arr + n);
  
	if (n < m)
		return -1;

	int min_diff = INT_MAX;

	for (int i = 0; i + m - 1 < n; i++) {
		int diff = arr[i + m - 1] - arr[i];
		if (diff < min_diff)
			min_diff = diff;
	}
	return min_diff;
}

int main()
{
	int arr[] = { 12, 4, 7, 9, 2, 23, 25, 41, 30,
				40, 28, 42, 30, 44, 48, 43, 50 };
	int m = 7; // Number of students
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum difference is "
		<< findMinDiff(arr, n, m);
	return 0;
}


```
