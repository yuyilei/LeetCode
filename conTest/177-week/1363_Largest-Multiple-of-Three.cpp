/*
Given an integer array of digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order.

Since the answer may not fit in an integer data type, return the answer as a string.

If there is no answer return an empty string.

 

Example 1:

Input: digits = [8,1,9]
Output: "981"
Example 2:

Input: digits = [8,6,7,1,0]
Output: "8760"
Example 3:

Input: digits = [1]
Output: ""
Example 4:

Input: digits = [0,0,0,0,0,0]
Output: "0"
 

Constraints:

1 <= digits.length <= 10^4
0 <= digits[i] <= 9
The returning answer must not contain unnecessary leading zeros.

*/



/*
 * 思路：
  1. 能被3整除的数各位数的总和也能被3整除
  2. 先对所有数字从小到到大进行排序，如果排序后最大的数为0，那么直接返回0即可
  3. 算出所有数字的总和sum，同时记录digits中除3余一和除3余二的数的索引，分别存到index1, index2 (由下文可知，最多存两个即可)
    3.1 如果sum能被3整除，那么digits里的所有数都能参与组合
    3.2 如果 sum % 3 == 1, 是由，digits里一个除3余一的数( 1%3 = 1)或两个除3余二的数( (2+2)%3 =1)造成的，需要去除
    3.3 如果 sum % 3 == 2, 是由，digits里一个除3余二的数( 2%3 = 2)或两个除3余一的数( (1+1)%3 =2)造成的，需要去除
  4. 将处理好的digits数组中的数进行组合


 */

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        if (digits.back() == 0) {
            return "0";
        }
        vector<int> index1;
        vector<int> index2;
        int sum = 0;
        int i = 0;
        for (int num: digits) {
            sum += num;
            if (num % 3 == 1 && index1.size() < 2) {
                index1.push_back(i);
            }
            if (num % 3 == 2 && index2.size() < 2) {
                index2.push_back(i);
            }
            i++;
        }
        // 余1，可能是一个余1的数，或两个余2的数
        // 余2，可能是一个余2的数，或两个余1的数
        if (sum % 3 != 0 && index1.empty() && index2.empty()) {
            return "";
        }
        // 对需要去除的元素标记为-1
        if (sum % 3 == 1) {
            if (index1.size() >= 1) {
                digits[index1[0]] = -1;
            }
            else if (index2.size() >= 2){
                digits[index2[0]] = -1;
                digits[index2[1]] = -1;
            }
            else {
                return "";
            }
        }
        else if (sum % 3 == 2) {
            if (index2.size() >= 1) {
                digits[index2[0]] = -1;
            }
            else if (index1.size() >= 2){
                digits[index1[0]] = -1;
                digits[index1[1]] = -1;
            }
            else {
                return "";
            }
        }
        string res = "";
        for (int i = digits.size()-1; i >= 0; i--) {
            if (digits[i] != -1)
                res = res + to_string(digits[i]);
        }
        return res;
    }
};
