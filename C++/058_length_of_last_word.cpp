class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int index = s.size()-1;
        while (index >= 0) {
            if (s[index] != ' ')
                break;
            index--;
        }
        while (index >= 0) {
            if (s[index] == ' ') {
                break;
            }
            res++;
            index--;
        }
        return res;
    }
};
