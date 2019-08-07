/*
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
说明：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        using E = std::pair<int, int>;
        priority_queue<E, vector<E>, greater<E>> heap;
        map<int, int> counter;
        for (int num : nums)
            counter[num]++;
        for (auto each : counter) {
            auto pair = make_pair(each.second, each.first);
            if (heap.size() == k) {
                if (pair < heap.top())
                    continue;
                heap.pop();
            }
            heap.push(pair);
        }
        while (!heap.empty()) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
