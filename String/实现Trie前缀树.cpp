/*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true
说明:

你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。
*/

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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
