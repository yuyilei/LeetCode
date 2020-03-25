/*
Given a string s. Return all the words vertically in the same order in which they appear in s.
Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
Each word would be put on only one column and that in one column there will be only one word.

 

Example 1:

Input: s = "HOW ARE YOU"
Output: ["HAY","ORO","WEU"]
Explanation: Each word is printed vertically.
 "HAY"
 "ORO"
 "WEU"
Example 2:

Input: s = "TO BE OR NOT TO BE"
Output: ["TBONTB","OEROOE","   T"]
Explanation: Trailing spaces is not allowed.
"TBONTB"
"OEROOE"
"   T"
Example 3:

Input: s = "CONTEST IS COMING"
Output: ["CIC","OSO","N M","T I","E N","S G","T"]
 

Constraints:

1 <= s.length <= 200
s contains only upper case English letters.
It's guaranteed that there is only one space between 2 words.

*/

/*
 * 1. 先按照空格分割成一个个word
 * 2. 最长word的长度就是res中元素的个数
 * find: 从前往后查找，返回第一个符合符合规则的元素的位置，否则返回-1
 * rfind: 从后往前查找，其他与find相同
 * find_first_of: 从前往后查找，找出第一个符合的位置
 * find_last_of: 从后往前查找，找出第一个符合的位置
 * find_first_not_of: 从前往后，找出第一个不相符的位置
 * find_last_not_of: 从后往前，找出第一个不相符的位置
 */
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        int len = s.size();
        int maxlen = 0;
        for (int i = 1, start = 0; i <= len; i++) {
            if (i == len || s[i] == ' ') {
                words.push_back(s.substr(start, i-start));
                maxlen = max(maxlen, i-start);
                start = i+1;
            }
        }
        vector<string> res (maxlen, "");
        for (int i = 0; i < maxlen; i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i < words[j].size()) {
                    res[i] += words[j][i];
                }
                else {
                    res[i] += " ";
                }
            }
            // 移除后面的空格
            res[i].erase(res[i].find_last_not_of(' ')+1);
        }
        return res;
    }
};
