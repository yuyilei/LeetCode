/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

给定链表，交换每两个相邻节点并返回其头节点。

例如，对于列表 1-> 2 -> 3 -> 4，我们应当返回新列表 2 -> 1 -> 4 -> 3 的头节点。

我们可以定义函数 swap(head) 以实现解决方案，其中输入的参数 head 指向链表的头节点。而该函数应当返回将链表中每两个相邻节点交换后得到的新列表的头节点 head 。

按照我们上面列出的步骤，我们可以按下面的流程来实现函数：

首先，我们交换列表中的前两个节点，也就是 head 和 head.next；
然后我们以 swap(head.next.next) 的形式调用函数自身，以交换头两个节点之后列表的其余部分。
最后，我们将步骤（2）中的子列表的返回头与步骤（1）中交换的两个节点相连，以形成新的链表。


示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return swapNode(head);
    }
private:
    ListNode* swapNode(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* newhead = head->next;
        ListNode* nextnextNode = head->next->next;
        newhead->next = head;
        head->next = swapNode(nextnextNode);
        return newhead;
    }
};
