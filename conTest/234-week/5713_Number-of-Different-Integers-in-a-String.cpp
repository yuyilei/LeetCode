/*
You are given a string word that consists of digits and lowercase English letters.

You will replace every non-digit character with a space. For example, "a123bc34d8ef34" will become " 123  34 8  34". Notice that you are left with some integers that are separated by at least one space: "123", "34", "8", and "34".

Return the number of different integers after performing the replacement operations on word.

Two integers are considered different if their decimal representations without any leading zeros are different.

 

Example 1:

Input: word = "a123bc34d8ef34"
Output: 3
Explanation: The three different integers are "123", "34", and "8". Notice that "34" is only counted once.
Example 2:

Input: word = "leet1234code234"
Output: 2
Example 3:

Input: word = "a1b01c001"
Output: 1
Explanation: The three integers "1", "01", and "001" all represent the same integer because
the leading zeros are ignored when comparing their decimal values.
 

Constraints:

1 <= word.length <= 1000
word consists of digits and lowercase English letters.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-different-integers-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int numDifferentIntegers(string word) {
        word += 'a';
        unordered_set<string> s;
        int len = word.size();
        int start = 0, cur = 0;
        for ( ; cur < len; cur++) {
            if ((cur > 0) && isLetter(word[cur-1]) && !isLetter(word[cur])) {
                start = cur;
            }
            if ((cur > 0) && !isLetter(word[cur-1]) && isLetter(word[cur])) {
                while (start < cur-1 && word[start] == '0')
                    start++;
                string sub = word.substr(start, cur-start);
                s.insert(sub);
            }
        }
        return (int)s.size();
    }
private:
    bool isLetter(char c) {
        if (c >= 'a' && c <= 'z')
            return true;
        return false;
    }
};
