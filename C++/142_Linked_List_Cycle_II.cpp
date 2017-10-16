/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 解法一：标记法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode *,bool> visit ; 
        while ( head ) {
            if ( visit[head] == true ) 
                return head ; 
            visit[head] = true ; 
            head = head->next ; 
        } 
        return NULL ; 
    }
};

// 解法二：快慢指针 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fp = head , *sp = head ; 
        while ( true ) {
            if ( fp == NULL || fp->next == NULL || sp == NULL ) 
                return NULL ; 
            fp = fp->next->next ; 
            sp = sp->next ; 
            if ( fp == sp && fp != NULL ) {
                sp = head ; 
                while ( fp != sp ) {
                    fp = fp->next ; 
                    sp = sp->next ; 
                }
                return sp ; 
            }
        }
    }
}; 