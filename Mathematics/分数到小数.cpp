/*
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

如果小数部分为循环小数，则将循环的部分括在括号内。

示例 1:

输入: numerator = 1, denominator = 2
输出: "0.5"
示例 2:

输入: numerator = 2, denominator = 1
输出: "2"
示例 3:

输入: numerator = 2, denominator = 3
输出: "0.(6)"
*/

// 用map判断是否出现循环小数
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long n = numerator, d = denominator;
        bool flag = true;
        if ( n > 0 && d < 0 || n < 0 && d > 0 )
            flag = false;
        cout << flag << endl;
        n = abs(n); d = abs(d);
        string res = to_string(n/d);
        string ans = ".";
        long remainder = n % d;
         if ( remainder == 0 )
            return (flag ? "" : "-") + res;
        map<long,int> tmp;
        int pos = 1;
        bool loop = false;
        while ( remainder != 0 ) {
            if ( tmp.find(remainder) != tmp.end() ) {
                pos = tmp[remainder];
                loop = true;
                break;
            }
            tmp[remainder] = pos++;
            ans += to_string(10*remainder/d);
            remainder = (10*remainder) % d;
        }
        if ( loop ) {
            ans.insert(pos,"(");
            ans = ans + ")";
        }
        res = (flag ? "" : "-") + res + ans;
        return res;
    }
};
