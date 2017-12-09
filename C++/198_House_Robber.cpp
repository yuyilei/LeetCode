class Solution {
public:
    int rob(vector<int>& nums) {
        if ( nums.size() == 0 ) 
            return 0 ; 
        if ( nums.size() == 1 ) 
            return nums[0] ; 
        int res = 0 ; 
        int tmp[nums.size()] ; 
        tmp[0] = nums[0] ; 
        tmp[1] = max(nums[0],nums[1]) ; 
        for ( int i = 2 ; i < nums.size() ; i++ )
            tmp[i] = max(tmp[i-1],tmp[i-2]+nums[i]) ; 
        return tmp[nums.size()-1] ; 
    }
};