/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?



*/

// n*logn
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        int len = nums.size()-1;
        vector<int> dp (len, 0);
        int res = 0;
        for (int num: nums) {
            int left = 0;
            int right = res;
            while (left < right) {
                int mid = (left + right)/2;
                if (nums[mid] < num)
                    left = mid+1;
                else
                    right = mid;
            }
            nums[left] = num;
            if (left == res)
                res++;
        }
        return res;
    }
};


// n^2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        int len = nums.size();
        int res = 1;
        vector<int> dp (len, 1);
        for (int i = 1;i < len; i++) {
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    tmp = max(tmp, dp[j]);
            }
            dp[i] = max(tmp+1, dp[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
