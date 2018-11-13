/*
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 // 思想：先进行排序
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        sort(intervals.begin(),intervals.end(),cmp);
        for ( auto interval : intervals ) {
            if ( res.empty() || res.back().end < interval.start )
                res.push_back(interval);
            else
                res.back().end = max(res.back().end,interval.end);
        }
        return res;
    }
private:
    static bool cmp(Interval a, Interval b ) {
        if ( a.start < b.start )
            return true;
        else if ( a.start == b.start && a.end < b.end )
            return true;
        return false;
    }
};
