/*
You are given a very large integer n, represented as a string,​​​​​​ and an integer digit x. The digits in n and the digit x are in the inclusive range [1, 9], and n may represent a negative number.

You want to maximize n's numerical value by inserting x anywhere in the decimal representation of n​​​​​​. You cannot insert x to the left of the negative sign.

For example, if n = 73 and x = 6, it would be best to insert it between 7 and 3, making n = 763.
If n = -55 and x = 2, it would be best to insert it before the first 5, making n = -255.
Return a string representing the maximum value of n​​​​​​ after the insertion.

 

Example 1:

Input: n = "99", x = 9
Output: "999"
Explanation: The result is the same regardless of where you insert 9.
Example 2:

Input: n = "-13", x = 2
Output: "-123"
Explanation: You can make n one of {-213, -123, -132}, and the largest of those three is -123.
 

Constraints:

1 <= n.length <= 105
1 <= x <= 9
The digits in n​​​ are in the range [1, 9].
n is a valid representation of an integer.
In the case of a negative n,​​​​​​ it will begin with '-'.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-value-after-insertion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* 对于负数，要让绝对值最小，对于整数，要让绝对值最大
 * 对于负数，找出第一个大于x的数字，将x插入到它前面
 * 对于正数，找出第一个小于x的数字，将x插入到它前面
 * 没有符合条件的数就就插入到最后
 * 对于等于x的数，掠过
 * 例如：
 * "-132" 和 3
 * "469975787943862651173569913153377" 和 3
 */
class Solution {
public:
    string maxValue(string n, int x) {
        if (n[0] == '-') {
            return getMin(n, x);
        }
        return getMax(n, x);
    }
private:
    string getMin(string n, int x) {
        int len = n.size();
        for (int i = 1; i < len; i++) {
            int cur = n[i] - '0';
            if (cur > x) {
                char cx = (char)(x + '0');
                n.insert(i, 1, cx);
                break;
            }
        }
        if (n.size() == len) {
            n += (char)(x + '0');
        }
        return n;
    }
    string getMax(string n, int x) {
        int len = n.size();
        for (int i = 0; i < len; i++) {
            int cur = n[i] - '0';
            if (cur < x) {
                char cx = (char)(x + '0');
                n.insert(i, 1, cx);
                break;
            }
        }
        if (n.size() == len) {
            n += (char)(x + '0');
        }
        return n;
    }
};
