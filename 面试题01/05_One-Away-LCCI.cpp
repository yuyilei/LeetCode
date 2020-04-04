/*
There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

 

Example 1:

Input:
first = "pale"
second = "ple"
Output: True
Example 2:

Input:
first = "pales"
second = "pal"
Output: False

*/

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int len1 = first.size();
        int len2 = second.size();
        if (abs(len1-len2) >= 2)
            return false;
        bool same = true;
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (first[i] == second[j]) {
                i++;
                j++;
            }
            else {
                if (!same)
                    return false;
                same = false;
                i++; j++;
                if (len1 < len2)
                    i--;
                else if (len1 > len2)
                    j--;
            }
        }
        return true;
    }
};
