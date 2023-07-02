class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int count = 0, ptr = 0;
        
        for(int n : nums){
            if(n == 0) count++;
            else{
                nums[ptr++] = n;     
            }
        }
        
        while(ptr < nums.size()){
            nums[ptr++] = 0;
        }
    }
};
