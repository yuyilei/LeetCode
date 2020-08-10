/*
On old cell phones, users typed on a numeric keypad and the phone would provide a list of words that matched these numbers. Each digit mapped to a set of 0 - 4 letters. Implement an algo­rithm to return a list of matching words, given a sequence of digits. You are provided a list of valid words. The mapping is shown in the diagram below:



Example 1:

Input: num = "8733", words = ["tree", "used"]
Output: ["tree", "used"]
Example 2:

Input: num = "2", words = ["a", "b", "c", "d"]
Output: ["a", "b", "c"]
Note:

num.length <= 1000
words.length <= 500
words[i].length == num.length
There are no number 0 and 1 in num.


*/

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> res;
        vector<char> key;
        for (int i = 0, n = 2, cnt = 0; i < 26; i++) {
            if (n == 7 || n == 9) {
                if (cnt == 4) {
                    n++;
                    cnt = 0;
                }
            } else {
                if (cnt == 3) {
                    n++;
                    cnt = 0;
                }
            }
            key.push_back((char)('0'+n));
            cnt++;
        }
        int len = num.size();
        int size = words.size();
        for (int i = 0; i < size; i++) {
            bool flag = true;
            for (int j = 0; flag && j < len; j++) {
                if (key[words[i][j]-'a'] != num[j]) {
                    flag = false;
                }
            }
            if (flag)
                res.push_back(words[i]);
        }
        return res;
    }
};
