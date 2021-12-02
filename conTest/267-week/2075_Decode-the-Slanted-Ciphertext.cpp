class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.size(); 
        int cols = len / rows; 
        int num = 0; 
        vector<vector<char>> v (rows , vector<char> (cols, ' ')); 
        for (int i = 0; i < len; i++) {
            char cur = encodedText[i]; 
            if (cur != ' ') {
                int r = i / cols; 
                int c = i % cols; 
                v[r][c] = cur; 
                num++; 
            }
        }
        string res = ""; 
        for (int i = 0; i < cols; i++) {
            int r = 0, c = i;
            while (r < rows && c < cols && num != 0) {
                if (v[r][c] != ' ') 
                    num--; 
                res += v[r][c]; 
                r++;
                c++; 
            }
            if (num == 0) 
                break;
        }
        return res;
    }
};