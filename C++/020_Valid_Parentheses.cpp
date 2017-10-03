class Solution {
public:
    bool isValid(string s) {
        if ( s.length() % 2 ) 
            return false ; 
        stack<int> z ; 
        map<char,int> mmp ; 
        string temp = "({[]})" ; 
        for ( int i = 0 ; i < 6 ; i++ ) { 
            mmp[temp[i]] = i + 1  ; 
        }
        for ( int i = 0 ; i < s.length() ; i ++ ) {
            if ( mmp[s[i]] <= 3 ) 
                z.push(mmp[s[i]]) ; 
            else  { 
                int sum = 0 ; 
                while ( z.size() ) { 
                    int tmp = z.top() ; 
                    z.pop() ; 
                    if ( tmp + mmp[s[i]] == 7 ) {
                        if ( sum % 7 ) 
                            return false ; 
                        break ; 
                    } 
                    if ( z.size() == 0 ) 
                        return false ; 
                    sum += tmp ;
                }
            }
        }
        if ( z.size() != 0 )
            return false ; 
        return true ; 
    }
};