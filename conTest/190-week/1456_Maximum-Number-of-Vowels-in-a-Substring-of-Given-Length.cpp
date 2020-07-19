/*
Given a string s and an integer k.

Return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are (a, e, i, o, u).

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
Example 4:

Input: s = "rhythms", k = 4
Output: 0
Explanation: We can see that s doesn't have any vowel letters.
Example 5:

Input: s = "tryhard", k = 4
Output: 1
 

Constraints:

1 <= s.length <= 10^5
s consists of lowercase English letters.
1 <= k <= s.length

*/


// 利用queue
class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> vowel {'a', 'e', 'i', 'o', 'u'};
        queue<int> pre;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (vowel.find(s[i]) != vowel.end()) {
                pre.push(i);
                while (!pre.empty() && i-pre.front()+1 > k) {
                    pre.pop();
                }
                int size = pre.size();
                res = max(res, size);
            }
        }
        return res;
    }
};



// 滑动窗口
class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> vowel {'a', 'e', 'i', 'o', 'u'};
        int res = 0;
        int left = 0, right = 0;
        int window = 0;
        while (right < s.size()) {
            if (vowel.find(s[right]) != vowel.end()) {
                window++;
            }
            right++;
            while (right-left > k) {
                if (vowel.find(s[left]) != vowel.end()) {
                    window--;
                }
                left++;
            }
            res = max(res, window);
        }
        return res;
    }
};
