/*
给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

你找到的子数组应是最短的，请输出它的长度。

示例 1:

输入: [2, 6, 4, 8, 10, 9, 15]
输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
说明 :

输入的数组长度范围在 [1, 10,000]。
输入的数组可能包含重复元素 ，所以升序的意思是<=。
*/

// 一、
// 排序，然后比较索引，双指针
// left是从左到右第一个原数组与排序后的数组的不同的位置
// right是从右到左第一个原数组与排序后的数组不同的位置
// 注意，如果原数组是有序的，返回0
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if ( nums.empty() )
            return 0;
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int left = 0, right = nums.size()-1;
        while ( left < right && temp[left] == nums[left] )
            left++;
        while ( left < right && temp[right] == nums[right] )
            right--;
        return (left == right) ? 0 : right - left + 1;
    }
};


// 二、
// 原地
// maxval是从左到右的最大值，在从左到右遍历的过程中，如果发现当前值小于maxval，就把i赋值给right，结束遍历之后，right后面的是有序的
// 同理，minval是从右到左的最小值；在从右到左的遍历过程中，如果发现当前值大于minval，就把i赋值给left，结束遍历之后，left前面的是有序的
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if ( nums.empty() )
            return 0;
        int left = 1, right = 0;
        int maxval, minval;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            if ( i == 0 )
                maxval = nums[i];
            else {
                if ( nums[i] < maxval )
                    right = i;
                maxval = max(maxval, nums[i]);
            }
        }
        for ( int i = nums.size()-1 ; i >= 0 ; i-- ) {
            if ( i == nums.size()-1 )
                minval = nums[i];
            else {
                if ( nums[i] > minval )
                    left = i;
                minval = min(minval, nums[i]);
            }
        }
        return right-left+1;
    }
};
