```
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&kp, vector<int>&target, int n)
	{
	    queue<pair<pair<int,int>, int>> q;
	    q.push({{kp[0],kp[1]}, 0});
	    
	    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
	    int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
	    
	    vector<vector<int>> vis(n+1, vector<int>(n+1, 0));
	    
	    int ans = INT_MAX;
	    
	    while(!q.empty()){
	        auto cord = q.front().first;
	        int moves = q.front().second;
	        q.pop();
	        
	        if(cord.first == target[0] && cord.second == target[1]) {
	            ans = min(ans, moves);
	            continue;
	        }
	        
	        for(int i = 0; i<8; i++){
	            int nx = cord.first + dx[i], ny = cord.second + dy[i];
	            
	            if(nx < 1 || nx > n || ny < 1 || ny > n || vis[nx][ny]) continue;
	            
	            q.push({{nx, ny}, moves+1});
	            vis[nx][ny] = 1;
	        }
	    }
	    
	    if(ans == INT_MAX) return -1;
	    
	    return ans;
	    
	    
	}
};
```
