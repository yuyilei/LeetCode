/*
给出方程式 A / B = k, 其中 A 和 B 均为代表字符串的变量， k 是一个浮点型数字。根据已知方程式求解问题，并返回计算结果。如果结果不存在，则返回 -1.0。

示例 :
给定 a / b = 2.0, b / c = 3.0
问题: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
返回 [6.0, 0.5, -1.0, 1.0, -1.0 ]

输入为: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries(方程式，方程式结果，问题方程式)， 其中 equations.size() == values.size()，即方程式的长度与方程式结果长度相等（程式与结果一一对应），并且结果值均为正数。以上为方程式的描述。 返回vector<double>类型。

基于上述例子，输入如下：

equations(方程式) = [ ["a", "b"], ["b", "c"] ],
values(方程式结果) = [2.0, 3.0],
queries(问题方程式) = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
输入总是有效的。你可以假设除法运算中不会出现除数为0的情况，且不存在任何矛盾的结果。

*/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, int> store;
        int n = 0;
        for (auto e: equations) {
            if (store.find(e[0]) == store.end())
                store[e[0]] = n++;
            if (store.find(e[1]) == store.end())
                store[e[1]] = n++;
        }
        vector<vector<double>> graph (n, vector<double> (n, 0));
        vector<vector<bool>> vis (n, vector<bool> (n, false));
        for (int i = 0; i < values.size(); i++) {
            vector<string> e = equations[i];
            double v = values[i];
            int a = store[e[0]];
            int b = store[e[1]];
            graph[a][b] = v;
            graph[b][a] = 1/v;
            vis[a][b] = true;
            vis[b][a] = true;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; !vis[i][j] && k < n; k++) {
                    if (vis[i][k] && vis[k][j]) {
                        graph[i][j] = graph[i][k]*graph[k][j];
                        vis[i][j] = true;
                        graph[j][i] = 1/graph[i][j];
                        vis[j][i] = true;
                    }
                }
            }
        }
        int len = queries.size();
        vector<double> res (len, 0);
        for (int i = 0; i < len; i++) {
            string a = queries[i][0];
            string b = queries[i][1];
            if (store.find(a) == store.end() || store.find(b) == store.end()) {
                res[i] = -1;
            }
            else {
                int idxa = store[a];
                int idxb = store[b];
                if (vis[idxa][idxb])
                    res[i] = graph[idxa][idxb];
                else
                    res[i] = -1;
            }
        }
        return res;
    }
};
