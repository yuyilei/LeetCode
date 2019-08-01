/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

我们可以将 f(5, 3)f(5,3) 分解为 f(5, 3) = f(4, 2) + f(4, 3)f(5,3)=f(4,2)+f(4,3)，然后递归地调用 f(4, 2)f(4,2) 和 f(4, 3)f(4,3)：

对于调用的 f(4, 2)f(4,2)，我们可以进一步展开它，直到到达基本情况，正如下面所描述的：
f(4, 2) = f(3, 1) + f(3, 2) = f(3, 1) + (f(2, 1) + f(2, 2)) = 1 + (1 + 1) = 3
f(4,2)=f(3,1)+f(3,2)=f(3,1)+(f(2,1)+f(2,2))=1+(1+1)=3

对于调用的 f(4, 3)f(4,3)，类似地，我们可以将其分解为：
f(4, 3) = f(3, 2) + f(3, 3) = (f(2, 1) + f(2, 2)) + f(3, 3) = (1 + 1) + 1 = 3
f(4,3)=f(3,2)+f(3,3)=(f(2,1)+f(2,2))+f(3,3)=(1+1)+1=3

最后，我们结合上述子问题的结果：
f(5, 3) = f(4, 2) + f(4, 3) = 3 + 3 = 6
f(5,3)=f(4,2)+f(4,3)=3+3=6


*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0)
            return res;
        res.resize(numRows);
        for (int i = 0; i < numRows; i++) {
            res[i].resize(i+1, 0);
        }
        res[0][0] = 1;
        for (int i = 0; i < numRows; i++) {
            f(numRows-1, i);
        }
        return res;
    }
private:
    vector<vector<int>> res;
    void f(int x, int y) {
        if (x < 0 || y < 0)
            return;
        if (res[x][y] != 0)
            return;
        if (y==0 || x==y) {
            res[x][y] = 1;
        }
        else {
            f(x-1, y-1);
            f(x-1, y);
            res[x][y] = res[x-1][y-1] + res[x-1][y];
        }
    }
};
