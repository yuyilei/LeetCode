class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size(); 
        vector<int> tmp (len1+len2,0); 
        for ( int i = len1 - 1 ; i >= 0 ; i-- ) {
            for ( int j = len2 - 1 ; j >= 0 ; j-- ) {
                tmp[i+j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        int last = 0; 
        string res = "";
        for ( int i = len1+len2-2 ; i >= 0 ; i-- ) {
            int nextlast = ( tmp[i] + last ) / 10;
            tmp[i] = ( tmp[i] + last ) % 10; 
            res = (char)('0' + tmp[i]) + res; 
            last = nextlast; 
        }
        if ( last != 0 ) {
            res = (char)('0' + last) + res; 
        }
        int start = 0; 
        for ( ; start < res.size() - 1 ; start++ )  
            if ( res[start] != '0' ) 
                break; 
        return res.substr(start,res.size()-start);
    }
};