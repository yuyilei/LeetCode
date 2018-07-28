/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
利用栈。。。
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *res = NULL, *pre = NULL;
        while ( head ){
            stack <ListNode *> s;
            ListNode *tmphead = head;
            for ( int i = 0 ; i < k ; i++ ){
                if ( !head ) 
                    break;
                s.push(head);
                head = head->next;
            }
            if ( s.size() != k ){
                if ( pre )
                    pre->next = tmphead;
                else
                    res = tmphead;
            }
            else{
                if ( !pre ){
                    pre = s.top();
                    res = pre;
                    s.pop();
                }
                while ( !s.empty() ){
                    pre->next = s.top();
                    pre = pre->next;
                    pre->next = NULL;                           // 要把这里切断，不然有可能形成"环". 
                    s.pop();
                }
            }
        }
        return res;
    }
};