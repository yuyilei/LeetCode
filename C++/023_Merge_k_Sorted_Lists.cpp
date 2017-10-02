// 解法一：两个两个合并，时间复杂度是O(kN)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if ( lists.size() == 0 ) 
            return NULL ; 
        while ( lists.size() > 1 ) {
            lists.push_back(merge2list(lists[0],lists[1])) ; 
            lists.erase(lists.begin()) ; 
            lists.erase(lists.begin()) ; 
        }
        return lists[0] ; 
    }
    ListNode* merge2list(ListNode* l1 , ListNode* l2 ) {
        if ( l1 == NULL ) return l2 ; 
        if ( l2 == NULL ) return l1 ; 
        if ( l1->val > l2->val ) {
            l2->next = merge2list(l1,l2->next) ; 
            return l2 ; 
        } 
        else {
            l1->next = merge2list(l1->next,l2) ; 
            return l1 ; 
        }
    }
};

// 分治法，时间复杂度是O(N*log(k))
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if ( lists.size() == 0 ) 
            return NULL ; 
        int len = lists.size() ; 
        while ( len > 1 ) { 
            for ( int i = 0 ; i < len / 2 ; i++ ) 
                lists[i] = merge2list(lists[i],lists[len-1-i]) ; 
            len = (len+1) / 2 ; 
        }
        return lists[0] ; 
    }
    ListNode* merge2list(ListNode* l1 , ListNode* l2 ) {
        if ( l1 == NULL ) return l2 ; 
        if ( l2 == NULL ) return l1 ; 
        if ( l1->val > l2->val ) {
            l2->next = merge2list(l1,l2->next) ; 
            return l2 ; 
        } 
        else {
            l1->next = merge2list(l1->next,l2) ; 
            return l1 ; 
        }
    }
};