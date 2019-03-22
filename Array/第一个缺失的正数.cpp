/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
说明:

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
*/

/*
 从题意可知，长度为n的数组中没有出现的最小正整数的范围是1～n
 通过不停的交换，将数 nums[i] 交换到 位置num[i]-1 上
 其中，对于 nums[i] < 0 或 nums[i] >= n 的数不进行交换，因为数组中没有这样的位置
 最后，找出 第一个 nums[i] != i+1 的数，i+1 就是没有出现的最小正整数 
 如果全部的 nums[i] == i+1，说明数组中的数连续，且为1~n，所以答案为 n+1 
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if ( nums.empty() ) 
            return 1;
        int len = nums.size();
        for ( int i = 0 ; i < len ; i++ ) {
            while ( nums[i] > 0 && nums[i] <= len && nums[nums[i]-1] != nums[i] ) {
                swap(nums, i, nums[i]-1);
            }
        }
        for ( int i = 0 ; i < len ; i++ ) {
            if ( nums[i] != i + 1 ) 
                return i + 1;
        }
        return len + 1;
    }
private:
    void swap(vector<int> &nums, int x, int y) {
        int tmp = nums[x];
        nums[x] = nums[y];
        nums[y] = tmp;
    }
};
