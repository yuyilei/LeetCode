/*
一：
*/
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

/*
二：
更简便的写法
动态规划：
    now 是 前 i 个数 组成序列 的最优解， ppre 前 i-2个 数 的最优解
    pre 是 前 i-1 个数 的最优解 

*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int now = 0, pre = 0, ppre = 0;
        for ( int i = 0 ; i < nums.size() ; i++ ){
            now = max(ppre+nums[i],pre);
            ppre = pre;
            pre = now;
        }
        return now;
    }
}; 