设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。

get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
put(key, value) - 如果键不存在，请设置或插入值。当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。

进阶：
你是否可以在 O(1) 时间复杂度内执行两项操作？

示例：

LFUCache cache = new LFUCache( 2 /* capacity (缓存容量) */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回 1
cache.put(3, 3);    // 去除 key 2
cache.get(2);       // 返回 -1 (未找到key 2)
cache.get(3);       // 返回 3
cache.put(4, 4);    // 去除 key 1
cache.get(1);       // 返回 -1 (未找到 key 1)
cache.get(3);       // 返回 3
cache.get(4);       // 返回 4 


class LFUCache {
public:
    LFUCache(int capacity) {
        cal = capacity;
        mincount = 0;
    }

    int get(int key) {
        // key 不存在
        if ( kvc.find(key) == kvc.end() )
            return -1;
        // key 存在，取出value，修改kvc中的count、kc对应的层数、kl中的iter
        int value = kvc[key].first, old_count = kvc[key].second;
        kvc[key].second++;
        ck[old_count].erase(kl[key]);
        ck[old_count+1].push_back(key);
        kl[key] = --ck[old_count+1].end();
        // 更新最小count
        if ( ck[mincount].empty() )
            mincount++;
        return value;
    }

    void put(int key, int value) {
        if ( cal <= 0 ) {
            return;
        }
        // key 已经存在
        else if ( get(key) != -1 ) {
            kvc[key].first = value;
        }
        // key 不存在、需要插入
        else {
            // 容量不够、删除 miscount中前面的key/value、修改 ck、kl、kvc
            if ( kvc.size() + 1 > cal ) {
                int minkey = ck[mincount].front();
                // cout << "remove: " << minkey << " " << kvc[minkey].first << endl;
                ck[mincount].pop_front();
                kvc.erase(minkey);
                kl.erase(minkey);
            }
            // 插入第一层
            kvc[key] = {value,1};
            ck[1].push_back(key);
            kl[key] = --ck[1].end();
            mincount = 1;
        }
    }

private:
    int cal, mincount;
    map<int,pair<int,int>> kvc;
    map<int,list<int>> ck;
    map<int,list<int>::iterator> kl;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
