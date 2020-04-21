/*
Given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple “croak” are mixed. Return the minimum number of different frogs to finish all the croak in the given string.

A valid "croak" means a frog is printing 5 letters ‘c’, ’r’, ’o’, ’a’, ’k’ sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of valid "croak" return -1.

 

Example 1:

Input: croakOfFrogs = "croakcroak"
Output: 1
Explanation: One frog yelling "croak" twice.
Example 2:

Input: croakOfFrogs = "crcoakroak"
Output: 2
Explanation: The minimum number of frogs is two. 
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".
Example 3:

Input: croakOfFrogs = "croakcrook"
Output: -1
Explanation: The given string is an invalid combination of "croak" from different frogs.
Example 4:

Input: croakOfFrogs = "croakcroa"
Output: -1
 

Constraints:

1 <= croakOfFrogs.length <= 10^5
All characters in the string are: 'c', 'r', 'o', 'a' or 'k'.

*/

// 一
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int res = 0;
        map<char, int> m;
        for (char f: croakOfFrogs) {
            m[f]++;
            if (m['c'] >= m['r'] && m['r'] >= m['o'] && m['o'] >= m['a'] && m['a'] >= m['k']) {
                res = max(res, m['c']-m['k']);
            }
            else {
                return -1;
            }
        }
        if (m['c'] == m['r'] && m['r'] == m['o'] && m['o'] == m['a'] && m['a'] == m['k'])
            return res;
        else
            return -1;
    }
};

// 二
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int res = 0;
        int tmp = 0;
        map<char, int> m = {{'c', 0}, {'r', 0}, {'o', 0}, {'a', 0}, {'k', 0}};
        map<char, int> s = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        int len = croakOfFrogs.size();
        for (int i = 0; i < len; i++) {
            char c = croakOfFrogs[i];
            if (i == len-1 && c != 'k')
                return -1;
            if (c != 'k') {
                for (auto it = m.begin(); it != m.end(); it++) {
                    if (s[it->first] > s[c] && it->second > m[c]) {
                        return -1;
                    }
                }
            }
            m[c]++;
            if (c == 'k') {
                tmp = 0;
                for (auto it = m.begin(); it != m.end(); it++) {
                    if (it->second == 0)
                        return -1;
                    tmp = max(tmp, it->second);
                }
                for (auto it = m.begin(); it != m.end(); it++) {
                    it->second--;
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
};
