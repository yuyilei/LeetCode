/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        if (digits.empty())
            return res;
        digits.back()++;
        int pre = 0;
        for (int i = digits.size()-1; i >= 0; i--) {
            int now = digits[i];
            res.push_back((now+pre)%10);
            pre = (now+pre)/10;
        }
        if (pre)
            res.push_back(pre);
        reverse(res.begin(), res.end());
        return res;
    }
};
