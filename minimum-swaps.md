```
Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explaination:
swap 10 with 3 and swap 19 with 5.
```

```
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    
	    vector<pair<int,int>> hash;
	    
	    for(int i = 0; i<nums.size(); i++) hash.push_back({nums[i], i});
	    
	    sort(hash.begin(), hash.end());
	    
	    int cnt = 0, i = 0;
	    
	    while(i<hash.size()){
	        
	        if(i == hash[i].second){
	            i++;
	        }
	        else {
	            swap(hash[i], hash[hash[i].second]);
	            cnt++;  
	        }
	    }
	    
	    return cnt;
	    
	    
	}
};
```
