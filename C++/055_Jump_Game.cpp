// 解法一： 从头出发，jump 表示当前点能跳的最远距离，每次向前走一步jump就减1 , 如果 jump加当前位置i大于终点，就说明可以到达
// 每走一步判断是否可以到达终点，如果不能到达终点，而且jump==0就说明不可能到达终点 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = -1 , len = nums.size() ; 
        for  ( int i = 0 ; i < len ; i++ ) {
            jump = ( nums[i] > jump ) ? nums[i] : jump ;  
            if ( jump + i >= len - 1 ) 
                return true ; 
            if ( jump == 0 ) 
                return false ; 
            jump-- ; 
        }
        return false ; 
    }
};


// 解法二： 从后往前，每次判断能否到达lastindex 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastindex = nums.size() - 1 ; 
        for ( int i = nums.size() - 2 ; i >= 0 ; i-- ) {
            if ( nums[i] + i >= lastindex ) 
                lastindex = i ; 
        } 
        return lastindex == 0 ; 
    }
};