/*
动态规划：乘积最大连续子序列
序列中存在负数，所以大小可能反转。
index = i 时
minn = num[0,...,i-1]序列的乘积最小（序列以num[i-1]结尾，以此保证连续）
maxx = num[0,...,i-1]序列的乘积最大（序列以num[i-1]结尾，以此保证连续）

minn = min(minn*num[i],maxx*num[i],num[i])      三者中最小值
maxx = mxx(minn*num[i],maxx*num[i],num[i])      三者中最大值
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx = nums[0] ;
        int minn = nums[0] ;
        int res = nums[0] ; 
        for ( int i = 1 ; i < nums.size() ; i++ ) {
            int a = maxx * nums[i], b = minn * nums[i] ; 
            maxx = max(max(a,b),nums[i]) ; 
            minn = min(min(a,b),nums[i]) ; 
            res = max(res,maxx) ; 
        }
        return res ; 
    }
};