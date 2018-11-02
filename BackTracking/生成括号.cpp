/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

//  从左边起，取到任意的某个位置得到的串，左括号数量一定是大于或等于右括号的数量， 只有在这种情况下，这组输出才是有效的
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n,n,"",res);
        return res;
    }
private:
    void dfs(int left, int right, string now, vector<string>& res) {
        if ( left > right )
            return;
        if ( left == 0 && right == 0 ) {
            res.push_back(now);
            return;
        }
        if ( left > 0 ) {
            string tmp = now + "(";
            dfs(left-1,right,tmp,res);
        }
        if ( right > 0 ) {
            string tmp = now + ")";
            dfs(left,right-1,tmp,res);
        }
    }
};
