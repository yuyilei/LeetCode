/*
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
说明：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if ( nums.empty() )
            return {};
        vector<int> res;
        unordered_map<int, int> counter;
        priority_queue<pair<int, int>> q;   // 大顶堆
        for ( int num : nums )
            counter[num]++;
        for ( auto each : counter )
            q.push({each.second, each.first});   // 先根据出现的次数进行排序 
        for ( int i = 0 ; i < k ; i++ ) {
            res.push_back(q.top().second);       // second是所代表的元素 
            q.pop();
        }
        return res;
    }
};



// 改为小顶堆，就可以求低频词汇 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if ( nums.empty() ) 
            return {};
        vector<int> res;
        unordered_map<int, int> counter;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > q;  // 小顶堆 
        for ( int num : nums ) 
            counter[num]++;
        for ( auto each : counter ) 
            q.push({each.second, each.first});
        for ( int i = 0 ; i < k ; i++ ) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
