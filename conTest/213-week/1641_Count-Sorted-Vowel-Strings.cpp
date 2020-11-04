/*
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
Example 3:

Input: n = 33
Output: 66045
 

Constraints:

1 <= n <= 50 


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-sorted-vowel-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int countVowelStrings(int n) {
        if (n == 1) return 5;
        if (n == 2) return 15;
        vector<int> tmp (5, 0);
        for (int i = 0; i < 5; i++)
            tmp[i] = i+1;
        for (int i = 3; i <= n+1; i++) {
            int sum = 1;
            for (int j = 1; j < 5; j++) {
                sum += tmp[j];
                tmp[j] = sum;
            }
        }
        return tmp[4];
    }
};
