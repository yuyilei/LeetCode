// 假设i到j的子数列和为最大，那么就有i到k（i<=k<=j) 中所有的和大于0，否则k到j的和大于i到j，与条件不符合 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if ( nums.size() == 0 )
            return INT_MIN ; 
        int res = nums[0] , i , len = nums.size() , tmp = 0 ; 
        for ( i = 0 ; i < len ; i++ ){
            tmp = max(0,tmp) ;  // 如果tmp小于0，就重置为0 
            tmp += nums[i] ; 
            res = max(tmp,res) ;  
        }
        return res ;
    }
};