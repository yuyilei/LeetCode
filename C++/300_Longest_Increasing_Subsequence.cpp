/*
求最长上升子序列的长度，动态规划
设 res[i]为 数组 nums[0,...,i]的最长上升子序列的长度（注意这个子序列一定包含nums[i]，这是约束条件）
动态规划函数

1) res[i] = 1            i = 1 或 不存在 res[i] > res[j] ( 0 <= j < i )    // nums[i] 单个元素作为最长上升子序列  
2) res[i] = max({res[j]+1})   对于任意 res[i] > res[j] ( 0 <= j < i )      // nums[i] 与前面的元素组成作为最长上升子序列

maxlen = max({res[i]}) 0 <= i < nums.size() 

*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size() ; 
        vector<int> res (len,1) ; 
        int maxlen = 0 ;
        for ( int i = 0 ; i < len ; i++ ) {
            for ( int j = i - 1 ; j >= 0 ; j-- ) {
                if ( nums[i] > nums[j] ) 
                    res[i] = max(res[i],res[j]+1) ; 
            }
            maxlen = max(res[i],maxlen) ; 
        }
        return maxlen ; 
    }
}; 