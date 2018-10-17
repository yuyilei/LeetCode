/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。
*/

// 思路:
// 如果三个数之和是0的话，一定有一个非正数。
// 将数组排序之后，遍历数组
// 遍历每一个非正数，找出剩下两个数相加为0，剩下两个数从这个非正数的右边开始寻找
// 设左右指针，左指针从这个非正数的右边第一个开始从左到右，右指针从数组的最右边开始从右往左，如果三数相加为0，则加入res
// 去重：题目要求不能有重复的三元组，就对于每一个数，如果它与它相邻的数相等，就跳过
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            if ( nums[i] > 0 )
                break;
            if ( i > 0 && nums[i] == nums[i-1] )
                continue;
            int t = -nums[i];
            int left = i + 1, right = nums.size()-1;
            while ( left < right ) {
                if ( nums[left] + nums[right] == t ) {
                    res.push_back({nums[i],nums[left],nums[right]});
                    while ( left < right && nums[left] == nums[left+1] )
                        left++;
                    while ( left < right && nums[right] == nums[right-1] )
                        right--;
                    left++; right--;
                }
                else if ( nums[left] + nums[right] < t ) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return res;
    }
};
