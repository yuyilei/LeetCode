/*
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
*/

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if ( envelopes.empty() )
            return 0;
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> nums (envelopes.size(),1);
        int res = 1;
        for ( int i = 1 ; i < envelopes.size() ; i++ ) {
            auto now = envelopes[i];
            int tmp = 0;
            for ( int j = i - 1 ; j >= 0 ; j-- ) {
                auto pre = envelopes[j];
                if ( cmp2(pre,now) ) {
                    tmp = max(tmp,nums[j]);
                }
            }
            nums[i] += tmp;
            res = max(res,nums[i]);
        }
        return res;
    }
private:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        if ( a.first < b.first )
            return true;
        if ( a.first == b.first && a.second < b.second )
            return true;
        return false;
    }
    static bool cmp2(pair<int,int> a, pair<int,int> b) {
        if ( a.first < b.first && a.second < b.second )
            return true;
        return false;
    }
};
