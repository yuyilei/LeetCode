class Solution {
public:
    int rob(vector<int>& nums) {
        if ( !nums.size() ) 
            return 0 ; 
        return max(getres(nums,0,nums.size()-2),getres(nums,1,nums.size()-1)) ; 
    } 
    int getres(vector<int> nums, int s, int e){
        if ( s >= e ) return nums[e] ; 
        int tmp[e-s+1] ; 
        tmp[0] = nums[s] ; 
        tmp[1] = max(nums[s],nums[s+1]) ; 
        for ( int i = s + 2 ; i <= e  ; i++ )
            tmp[i-s] = max(tmp[i-s-2]+nums[i],tmp[i-s-1]) ; 
        return tmp[e-s] ; 
    }
};