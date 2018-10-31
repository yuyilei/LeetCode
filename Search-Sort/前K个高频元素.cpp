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
        map<int,int> tmp;
        vector<int> res;
        map<int,vector<int>> tmp2;
        vector<int> values;
        for ( int num : nums ) {
            if ( tmp.count(num) == 0 )
                tmp[num] = 0;
            tmp[num]++;
        }
        for ( map<int,int>::iterator it = tmp.begin() ; it != tmp.end() ; it++ ) {
            if ( tmp2.count(it->second) == 0 )
                values.push_back(it->second);
            tmp2[it->second].push_back(it->first);
        }
        sort(values.begin(),values.end());
        reverse(values.begin(),values.end());
        for ( int i = 0 ; k > 0 ; i++ ) {
            for ( int num : tmp2[values[i]] ) {
                res.push_back(num);
            }
            k -= tmp2[values[i]].size();
        }
        return res;
    }
};


// 思路2:
// 将map改为vector，相当于桶排序
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        vector<vector<int>> bucket (nums.size()+1);
        vector<int> res;
        for ( int num : nums )
            m[num]++;
        for ( map<int,int>::iterator it = m.begin() ; it != m.end() ; it++ ) {
            bucket[it->second].push_back(it->first);
        }
        for ( int i = bucket.size() - 1 ; i >= 0 ; i-- ) {
            for ( int j = 0 ; j < bucket[i].size() ; j++ ) {
                res.push_back(bucket[i][j]);
            }
            if ( res.size() == k )
                return res;
        }
    }
};
