/*
给定一个嵌套的整型列表。设计一个迭代器，使其能够遍历这个整型列表中的所有整数。

列表中的项或者为一个整数，或者是另一个列表。

示例 1:

输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
示例 2:

输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,4,6]。
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */


// 递归 
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        NestedIterator_(nestedList);
    }

    int next() {
        int result = res.front();
        res.erase(res.begin());
        return result;
    }

    bool hasNext() {
        return !res.empty();
    }
private:
    vector<int> res;
    void NestedIterator_(vector<NestedInteger> &nestedList) {
        for ( int i = 0 ; i < nestedList.size() ; i++ ) {
            if ( nestedList[i].isInteger() ) {
                res.push_back(nestedList[i].getInteger());
            }
            else {
                NestedIterator_(nestedList[i].getList());
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */


//  用栈，非递归 
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        while ( !nestedList.empty() ) {
            if ( nestedList.back().isInteger() ) {
                s.push(nestedList.back().getInteger());
                nestedList.pop_back();
            }
            else {
                vector<NestedInteger> tmpList = nestedList.back().getList();
                nestedList.pop_back();
                for ( int i = 0 ; i < tmpList.size() ; i++ ) 
                    nestedList.push_back(tmpList[i]);
            }
        }
    }

    int next() {
        int res = s.top();
        s.pop();
        return res;
    }

    bool hasNext() {
        return !s.empty();
    }
private:
    stack<int> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
