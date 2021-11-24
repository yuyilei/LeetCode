/*
    二分查找，注意边界条件
*/
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 0, right = maxSum+1; 
        int res = 0; 
        while (left < right) {
            int mid = (left + right) / 2; 
            long leftSum = getSum(mid, index+1); 
            long rightSum = getSum(mid, n-index); 
            long curSum = leftSum + rightSum - mid;
            if (curSum <= maxSum) {
                res = max(mid, res);
                left = mid+1;
            }
            else {
                right = mid; 
            }
        }
        return res;
    }
private: 
    long getSum(long max, long len) {
        long sum = 0;
        if (max >= len) {
            sum = (2*max-len+1)*len/2;
        }
        else {
            sum = (max+1)*max/2 + (len-max);
        }
        return sum; 
    }
};
