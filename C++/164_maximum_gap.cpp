/*
利用桶排序
当所有元素均匀分布的时候，相邻数字的差的最大值最小，因此可以构造桶大小的为[(B - A) / (N - 1)] (向上取整)，
同一个桶内的元素的差一定小于桶的大小，这样就不需要管桶内的大小关系了，只需要关注每个桶的最小值和前一个非空桶的最大值之差就可以。
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if ( nums.size() <= 1 ) 
            return 0; 
        int high = 0, low = 0x7fffffff;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            high = max(high,nums[i]);
            low = min(low,nums[i]);
        }
        int average = (high-low)/nums.size() + 1;          // 假设数组是均匀排序 --> 求出平均距离，也是最小的最大距离
        int bucket_size = (high-low)/average + 1;          // 利用平均距离求出桶的个数 
        vector<int> maxn (bucket_size,low-1);
        vector<int> minn (bucket_size,high+1);
        vector<bool> flag (bucket_size,false);
        for ( int i = 0 ; i < nums.size() ; i++ ) {        // 求出每个桶中的最大最小值
            int idx = (nums[i]-low)/average;
            maxn[idx] = max(maxn[idx],nums[i]); 
            minn[idx] = min(minn[idx],nums[i]);
            flag[idx] = true;                              // 标志位记录这个桶中是否有数字
        } 
        int res = 0; 
        int last = 0;
        for ( int i = 1 ; i < bucket_size ; i++ ) {
            if ( !flag[i] ) 
                continue;
            res = max(res,minn[i]-maxn[last]);             // 最大距离是当前桶的最小值减去前一个桶的最大值，不可能在同一个桶中
            last = i; 
        }
        return res;
    }
};