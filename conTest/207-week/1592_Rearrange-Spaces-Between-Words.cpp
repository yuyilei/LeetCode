/*
You are given a string text of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by at least one space. It's guaranteed that text contains at least one word.

Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent words and that number is maximized. If you cannot redistribute all the spaces equally, place the extra spaces at the end, meaning the returned string should be the same length as text.

Return the string after rearranging the spaces.

 

Example 1:

Input: text = "  this   is  a sentence "
Output: "this   is   a   sentence"
Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.
Example 2:

Input: text = " practice   makes   perfect"
Output: "practice   makes   perfect "
Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space. We place this extra space at the end of the string.
Example 3:

Input: text = "hello   world"
Output: "hello   world"
Example 4:

Input: text = "  walks  udp package   into  bar a"
Output: "walks  udp  package  into  bar  a "
Example 5:

Input: text = "a"
Output: "a"
 

Constraints:

1 <= text.length <= 100
text consists of lowercase English letters and ' '.
text contains at least one word.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rearrange-spaces-between-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> v;
        string tmp = "", res = "";
        int len = text.size();
        int space = len;
        for (int i = 0; i < len; i++) {
            if (text[i] != ' ') {
                tmp += text[i];

            }
            if (tmp.size() != 0 && (text[i] == ' ' || i == len-1)) {
                v.push_back(tmp);
                space -= tmp.size();
                tmp = "";
            }
        }
        int word = v.size();
        int avar = (word != 1) ? (space/(word-1)) : 0;
        int extra = (word != 1) ? (space%(word-1)) : space;
        string avar_space = "", extra_space = "";
        for (int i = 0; i < avar; i++)
            avar_space += " ";
        for (int i = 0; i < extra; i++)
            extra_space += " ";
        for (int i = 0; i < word; i++) {
            res += v[i];
            if (i != word-1)
                res += avar_space;
        }
        res += extra_space;
        return res;
    }
};
