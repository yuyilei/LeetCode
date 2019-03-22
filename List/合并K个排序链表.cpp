/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// 两两合并链表
// 效率低
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = NULL;
        for ( ListNode *tmp : lists ) {
            res = mergeTwoLists(res,tmp);
        }
        return res;
    }
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ( !a )
            return b;
        if ( !b )
            return a;
        ListNode *res = new ListNode(0);
        ListNode *head = res;
        while ( a && b ) {
            if ( a->val < b ->val ) {
                res->next = a;
                a = a->next;
            }
            else {
                res->next = b;
                b = b->next;
            }
            res = res->next;
        }
        if ( a )
            res->next = a;
        if ( b )
            res->next = b;
        return head->next;
    }
};


// 法二：
// 使用优先队列
struct cmp {   // 默认重载less
    bool operator() (const ListNode* a, const ListNode* b)
    {
        return a->val > b->val;
        // 返回true时，a的优先级低于b的优先级（a排在b的后面） 
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* tmp = new ListNode(0);
        ListNode* res = tmp;
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for ( ListNode* node : lists) {
            if ( node )
                heap.push(node);
        }
        while ( !heap.empty() ) {
            ListNode *now = heap.top();
            heap.pop();
            if ( heap.empty() ) {
                tmp->next = now;
            }
            else {
                tmp->next = now;
                tmp = tmp->next;
                if ( now->next ) {
                    heap.push(now->next);
                }
            }
        }
        return res->next;
    }
};
