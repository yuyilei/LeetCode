/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。
*/

// jump[i] 表示 能否到达 i 处
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if ( nums.empty() )
            return false;
        int len = nums.size(), max_index = 0;
        int i, j;
        vector<bool> jump (len,false);
        jump[0] = true;
        for ( i = 0 ; i < len ; i++ ) {
            if ( !jump[i] )
                continue;
            for ( j = max_index ; j < len && j <= i + nums[i] ; j++ ) {
                jump[j] = true;
            }
            max_index = j-1;
            if ( max_index == len - 1 )
                return true;
        }
        return false;
    }
};
