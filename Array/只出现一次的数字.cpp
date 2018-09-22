/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
*/

/*
任何数和自己本身异或得到0，和自己本身异或得到0 
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0; 
        for ( auto each : nums ) {
            res ^= each; 
        }
        return res;
    }
};