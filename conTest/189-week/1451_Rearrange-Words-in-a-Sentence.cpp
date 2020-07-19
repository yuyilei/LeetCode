/*
Given a sentence text (A sentence is a string of space-separated words) in the following format:

First letter is in upper case.
Each word in text are separated by a single space.
Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.

Return the new text following the format shown above.

 

Example 1:

Input: text = "Leetcode is cool"
Output: "Is cool leetcode"
Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
Output is ordered by length and the new first word starts with capital letter.
Example 2:

Input: text = "Keep calm and code on"
Output: "On and keep calm code"
Explanation: Output is ordered as follows:
"On" 2 letters.
"and" 3 letters.
"keep" 4 letters in case of tie order by position in original text.
"calm" 4 letters.
"code" 4 letters.
Example 3:

Input: text = "To be or not to be"
Output: "To be or to be not"
 

Constraints:

text begins with a capital letter and then contains lowercase letters and single space between words.
1 <= text.length <= 10^5

*/


// stable_sort 保证相等元素排序后次序不变

class Solution {
public:
    string arrangeWords(string text) {
        vector<string> tmp;
        string res = "";
        int start = 0;
        int len = text.size();
        text[0] = text[0] - 'A' + 'a';
        for (int i = 0; i < len; i++) {
            if (text[i] == ' ') {
                tmp.push_back(text.substr(start, i-start));
                start = i+1;
            }
            else if (i == len-1) {
                tmp.push_back(text.substr(start, i-start+1));
            }
        }
        stable_sort(tmp.begin(), tmp.end(), cmp);
        for (int i = 0; i < tmp.size(); i++) {
            res += tmp[i];
            if (i != tmp.size()-1)
                res += " ";
        }
        res[0] = res[0] - 'a' + 'A';
        return res;
    }
private:
    static bool cmp(string a, string b) {
        if (a.size() != b.size())
            return a.size() < b.size();
        return false;
    }
};

