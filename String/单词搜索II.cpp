/*
给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例:

输入: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

输出: ["eat","oath"]
说明:
你可以假设所有输入都由小写字母 a-z 组成。

提示:

你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
*/

// 前缀树+回溯
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new tree_node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        tree_node *now = root;
        for ( int i = 0 ; i < word.size() ; i++ ) {
            if ( now->children[word[i]-'a'] == NULL )
                now->children[word[i]-'a'] = new tree_node();
            now = now->children[word[i]-'a'];
        }
        now->isKey = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        tree_node *now = root;
        for ( int i = 0 ; i < word.size() ; i++ ) {
            if ( now->children[word[i]-'a'] == NULL )
                return false;
            now = now->children[word[i]-'a'];
        }
        return now->isKey;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        tree_node *now = root;
        for ( int i = 0 ; i < prefix.size() ; i++ ) {
            if ( now->children[prefix[i]-'a'] == NULL )
                return false;
            now = now->children[prefix[i]-'a'];
        }
        return true;
    }
private:
    struct tree_node {
        bool isKey;
        tree_node *children[26];
        tree_node() {
            isKey = false;
            for ( int i = 0 ; i < 26 ; i++ )
                children[i] = NULL;
        }
    };
    tree_node *root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if ( board.empty() || board[0].empty() )
            return res;
        for ( string word : words )
            trie.insert(word);
        len1 = board.size();
        len2 = board[0].size();
        vector<vector<bool>> visited (len1, vector<bool> (len2, false));
        for ( int i = 0 ; i < len1 ; i++ ) {
            for ( int j = 0 ; j < len2 ; j++ ) {
                string word = "";
                dfs(i, j, word, visited, board);
            }
        }
        return res;
    }
private:
    vector<string> res;
    set<string> res_set;
    Trie trie;
    int len1, len2;
    void dfs(int x, int y, string word, vector<vector<bool>> &visited, vector<vector<char>> &board) {
        if ( x < 0 || x >= len1 || y < 0 || y >= len2 )
            return;
        if ( visited[x][y] )
            return;
        word += board[x][y];
        if ( !trie.startsWith(word) )  // 前缀不符合
            return;
        if ( trie.search(word) ) {
            if ( res_set.find(word) == res_set.end() ) {
                res_set.insert(word);
                res.push_back(word);
            }
        }
        visited[x][y] = true;
        dfs(x+1, y, word, visited, board);
        dfs(x-1, y, word, visited, board);
        dfs(x, y+1, word, visited, board);
        dfs(x, y-1, word, visited, board);
        visited[x][y] = false;
    }
};
