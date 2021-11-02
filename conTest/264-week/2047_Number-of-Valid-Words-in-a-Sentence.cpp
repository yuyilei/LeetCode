class Solution {
public:
    int countValidWords(string sentence) {
        int res = 0; 
        sentence += " "; 
        int len = sentence.size(); 
        int left = 0, right = 0; 
        while (left < len && sentence[left] == ' ') {
            left++; 
        }
        right = left + 1;
        while (right < len) {
            char cur = sentence[right];
            if (cur == ' ') {
                string tmp = sentence.substr(left, right-left); 
                if (isValidToken(tmp)) 
                    res++; 
                while (right < len && sentence[right] == ' ') 
                    right++; 
                left = right; 
            }
            right++; 
        }
        return res;
    }
private: 
    bool isValidToken(string s) {
        int len = s.size();
        bool hasHyphen = false;
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9') 
                return false; 
            if (s[i] == '!' || s[i] == '.' || s[i] == ',') {
                if (i != len-1 && len != 1) 
                    return false;
            }
            if (s[i] == '-') {
                if (hasHyphen) 
                    return false; 
                hasHyphen = true; 
                if (i == 0 || i == len-1) 
                    return false; 
                if (s[i-1] < 'a' || s[i-1] > 'z') 
                    return false; 
                if (s[i+1] < 'a' || s[i+1] > 'z') 
                    return false;
            }
        }
        return true; 
    }
};