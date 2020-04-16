/*
Given an array of string words. Return all strings in words which is substring of another word in any order. 

String words[i] is substring of words[j], if can be obtained removing some characters to left and/or right side of words[j].

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
It's guaranteed that words[i] will be unique.

*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        int len = words.size();
        sort(words.begin(), words.end(), cmp);
        for (int i = 0; i < len-1; i++) {
            for (int j = len-1; words[i].size() < words[j].size(); j--) {
                int pos = words[j].find(words[i]);
                if (pos != string::npos) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
private:
    static bool cmp(string a, string b) {
        if (a.size() < b.size())
            return true;
        return false;
    }
};
