/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
你能尝试使用一趟扫描实现吗？  --> 使用数组存储node 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> list;
        for ( ListNode* now = head; now ; now = now->next ) 
            list.push_back(now); 
        if ( n == list.size() )
            return head->next;
        if ( n == 1 ) 
            list[list.size()-2]->next = NULL;
        else
            list[list.size()-1-n]->next = list[list.size()+1-n];
        return head;
    }
}; 