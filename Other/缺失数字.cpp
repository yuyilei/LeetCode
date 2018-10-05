/*
 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        for ( int num : nums ) {
            sum -= num;
        }
        return sum;
    }
};
