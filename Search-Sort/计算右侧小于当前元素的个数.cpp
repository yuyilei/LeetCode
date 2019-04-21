/*
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例:

输入: [5,2,6,1]
输出: [2,1,1,0] 
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.
*/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res (nums.size());
        vector<int> tmp;
        // 从右往左，每次取出一个元素，通过二分法插入另外一个数组，使其保持有序 
        for ( int i = nums.size()-1; i >= 0 ; i-- ) {
            int now = nums[i];
            int left = 0, right = tmp.size()-1;
            while ( left <= right ) {
                int mid = (left + right) / 2;
                if ( tmp[mid] < now )
                    left = mid+1;
                else
                    right = mid-1;
            }
            res[i] = left;
            tmp.insert(tmp.begin()+left, nums[i]);
        }
        return res;
    }
};
