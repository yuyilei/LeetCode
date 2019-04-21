/*
设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。

insert(val)：当元素 val 不存在时，向集合中插入该项。
remove(val)：元素 val 存在时，从集合中移除该项。
getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。
示例 :

// 初始化一个空的集合。
RandomizedSet randomSet = new RandomizedSet();

// 向集合中插入 1 。返回 true 表示 1 被成功地插入。
randomSet.insert(1);

// 返回 false ，表示集合中不存在 2 。
randomSet.remove(2);

// 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
randomSet.insert(2);

// getRandom 应随机返回 1 或 2 。
randomSet.getRandom();

// 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
randomSet.remove(1);

// 2 已在集合中，所以返回 false 。
randomSet.insert(2);

// 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
randomSet.getRandom();
*/

// 数组 + 哈希表，数组中存元素，哈希表中存元素对应的位置，移除元素时，将要移除的元素与最后一个元素交换，
// 然后，再把数组的最后一个元素移除. 
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if ( pos.find(val) == pos.end() || pos[val] == -1 ) {
            array.push_back(val);
            pos[val] = array.size()-1;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if ( pos.find(val) == pos.end() || pos[val] == -1 )
            return false;
        // 特殊情况是数组中只有一个元素时，要保障最后 pos[val] = -1 
        int index = pos[val];
        pos[array.back()] = index;
        pos[val] = -1;           // 保障 pos[val] = -1 
        array[index] = array.back();
        array.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if ( array.empty() )
            return 0;
        int index = rand() % array.size();
        return array[index];
    }
private:
    map<int, int> pos;
    vector<int> array;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
