/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", 0, 0, n);
        return res;
    }
private:
	// 任何时刻，应该满足左括号的数量大于等于右括号
    void generate(vector<string> &res, string cur, int left, int right, int n) {
        if (left > n || right > n || right > left)
            return;
        if (left == n && right == n) {
            res.push_back(cur);
        }
        else {
            generate(res, cur+"(", left+1, right, n);
            generate(res, cur+")", left, right+1, n);
        }
    }
};
