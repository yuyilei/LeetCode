/*
实现一个数据结构支持以下操作：

Inc(key) - 插入一个新的值为 1 的 key。或者使一个存在的 key 增加一，保证 key 不为空字符串。
Dec(key) - 如果这个 key 的值是 1，那么把他从数据结构中移除掉。否者使一个存在的 key 值减一。如果这个 key 不存在，这个函数不做任何事情。key 保证不为空字符串。
GetMaxKey() - 返回 key 中值最大的任意一个。如果没有元素存在，返回一个空字符串""。
GetMinKey() - 返回 key 中值最小的任意一个。如果没有元素存在，返回一个空字符串""。
挑战：以 O(1) 的时间复杂度实现所有操作。
*/

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if ( m.find(key) == m.end() ) {
            if ( levels.empty() || levels.front().val != 1 ) {
                struct Level tmp = Level(1);
                tmp.keys.insert(key);
                levels.push_front(tmp);
                m[key] = levels.begin();
            }
            else {
                levels.begin()->keys.insert(key);
                m[key] = levels.begin();
            }
        }
        else {
            auto nowlevel = m[key];
            auto nextlevel = ++m[key];
            int nowval = nowlevel->val;
            if ( nextlevel == levels.end() || nextlevel->val != nowval+1 ) {
                struct Level tmp = Level(nowval+1);
                tmp.keys.insert(key);
                m[key] = levels.insert(nextlevel,tmp);
            }
            else {
                nextlevel->keys.insert(key);
                m[key] = nextlevel;
            }
            nowlevel->keys.erase(key);
            if ( nowlevel->keys.empty() ) {
                levels.erase(nowlevel);
            }
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if ( m.find(key) == m.end() )
            return;
        auto nowlevel = m[key];
        if ( nowlevel->val == 1 ) {
            nowlevel->keys.erase(key);
            m.erase(key);
            if ( nowlevel->keys.empty() ) {
                levels.erase(nowlevel);
            }
        }
        else {
            int lastval = nowlevel->val - 1;
            auto lastlevel = --m[key];
            if ( lastlevel == levels.end() || lastlevel->val != lastval ) {
                struct Level tmp = Level(lastval);
                tmp.keys.insert(key);
                m[key] = levels.insert(nowlevel,tmp);
            }
            else {
                lastlevel->keys.insert(key);
                m[key] = lastlevel;
            }
            nowlevel->keys.erase(key);
            if ( nowlevel->keys.empty() ) {
                levels.erase(nowlevel);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if ( m.empty() )
            return "";
        return *(levels.back().keys.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if ( m.empty() )
            return "";
        return *(levels.front().keys.begin());
    }
private:
    struct Level {
        int val;
        unordered_set<string> keys;
        Level(int x): val(x) {}
    };
    list<struct Level> levels;
    unordered_map<string,list<struct Level>::iterator> m;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
