```
1
5 3
1
2
8
4
9
```

```
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl  "\n"

void solve()
{
	int n,c; cin>>n>>c;
	int arr[n];
	int maxi{0}; int mini{1000000001};
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(arr[i]>maxi) maxi = arr[i];
		if(arr[i]<mini) mini = arr[i];
	}
	sort(arr,arr+n);
	int low = 1; int high = (maxi-mini);
	while(low<=high){
		int mid = (low+high)/2;
		int lastp = arr[0];
		int number = 1;
		for(int i=1; i<n; i++){
			if(arr[i]-lastp>=mid){
				lastp = arr[i];
				number++;
			}
			if(number == c) break;
		}
		if(number==c) low = mid+1;
		else high = mid-1;
	}
	cout<<high<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif		

	int t; cin>>t;
	while(t--){
		solve();	
	}
	
	return 0;
}
```
