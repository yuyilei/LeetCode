/*
 *
Given a string, write a function to check if it is a permutation of a palin­ drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

 

Example1:

Input: "tactcoa"
Output: true（permutations: "tacocat"、"atcocta", etc.）

*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> counter;
        for (char c: s) {
            counter[c]++;
        }
        int flag = 0;
        for (auto it = counter.begin(); it != counter.end(); it++) {
            if (it->second % 2 != 0) {
                flag++;
                if (flag > 1)
                    return false;
            }
        }
        return true;
    }
};


// 二
class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> counter;
        int res = 0;
        for (char c: s) {
            counter[c]++;
            if (counter[c] % 2 == 0) {   // 遇到双数减一
                res--;
            }
            else {                       // 奇数加一
                res++;
            }
        }
        return res <= 1;
    }
};
