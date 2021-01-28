/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Merge Sort. O(n•logn) time, O(logn) space (recursion stack)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)   return head;
        
        auto slow = head, fast = head, prev = head;
        while(fast and fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        auto next = prev->next;
        prev->next = nullptr;
        
        auto p = sortList(head);
        auto q = sortList(next);
        return merge(p, q);
    }
    
    ListNode *merge(ListNode *p, ListNode *q) {
        ListNode *l = nullptr, **pp = &l;
        
        while(p and q) {
            if(p->val < q->val)
                *pp = p, p = p->next;
            else
                *pp = q, q = q->next;
            
            pp = &((*pp)->next);
        }
        if(p)   *pp = p;
        if(q)   *pp = q;
        return l;
    }
};
