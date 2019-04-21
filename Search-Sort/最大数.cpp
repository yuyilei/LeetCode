/*
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:

输入: [10,2]
输出: 210
示例 2:

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 */

class Solution {
public:
    string largestNumber(vector<int>& n) {
        vector<string> nums;
        for ( int each : n )
            nums.push_back(to_string(each));
        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        for ( string num : nums )
            res += num;
        if ( res.front() == '0' )
            return "0";
        return res;
    }
private:
    static bool cmp(const string &a, const string &b) {
        return a + b > b + a;
    }
};
