/*
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
进阶:

如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
*/


// 维持大顶堆中的元素全部小于小顶推，且大顶堆中的元素个数等于小顶堆中的元素个数，或者多一个 
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if ( max_heap.empty() ) {
            max_heap.push(num);
            return;
        }
        if ( !min_heap.empty() && num > min_heap.top() ) 
            min_heap.push(num);
        else  
            max_heap.push(num);
        if ( max_heap.size() == min_heap.size() + 2 ) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if ( min_heap.size() == max_heap.size() + 1 ) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if ( max_heap.size() == min_heap.size() ) 
            return (max_heap.top() + min_heap.top())/2.0;
        return max_heap.top()/1.0;
    }
private:
    priority_queue<int> max_heap;     // 默认为大顶堆 
    priority_queue<int, vector<int>, greater<int>> min_heap;   // 小顶推 
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
