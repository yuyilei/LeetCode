/*
给定一个文档 (Unix-style) 的完全路径，请进行路径简化。

例如，
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

边界情况:

你是否考虑了 路径 = "/../" 的情况？
在这种情况下，你需返回 "/" 。
此外，路径中也可能包含多个斜杠 '/' ，如 "/home//foo/" 。
在这种情况下，你可忽略多余的斜杠，返回 "/home/foo" 。

*/

// 第一步：将原来字符串用 / 分割成一个个字符串，放入 列表中
// 第二步：遍历列表，遇到不是 . 和 .. 的元素，入栈，遇到 .. 就弹出一个栈顶元素
// 第三步：弹出每个栈中的元素，构成路径 q
class Solution {
public:
    string simplifyPath(string path) {
        if ( path.empty() )
            return "";
        path += "/";
        vector<string> paths;
        string tmp = "";
        for ( int i = 0 ; i < path.size() ; i++ ) {
            if ( path[i] == '/' ) {
                if ( !tmp.empty() ) {
                    paths.push_back(tmp);
                    tmp.clear();
                }
            }
            else {
                tmp += path[i];
            }
        }
        int len = paths.size();
        stack<string> pathstack;
        for ( int i = 0 ; i < len ; i++ ) {
            if ( paths[i] != "." && paths[i] != ".." ) {
                pathstack.push(paths[i]);
            }
            if ( paths[i] == ".." && !pathstack.empty() ) {
                pathstack.pop();
            }
        }
        if ( pathstack.empty() )
            return "/";
        string res = "";
        while ( !pathstack.empty() ) {
            res = "/" + pathstack.top() + res;
            pathstack.pop();
        }
        return res;
    }
};
