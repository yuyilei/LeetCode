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
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        for ( int num : nums ) {
            res += to_string(num);
        }
        // 000 类似的情况只用返回一个 0 
        return (res[0] == '0') ? "0" : res;
    }
private:
    // 利用 string 比较的特性 
    static bool cmp(int a, int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
};
