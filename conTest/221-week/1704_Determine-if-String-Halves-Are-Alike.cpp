/*
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
Example 3:

Input: s = "MerryChristmas"
Output: false
Example 4:

Input: s = "AbCdEfGh"
Output: true
 

Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/determine-if-string-halves-are-alike
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.size();
        bool res = false;
        set<char> v {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int sum = 0;
        for (int i = 0; i < len / 2; i++) {
            char cur = s[i];
            if (v.find(cur) != v.end()) {
                sum++;
            }
        }
        for (int i = len/2; i < len; i++) {
            char cur = s[i];
            if (v.find(cur) != v.end()) {
                sum--;
                if (sum < 0)
                    return false;
            }
        }
        return sum == 0;
    }
};
