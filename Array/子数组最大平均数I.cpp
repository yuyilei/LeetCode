/*
给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

示例 1:

输入: [1,12,-5,-6,50,3], k = 4
输出: 12.75
解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 

注意:

1 <= k <= n <= 30,000。
所给数据范围 [-10,000，10,000]。

*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < k)
            return 0;
        double sum = 0;
        int i = 0;
        while ( i < k )
            sum += (double)nums[i++];
        double res = sum;
        for ( ; i < len ; i++ ) {
            sum -= nums[i-k];
            sum += nums[i];
            res = max(res, sum);
        }
        return  res/(double)k;
    }
};
