class Solution {
public : 
    void getres(vector<string> &res , string tmp , int left , int right ){
        if ( left == 0 && right == 0 ) {
            res.push_back(tmp) ; 
            return ; 
        }
        if ( left > 0 )
            getres(res,tmp+"(",left-1,right) ;  // 左括号还有，就可以加左括号
        if ( left < right ) 
            getres(res,tmp+")",left,right-1) ;  // 字符串中左括号多于右括号，要加上右括号和左括号匹配  
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        getres(res, "", n, n);     
        return res;
    }
};  