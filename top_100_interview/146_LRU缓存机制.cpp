/*
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

LRUCache cache = new LRUCache( 2  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4

*/

class LRUCache {
struct ListNode {
    int val, key;
    ListNode* next;
    ListNode* pre;
    ListNode(int k, int v): key(k), val(v) { next = NULL; pre = NULL;}
};
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new ListNode(0,0);
        tail = head->next;
    }

    int get(int key) {
        if (dict.find(key) == dict.end() || dict[key] == NULL)
            return -1;
        ListNode* cur = dict[key];
        if (cur == tail)
            return cur->val;
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        tail->next = cur;
        cur->pre = tail;
        cur->next = NULL;
        tail = cur;
        dict[key] = cur;
        return cur->val;
    }

    void put(int key, int value) {
        if (dict.find(key) != dict.end() && dict[key] != NULL) {
            dict[key]->val = value;
            get(key);
            return;
        }
        size++;
        ListNode* cur = new ListNode(key, value);
        if (size == 1) {
            head->next = cur;
            cur->pre = head;
            tail = cur;
        }
        else {
            tail->next = cur;
            cur->pre = tail;
            tail = cur;
        }
        dict[key] = cur;
        if (size > cap) {
            ListNode* del = head->next;
            head->next = del->next;
            del->next->pre = head;
            dict[del->key] = NULL;
            size--;
        }
    }
private:
    ListNode *head, *tail;
    map<int, ListNode*> dict;
    int cap;
    int size = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
