/*
设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。

注意: 允许出现重复元素。

insert(val)：向集合中插入元素 val。
remove(val)：当 val 存在时，从集合中移除一个 val。
getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。
示例:

// 初始化一个空的集合。
RandomizedCollection collection = new RandomizedCollection();

// 向集合中插入 1 。返回 true 表示集合不包含 1 。
collection.insert(1);

// 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
collection.insert(1);

// 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
collection.insert(2);

// getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
collection.getRandom();

// 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
collection.remove(1);

// getRandom 应有相同概率返回 1 和 2 。
collection.getRandom();
*/

// 一个vector保存所有元素，map<int, set<int>> 保存每个不重复元素的对应的index
// 删除元素时，将该元素交换到vector的尾部，利用pop_back()，O(1)的删除元素，再修改对应的index
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = true;
        if ( indexs.find(val) != indexs.end() && !indexs[val].empty() )
            res = false;
        nums.push_back(val);
        indexs[val].insert(nums.size()-1);
        return res;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if ( indexs.find(val) == indexs.end() || indexs[val].empty() )
            return false;
        int val_index = *indexs[val].begin();               // 取出任意一个val的index值
        indexs[val].erase(val_index);
        if ( nums.size()-1 == val_index ) {                 // 如果val就在尾部，就不用交换元素，直接删除
            nums.pop_back();
            return true;
        }
        int last = nums.back();                             // 取出尾部元素
        indexs[last].erase(nums.size()-1);                  // 删除尾部元素对应的index
        nums[val_index] = last;                             // 将尾部元素放到val_index
        indexs[last].insert(val_index);                     // 修改尾部元素对应的index
        nums.pop_back();                                    // 删除尾部元素
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        if ( nums.empty() )
            return -1;
        int index = rand() % nums.size();
        return nums[index];
    }
private:
    vector<int> nums;
    map<int, set<int>> indexs;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
