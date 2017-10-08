/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static int cmp ( Interval a , Interval b ) {
        return a.start < b.start ; 
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval) ; // 先插入，然后就和上一题的解法一样 
        if ( intervals.size() <= 1 )  
            return intervals ; 
        vector<Interval> res ;  
        sort(intervals.begin(),intervals.end(),cmp) ; 
        Interval first = intervals[0] ; 
        for ( int i = 1 ; i < intervals.size() ; i++ ) {
            if ( first.end < intervals[i].start ) {
                res.push_back(first) ; 
                first = intervals[i] ; 
                continue ; 
            } 
            first.end = max(first.end,intervals[i].end) ; 
        } 
        res.push_back(first) ; 
        return res ; 
    }
};