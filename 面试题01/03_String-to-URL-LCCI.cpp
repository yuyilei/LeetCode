/*
Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters,and that you are given the "true" length of the string. (Note: If implementing in Java,please use a character array so that you can perform this operation in place.)

Example 1:

Input: "Mr John Smith ", 13
Output: "Mr%20John%20Smith"
Explanation:
The missing numbers are [5,6,8,...], hence the third missing number is 8.
Example 2:

Input: "               ", 5
Output: "%20%20%20%20%20"
 

Note:

0 <= S.length <= 500000

*/


/*
 * 重新开辟一个数组
 */
class Solution {
public:
    string replaceSpaces(string S, int length) {
        string res = "";
        int size = S.size();
        int len = min(length, size);
        for (int i = 0; i < len; i++) {
            if (S[i] == ' ')
                res += "%20";
            else
                res += S[i];
        }
        return res;
    }
};


/*
 * 在原数组上进行修改
 */
class Solution {
public:
    string replaceSpaces(string S, int length) {
        S.resize(length);
        int count = 0;  // 记录有多少个空格
        for (char c: S)
            if (c == ' ')
                count++;
        if (count == 0)
            return S;
        int len = length + 2*count;
        S.resize(len);
        int i = length-1, j = len-1;
        while (i >= 0) {                // 从后面开始遍历
            if (S[i] != ' ') {
                S[j--] = S[i--];
            }
            else {
                S[j--] = '0';
                S[j--] = '2';
                S[j--] = '%';
                i--;
            }
        }
        return S;
    }
};
