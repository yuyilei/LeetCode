/*
给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。

示例 1:

输入: [2,2,3,4]
输出: 3
解释:
有效的组合是:
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
注意:

数组长度不超过1000。
数组里整数的范围为 [0, 1000]。

*/

// 法一：
// 先排序
// 先确定两个较短边，再寻找最长边
// 时间复杂度：O(n*logn)+O(n^3)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if ( nums.size() < 3 )
            return 0;
        int res = 0;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j, k;
        while ( i < len && nums[i] == 0 )     // 跳过所有0
            i++;
        for ( ; i < len - 2 ; i++ ) {
            for ( j = i + 1 ; j < len - 1 ; j++ ) {
                for ( k = j + 1 ; k < len ; k++ ) {
                    if ( nums[k] >= nums[j] + nums[i] )
                        break;
                    res++;
                }
            }
        }
        return res;
    }
}


// 法二:
// 先排序
// 先确定最大边，再确定两条较小边
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        int res = 0;
        int len = nums.size();
        int last = 0;
        sort(nums.begin(), nums.end());
        while ( last < len && nums[last] == 0 )  // 跳过所有0
            last++;
        for ( int i = 2 ; i < len ; i++ ) {
            int left = last;
            int right = i - 1;
            while ( left < right ) {
                if ( nums[left] + nums[right] > nums[i] ) {      // 说明所有left到right-1的边都能与nums[right]和nums[i]组成三角形
                    res += (right - left);
                    right--;
                }
                else {
                    left++;        // 增加left，以增大nums[left] + nums[right]
                }
            }
        }
        return res;
    }
};
